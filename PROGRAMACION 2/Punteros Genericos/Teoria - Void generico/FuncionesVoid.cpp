/* 
 * File:   FuncionesVoid.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de abril de 2024, 10:20
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "FuncionesVoid.h"
#define INCREMENTO 5

void LeerTweets(void *&Tweets,const char * namefile){
    ifstream arch (namefile);
    void **Arr_Tweets = nullptr;
    void * Registro;
    int nTweets =0, CapTweets=0;
    while(true){
        Registro = LeerRegistro(arch);
        if(arch.eof()) break;
        if(nTweets == CapTweets) incrementarEspacios(Arr_Tweets,nTweets,CapTweets);
        Arr_Tweets[nTweets-1] = Registro;
        nTweets++;
    }
    Tweets = Arr_Tweets;
}
void * LeerRegistro(ifstream &arch){
    void **Registro;
    int fecha, *PtrFecha;
    char *Txt_Tweet;
    
    arch>>fecha;
    if(arch.eof()) return nullptr;
    arch.get();
    Txt_Tweet = LeerCadena(arch,'\n');

    PtrFecha = new int ;
    *PtrFecha = fecha;
    Registro = new void *[4]{};
    Registro[0] = PtrFecha;
    Registro[1] = Txt_Tweet;
    return Registro;
}
char * LeerCadena(ifstream &arch,char c){
    char cadena[120],*ptrCadena;
    arch.getline(cadena,120,c);
    ptrCadena = new char [strlen(cadena)+1]{};
    strcpy(ptrCadena,cadena);
    return ptrCadena;
}
void incrementarEspacios(void **&Arr_Tweets,int &nTweets,int &CapTweets){
    CapTweets+= INCREMENTO;
    if(Arr_Tweets == nullptr){
        Arr_Tweets = new void *[CapTweets]{};
        nTweets = 1;
    } else {
        void ** AuxTweets = new void *[CapTweets]{};
        for(int i=0;i<nTweets;i++){
            AuxTweets[i]= Arr_Tweets[i];
        }
        delete Arr_Tweets;
        Arr_Tweets = AuxTweets;
    }
}
void MostrarTweets(void *t,const char * namefile){
    ofstream arch (namefile);
    void **Tweets = (void**)t;
    for(int i=0;Tweets[i];i++){
        ImprimirTweet(arch,Tweets[i]);
    }
}
void ImprimirTweet(ofstream &arch,void *Tweet){
    void **DatosTweet = (void **)Tweet;
    int *Fecha = (int*)DatosTweet[0];
    char *Txt_Tweet = (char*)DatosTweet[1];
    arch<<left<<setw(90)<<Txt_Tweet<<setw(10)<<*Fecha<<endl;
    if(DatosTweet[2]){
        ImprimirHashtags(arch,DatosTweet[2]);
    }
}
void ImprimirHashtags(ofstream &arch,void *Hashtags){
    void **DatosHashtags = (void**)Hashtags;
    for(int i=0; DatosHashtags[i];i++){
        ImprimirUnHashtag(arch,DatosHashtags[i]);
    }
}
void ImprimirUnHashtag(ofstream &arch,void *Hashtag){
    void **DatosHashtag = (void**)Hashtag;
    char* TxT_Hashtag = (char*) DatosHashtag[0];
    int *NSeguidores = (int*) DatosHashtag[1];
    arch<<setw(10)<<" "<<setw(40)<<TxT_Hashtag<<setw(10)<<*NSeguidores<<endl;
}
void LeerHashtags(void *&Tweets,const char * namefile){
    ifstream arch (namefile);
    void **ArrTweets = (void**) Tweets;
    int Fecha, posFecha, Ndatos[50]{},Cap[50]{};
    while(true){
        arch>>Fecha;
        if(arch.eof()) break;
        arch.get();
        posFecha = BuscarFecha(ArrTweets,Fecha);
        if(posFecha != -1 ){
            AgregarHastags(ArrTweets[posFecha],arch,Ndatos[posFecha],Cap[posFecha]);
        } else{
            while(arch.get() != '\n');
        }
    }
}
int BuscarFecha(void **ArrTweets,int Fecha){
    for(int i=0;ArrTweets[i];i++){
        if(IgualarFecha(ArrTweets[i],Fecha)) return i;
    }
    return -1;
}
bool IgualarFecha (void *Tweet,int fecha){
    void **DatosTweet = (void **)Tweet;
    int *FechaCreacion = (int *) DatosTweet[0];
    return *FechaCreacion == fecha;
}
void AgregarHastags(void *Tweet,ifstream &arch,int &Ndatos,int &Cap){
    void **DatosTweet = (void **)Tweet;
    void *Hashtags;
    Hashtags = LeerHastags(arch);
    if(Ndatos == Cap) incrementarEspacios(DatosTweet[2],Ndatos,Cap);
    InsertarHashtags(DatosTweet[2],Hashtags,Ndatos);
    Ndatos++;
}
void * LeerHastags(ifstream &arch){
    void **RegHashtag = new void*[2]{};
    char* hashtag;
    int *ptrSeguidores = new int;
    hashtag = LeerCadena(arch,',');
    arch>>*ptrSeguidores;
    arch.get();
    RegHashtag[0] = hashtag;
    RegHashtag[1] = ptrSeguidores;
    return RegHashtag;
}
void InsertarHashtags(void *tweet_Hashtag,void *hastags,int ndatos){
    void **DatosHashtags = (void**) tweet_Hashtag;
    DatosHashtags[ndatos-1] = hastags;
}
void incrementarEspacios(void *&tweet_Hashta,int &Ndatos,int &Cap){
    void **Hashtag = (void **) tweet_Hashta;
    Cap+= INCREMENTO;
    if(Hashtag == nullptr){
        Hashtag = new void *[Cap]{};
        Ndatos = 1;
    } else {
        void ** AuxHashtags = new void *[Cap]{};
        for(int i=0;i<Ndatos;i++){
            AuxHashtags[i]= Hashtag[i];
        }
        delete Hashtag;
        Hashtag = AuxHashtags;
    }
    tweet_Hashta = Hashtag;
}
/* 
 * File:   FuncionesVoid.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de abril de 2024, 10:20
 */

#ifndef FUNCIONESVOID_H
#define FUNCIONESVOID_H

void LeerTweets(void *&Tweets,const char * namefile);
void * LeerRegistro(ifstream &arch);
void incrementarEspacios(void **&Arr_Tweets,int &nTweets,int &CapTweets);
char * LeerCadena(ifstream &arch,char c);

void MostrarTweets(void *Tweets,const char * namefile);
void ImprimirTweet(ofstream &arch,void *Tweet);
void ImprimirHashtags(ofstream &arch,void *Hashtags);
void ImprimirUnHashtag(ofstream &arch,void *Hashtag);

void LeerHashtags(void *&Tweets,const char * namefile);
int BuscarFecha(void **ArrTweets,int Fecha);
bool IgualarFecha (void *Tweet,int fecha);
void AgregarHastags(void *Tweet,ifstream &arch,int &Ndatos,int &Cap);
void incrementarEspacios(void *&tweet_Hashta,int &Ndatos,int &Cap);
void * LeerHastags(ifstream &arch);
void InsertarHashtags(void *tweet_Hashtaf,void *hastags,int ndatos);
#endif /* FUNCIONESVOID_H */


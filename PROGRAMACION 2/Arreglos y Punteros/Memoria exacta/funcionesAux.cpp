/* 
 * File:   funcionesAux.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 10 de abril de 2024, 08:59
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "funcionesAux.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// PARA 1 ARCHIVOS///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LeerAlumnos_Cursos(int *&codigo, char **&nombres,char*** &cursos,const char* namefile){
    int Buff_Cod[50]{},numDatos=0,cod;
    char *Buff_Nom[50]{}, **Buff_Cursos[50]{};
    ifstream arch (namefile,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    //Leeo y guardo en el buffer
    while(true){
        arch>>cod;
        if(arch.eof())break;
        arch.get();
        Buff_Cod[numDatos]=cod;
        Buff_Nom[numDatos]=LeerCadena(arch);
        Buff_Cursos[numDatos]=LeerCursos(arch);
        numDatos++;
    }
    //Darles espacio de memoria
    codigo = new int [numDatos+1]{};
    nombres = new char* [numDatos+1]{};
    cursos = new char** [numDatos+1]{};
    //rellenar ese espacio
    for(int i=0;i<numDatos;i++){
        codigo[i]=Buff_Cod[i];
        nombres[i]=Buff_Nom[i];
        cursos[i] = Buff_Cursos[i];
    }
}
char* LeerCadena(ifstream &arch){
    char Cadena[60],*cad; // esto ultimo es lo q voy a retornar
    arch.getline(Cadena,60,',');
    cad =new char [strlen(Cadena)+1];
    strcpy(cad,Cadena);
    return cad;
}
char** LeerCursos (ifstream &arch){
    char *BuffCurso[40]{},**Cursos;
    int cantC=0;
    while(true){
        BuffCurso[cantC] =LeerCadenaCurso(arch);
        cantC++;
        if(arch.get()=='\n') break;
    }
    Cursos = new char *[cantC+1]{};
    for(int i=0;i<cantC;i++){
        Cursos[i] = BuffCurso[i];
    }
    return Cursos;
}
char* LeerCadenaCurso(ifstream &arch){
    char *cad; // esto ultimo es lo q voy a retornar
    cad =new char [7];
    arch.get(cad,7);
    return cad;
}
void MostrarAlumnos_Cursos(int *codigo, char **nombres,char*** cursos,const char* namefile){
    ofstream arch (namefile);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    arch<<"REPORTE DE ALUMNOS CURSOS"<<endl;
    for(int i=0; codigo[i];i++){
        arch<<left<<setw(10)<<codigo[i]<<nombres[i]<<endl;
        if(cursos[i]){
            MostrarCursos(cursos[i],arch);
        }
        else{
            arch<<"NO TIENE CURSOS"<<endl;
        }
        arch<<endl;
    }
}
void MostrarCursos(char** cursos,ofstream &arch){
    for(int i=0;cursos[i];i++){
            arch<<right<<setw(15)<<cursos[i]<<endl;
        }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// PARA 2 ARCHIVOS ///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LeerDatosAlumnos(int *&codigos2,char **&nombres2,const char* namefile){
    ifstream arch (namefile,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    int BufCod[50]{}, CantD=0,cod;
    char *BuffNom[50]{};
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        BufCod[CantD]=cod;
        BuffNom[CantD] = LeerNombre(arch);
        CantD++;
    }
    codigos2 = new int [CantD+1]{};
    nombres2 = new char *[CantD+1]{};
    for(int i=0;i<CantD;i++){
        codigos2[i] = BufCod[i];
        nombres2[i] = BuffNom[i];
    }
}
char * LeerNombre(ifstream &arch){
    char cad[60], *ptrCad;
    arch.getline(cad,60);
    ptrCad = new char [strlen(cad)+1];
    strcpy(ptrCad,cad);
    return ptrCad;
}

void LeerDatosCursos(int*codigos2,char ***&Cursos2,const char* namefile){
    ifstream arch (namefile,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    int numDatos=0, nd[50]{}, cod, pos;
    char Aux[60];
    
    //Inicializar curso
    while(codigos2[numDatos]) numDatos++;
    Cursos2 = new char **[numDatos+1]{};
    for(int i=0;i<numDatos;i++) Cursos2[i] = new char*[50]{};
    
    //Colocamos los curos
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        pos = BuscarAlumno(cod,codigos2);
        if (pos != 1){
            ColocarCurso(arch,Cursos2[pos],nd[pos]);
        }
        else{
            arch.getline(Aux,60);
        }
    }
    //Pasamos los cursos a los arreglos exactos
    for(int i=0; Cursos2[i];i++){
        espaciosExactos(Cursos2[i],nd[i]);
    }
}
int BuscarAlumno(int cod,int *codigos2){
    for(int i=0;codigos2[i];i++){
        if(cod == codigos2[i]) return i;
    }
    return -1;
}
void ColocarCurso(ifstream &arch,char **Cursos2,int &nd){
    char *cod;
    cod=LeerNombre(arch);
    Cursos2[nd] = cod;
    nd++;
}
void espaciosExactos(char **&Cursos2,int nd){
    char** espaciofinal;
    if(nd!=0){
        espaciofinal = new char *[nd+1]{};
        for(int i=0; i<nd; i++){
            espaciofinal[i] = Cursos2[i];
        }
        delete Cursos2;
        Cursos2 = espaciofinal;
    }
    else{
        delete Cursos2;
        Cursos2 = nullptr;
    }
}
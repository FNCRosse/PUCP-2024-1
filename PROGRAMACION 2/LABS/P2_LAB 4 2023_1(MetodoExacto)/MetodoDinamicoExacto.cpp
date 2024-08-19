/* 
 * File:   MetodoDinamicoExacto.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 11 de abril de 2024, 20:25
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "MetodoDinamicoExacto.h"

void LecturaAlumnos(const char * namefile,int *&alumno_Codigo,char **&alumno_nombre,
        char *&alumno_Modalidad,int *&alumno_porcentaje,int *&alumno_escala){
    ifstream arch (namefile,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    int numD =0,cod;
    int buffCod[80]{}, buffPor[80]{}, buffEsc[80]{};
    char *BuffNomb[80]{}, buffMod[80]{};
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        buffCod[numD] =cod;
        BuffNomb[numD] = LeerCadena(arch);
        LeerMod_Por_Esc(arch,buffMod[numD],buffPor[numD],buffEsc[numD]);
        numD++;
    }
    alumno_Codigo = new int [numD+1]{};
    alumno_nombre = new char *[numD+1]{};
    alumno_Modalidad = new char [numD+1]{};
    alumno_porcentaje = new int [numD+1]{};
    alumno_escala = new int [numD+1]{};
    for(int i=0;i<numD;i++){
        alumno_Codigo[i] = buffCod[i];
        alumno_nombre[i] = BuffNomb[i];
        alumno_Modalidad[i] = buffMod[i];
        alumno_porcentaje[i] = buffPor[i];
        alumno_escala[i] = buffEsc[i];
    }
}
void PruebaLecturaAlumnos(const char * namefile,int *alumno_Codigo,char **alumno_nombre,
        char *alumno_Modalidad,int *alumno_porcentaje,int *alumno_escala){
    ofstream arch (namefile,ios::out);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    
    for(int i=0;alumno_Codigo[i];i++){
        arch<<left<<setw(10)<<alumno_Codigo[i]<<setw(50)<<alumno_nombre[i]<<setw(5)<<alumno_Modalidad[i]
                <<setw(5)<<alumno_porcentaje[i]<<setw(5)<<alumno_escala[i]<<endl;
    }
}
    
void LecturaCursos(const char * namefile,int *alumno_Codigo,int *alumno_escala,char **&curso_Nombre,
        double *&curso_credito,int **&curso_Alumnos){
    ifstream arch (namefile,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    int numD =0,cod,posAlumno,posCurso;
    int *buffCurAlu[110]{}, numCurA[110]{};
    char *BuffNomb[110]{}, *nombre;
    double BuffCred[110]{};
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        nombre = LeerCadena(arch);
        arch>>BuffCred[numD];
        arch.get();
        posAlumno = BuscarAlumno(alumno_Codigo,cod);
        posCurso = BuscarCurso(BuffNomb,nombre);
        if (posCurso != -1){
            buffCurAlu[posCurso] = ColocarAlumno(buffCurAlu[posCurso],numCurA[posCurso],cod,posAlumno,alumno_escala);
        }
        else{
            buffCurAlu[numD] = ColocarAlumno(buffCurAlu[numD],numCurA[numD],cod,posAlumno,alumno_escala);
        }
        BuffNomb[numD] = nombre;
        numD++;
    }
    curso_Nombre = new char *[numD+1]{};
    curso_credito = new double [numD+1]{};
    curso_Alumnos = new int *[numD+1]{};
    for(int i=0;i<numD;i++){
        curso_Nombre[i] = BuffNomb[i];
        curso_credito[i] = BuffCred[i];
        curso_Alumnos[i] = buffCurAlu[i];
    }
}
void PruebaLecturaCursos(const char * namefile,char **curso_Nombre,
        double *curso_credito,int **curso_Alumnos){
    ofstream arch (namefile,ios::out);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    for(int i=0; curso_Nombre[i];i++){
        arch<<left<<setw(50)<<curso_Nombre[i]<<curso_credito[i]<<endl;
        ImprimirAlumnos(curso_Alumnos[i],arch);
        arch<<endl;
    }
}
 void ImprimirAlumnos(int *curso_Alumnos,ofstream &arch){
     for(int i=0; curso_Alumnos[i];i++){
         arch<<right<<setw(10)<<curso_Alumnos[i]<<" ";
     }
 }
void ReporteDeRecaudacionPorModalidad(const char * namefile,int  *alumno_Codigo,char *alumno_Modalidad,
            int *alumno_porcentaje,char **alumno_nombre,char **curso_Nombre,double *curso_credito
            ,int **curso_Alumnos){
    ofstream arch (namefile,ios::out);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
}

char * LeerCadena(ifstream &arch){
    char cadena[60],*cad;
    arch.getline(cadena,60,',');
    cad = new char [strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
}
void LeerMod_Por_Esc(ifstream &arch,char &buffMod,int &buffPor,int &buffEsc){
    char modalidad,extra;
    arch>>modalidad;
    if(modalidad == 'V'){
        buffMod = 'V';
        arch>>extra>>buffEsc;
    }
    else if ( modalidad == 'S'){
        buffMod = 'S';
        arch>>extra>>buffPor>>extra>>buffEsc;
    }
    else{
        buffMod = 'P';
        buffEsc = modalidad - '0';
    }
}
int BuscarAlumno(int *alumno_Codigo,int cod){
    for(int i=0; alumno_Codigo[0];i++){
        if(alumno_Codigo[i] == cod) return i;
    }
    return -1;
}
int BuscarCurso(char **BuffNomb,char *nombre){
    for(int i=0; BuffNomb[i];i++){
        if(strcmp(BuffNomb[i],nombre)==0) return i;
    }
    return -1;
}
int* ColocarAlumno(int *&buffCurAlu,int &numCurA,int cod,int posAlumno,int *alumno_escala){
    int *Aux,buff[300]{};
    if(numCurA == 0 ){
        buff[0] = cod;
        buff[1] = alumno_escala[posAlumno];
        numCurA +=2;
    }
    else{
        for(int i=0;i<numCurA;i++){
            buff[i] = buffCurAlu[i];
            buff[i+1] = buffCurAlu[i+1];
            i++;
        }
        delete buffCurAlu;
        buff[numCurA] = cod;
        buff[numCurA+1] = alumno_escala[posAlumno];
        numCurA +=2;
    }
    Aux = new int [numCurA+1]{};
    for(int i=0;i<numCurA;i++){
        Aux[i] = buff[i];
    }
    return Aux;
}
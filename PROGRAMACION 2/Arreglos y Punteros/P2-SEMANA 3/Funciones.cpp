/* 
 * File:   Funciones.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 5 de abril de 2024, 16:00
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Funciones.h"

char* leerCadena(ifstream& arch, const char delimitador){
    char buffer[200];
    arch.getline(buffer,200,delimitador);
    //Usar la tecnica de asignacion exacta
    char* cadena = new char [strlen(buffer)+1];
    strcpy(cadena,buffer);
    return cadena;
}
char** separarCursos(char *bufferCursos){
    char* buf_codCuros[15];
    int n=0;
    char* ptrCadena = strtok(bufferCursos,",");
    while( ptrCadena != nullptr){
        buf_codCuros[n] = ptrCadena;
        ptrCadena = strtok(nullptr,",");
        n++;
    }
    char** cod_curso = new char* [n+1];
    for(int i=0;i<n;i++){
        cod_curso[i] = buf_codCuros[i];
    }
    cod_curso[n] =nullptr;
    return cod_curso;
}
void LeerDatos(const char* namefile,char**  Codigos,char** &Nombres,char*** &Cursos){
    ifstream arch(namefile);
    if (!arch.is_open()) exit(0);
    char* buf_Cod[50];
    char* buf_Nombres[50];
    char* buf_Cursos[50];//Leemos todos luego los separamos
    //Luego de leer los buffers crear la memoria dinamica
    int n=0;
    while (true) {
        buf_Cod[n] = leerCadena(arch,',');
        if(arch.eof()) break;
        buf_Nombres[n] = leerCadena(arch,',');
        buf_Cursos[n] = leerCadena(arch,'\n');
        n++;
    }
    //hacer un delimitador con el nullptr ya que son punteros
    Codigos = new char* [n+1];
    Nombres = new char* [n+1];
    Cursos = new char** [n+1];
    for(int i=0;i<n;i++){
        Codigos[i] =buf_Cod[i];
        Nombres[i] =buf_Nombres[i];
        //Todo: split a buf_cursos[i]
        Cursos[i] = separarCursos(buf_Cursos[i]);
        
    }
    Codigos[n] = nullptr;
    Nombres[n] = nullptr;
    Cursos[n] = nullptr;
    arch.close();
}
void MostrarDatos(char** Codigos,char** Nombres,char*** Cursos){
    for( int i=0; Codigos[i] != nullptr; i++){
        cout<<Codigos[i]<<" - "<<Nombres[i]<<endl;
        for(int j=0; Cursos[i][j] != nullptr; j++){
            cout<<Cursos[i]<<"  ";
        }
        cout<<endl;
    }
}
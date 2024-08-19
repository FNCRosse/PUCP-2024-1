/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   LibroEducativo.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 21:06
 */
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
#include "LibroEducativo.h"

LibroEducativo::LibroEducativo(){
    Materia= nullptr;
}
void LibroEducativo::Leer(ifstream &arch){
    Libro::LeerDatos(arch);
    char buff[50];
    arch.getline(buff,50,'\n');
    SetMateria(buff);
}
void LibroEducativo::Imprimir(ofstream &arch){
    Libro::Imprimir(arch);
    arch<<Materia<<endl;
}
void LibroEducativo::SetMateria(const char* cad) {
    if( Materia != nullptr) delete Materia;
    Materia = new char [strlen(cad)+1];
    strcpy(Materia,cad);
}

void  LibroEducativo::GetMateria(char *cad) const {
    if(Materia == nullptr) cad[0] =0;
    else strcpy(cad,Materia);
}
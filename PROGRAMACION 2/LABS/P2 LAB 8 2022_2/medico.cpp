/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   medico.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 16:09
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "medico.h"

medico::medico(){
    especialidad=nullptr;
    nombre = nullptr;
    codigo=0;
}

void medico::SetEspecialidad(const char* cad) {
    if(especialidad != nullptr) delete especialidad;
    especialidad = new char[strlen(cad)+1];
    strcpy(especialidad,cad);
}

void medico::GetEspecialidad(char *cad) const {
    if(especialidad == nullptr) cad[0]=0;
    else strcpy(cad,especialidad);
}

void medico::SetNombre(const char* cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void medico::GetNombre(char *cad) const {
    if(nombre == nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

void medico::LeerDatos(ifstream &arch){
    
}
void medico::Imprimir(ofstream &arch){
    
}
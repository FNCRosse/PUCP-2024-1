/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   conReceta.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 16:20
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "conReceta.h"

conReceta::conReceta(){
    codmed =0;
    especialidad=nullptr;
}
void conReceta:: Imprimir(ofstream &arch){
    char descrip[120];
    int cod =GetCodigo();
    GetNombreMed(descrip);
    int cant = GetCantidad();
    arch<<left<<setw(15)<<cod<<setw(50)<<descrip<<setw(10)<<cant<<setw(20)<<codmed<<especialidad<<endl;
}
void conReceta::IngresarDatos(int fecha, int codmed,int codmedicina,int cant,char *especialidad){
    SetFecha(fecha);
    SetCantidad(cant);
    SetCodmed(codmed);
    SetEspecialidad(especialidad);
    medicamento::LeerDatos(codmedicina);
}
void conReceta::SetEspecialidad(const char* cad) {
    if(especialidad != nullptr) delete especialidad;
    especialidad = new char[strlen(cad)+1];
    strcpy(especialidad,cad);
}

void conReceta::GetEspecialidad(char *cad) const {
    if(especialidad == nullptr) cad[0]=0;
    else strcpy(cad,especialidad);
}

void conReceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conReceta::GetCodmed() const {
    return codmed;
}
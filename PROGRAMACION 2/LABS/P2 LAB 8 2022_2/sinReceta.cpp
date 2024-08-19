/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   sinReceta.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 16:23
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "sinReceta.h"
#include "medicamento.h"

sinReceta::sinReceta(){
    nombre=nullptr;
    dni=0;
}
void sinReceta::Imprimir(ofstream &arch){
    char descrip[120];
    int cod =GetCodigo();
    GetNombreMed(descrip);
    int cant = GetCantidad();
    arch<<left<<setw(15)<<cod<<setw(50)<<descrip<<setw(10)<<cant<<setw(20)<<dni<<nombre<<endl;
}
void sinReceta::IngresarDatos(int fecha, int dni,int codmedicina,int cant,char *name){
    SetFecha(fecha);
    SetDni(dni);
    SetCantidad(cant);
    SetNombre(name);
    medicamento::LeerDatos(codmedicina);
}
void sinReceta::SetNombre(const char* cad) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void sinReceta::GetNombre(char *cad) const {
    if(nombre == nullptr) cad[0]=0;
    else strcpy(cad,nombre);
}

void sinReceta::SetDni(int dni) {
    this->dni = dni;
}

int sinReceta::GetDni() const {
    return dni;
}
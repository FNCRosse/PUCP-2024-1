/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PrioridadMedia.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 15:40
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "PrioridadMedia.h"

PrioridadMedia::PrioridadMedia(){
    descripcion=nullptr;
    nueva_fecha_entrega=0;
}

void PrioridadMedia::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadMedia::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadMedia::SetDescripcion(const char* cad) {
    if(descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(cad)+1];
    strcpy(descripcion,cad);
}

void PrioridadMedia::GetDescripcion(char*cad) const {
    if(descripcion == nullptr) cad[0]=0;
    else strcpy(cad,descripcion);
}
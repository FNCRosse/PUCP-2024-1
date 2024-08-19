/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NPedidos.cpp
 * Author: Rosse
 * 
 * Created on 13 de junio de 2024, 20:24
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "NPedidos.h"

NPedidos::NPedidos(){
    sig = nullptr;
}
void NPedidos::ImprimirPed(ofstream &arch){
    
}
void NPedidos::SetPeso(double peso) {
    this->peso = peso;
}

double NPedidos::GetPeso() const {
    return peso;
}

void NPedidos::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedidos::GetCantidad() const {
    return cantidad;
}

void NPedidos::SetCodigo(const char* cad) {
    if(codigo !=  nullptr) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void NPedidos::GetCodigo(char *cad) const {
    if(codigo ==  nullptr) cad[0]=0;
    else strcpy(cad,codigo);
}
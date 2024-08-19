/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NPedido.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 15:32
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "NPedido.h"

NPedido::NPedido(){
    sig = nullptr;
    codigo = nullptr;
    cantidad =0;
    peso =0;
}
NPedido::NPedido(const NPedido &orig){
    cantidad = orig.cantidad;
    SetCodigo(orig.codigo);
    peso = orig.peso;
    sig = nullptr;
}
void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(const char* cad) {
    if(codigo !=  nullptr) delete codigo;
    codigo  =new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void NPedido::GetCodigo(char* cad) const {
    if(codigo ==  nullptr) cad[0]=0 ;
    else strcpy(cad,codigo);
}
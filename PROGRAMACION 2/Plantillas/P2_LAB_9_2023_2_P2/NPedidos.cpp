/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NPedidos.cpp
 * Author: Rosse
 * 
 * Created on 20 de junio de 2024, 14:24
 */
#include "Util.h"
#include "NPedidos.h"

NPedidos::NPedidos() {

}

void NPedidos::lee(ifstream &arch) {
    char buff[50];
    arch.getline(buff,50,',');
    SetCodigo(buff);
    arch>>cantidad;
    arch.get();
    arch>>peso;
    arch.get();
}

void NPedidos::imprime(ofstream &arch) {
    char cod[15];
    GetCodigo(cod);
    arch<<setw(15)<<cod<<setw(6)<<cantidad<<peso<<endl;
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
    if (Codigo != nullptr) delete Codigo;
    Codigo = new char[strlen(cad) + 1];
    strcpy(Codigo, cad);
}

void NPedidos::GetCodigo(char *cad) const {
    if (Codigo == nullptr) cad[0] = 0;
    else strcpy(cad, Codigo);
}
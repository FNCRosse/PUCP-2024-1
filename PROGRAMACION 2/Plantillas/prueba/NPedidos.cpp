/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NPedidos.cpp
 * Author: Rosse
 * 
 * Created on 21 de junio de 2024, 04:52
 */
#include "Util.h"
#include "NPedidos.h"

NPedidos::NPedidos() {
    codigo = nullptr;
    cantidad=0;
    peso=0;
}
NPedidos::~NPedidos() {
    if(codigo != nullptr) delete codigo;
}

void NPedidos::lee(ifstream &arch) {
    char buff[10]{};
    arch.getline(buff, 10, ',');
    SetCodigo(buff);
    arch>>cantidad;
    arch.get();
    arch>>peso;
    arch.get();
}

void NPedidos::imprime(ofstream &arch) {
    arch << left << setw(16) << codigo << setw(6) << cantidad << peso << endl;
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

void NPedidos::SetCodigo(char* cad) {
    this->codigo = new char[strlen(cad)+1];
    strcpy(this->codigo,cad);
}

char* NPedidos::GetCodigo() const {
    return codigo;
}
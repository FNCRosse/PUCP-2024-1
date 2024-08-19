/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 15:28
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido(){
    codigo=nullptr;
    dni_cliente=0;
    subtotal=0;
    fecha=0;
    Estado=nullptr;
    total=0;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetEstado(const char* cad) {
    if(Estado != nullptr) delete Estado;
    Estado = new char[strlen(cad)+1];
    strcpy(Estado,cad);
}

void Pedido::GetEstado(char* cad) const {
    if(Estado == nullptr) cad[0]=0;
    else strcpy(cad,Estado);
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Pedido::GetSubtotal() const {
    return subtotal;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(const char* cad) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cad)+1];
    strcpy(codigo,cad);
}

void Pedido::GetCodigo(char* cad) const {
    if(codigo == nullptr) cad[0]=0;
    else strcpy(cad,codigo);
}

void Pedido::LeerDato(ifstream &arch){
    
}
void Pedido::Imprimir(ofstream &arch){
    
}
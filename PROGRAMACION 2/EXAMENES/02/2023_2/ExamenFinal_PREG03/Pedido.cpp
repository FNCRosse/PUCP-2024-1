/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 11:44
 */

#include "Pedido.h"

Pedido::Pedido() {

}

void Pedido::SetPeso(double peso) {
    this->peso = peso;
}

double Pedido::GetPeso() const {
    return peso;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::LeerPedido(ifstream &arch) {
    getline(arch,codigo,',');
    arch>>cantidad;
    arch.get();
    arch>>peso;
    arch.get();
}

void Pedido::ImprimirPedido(ofstream &arch) {
    arch<<setw(12)<<codigo<<setw(8)<<peso<<cantidad<<endl;
}
bool Pedido::operator < (const class Pedido &other)const{
    return GetPeso() < other.GetPeso();
}
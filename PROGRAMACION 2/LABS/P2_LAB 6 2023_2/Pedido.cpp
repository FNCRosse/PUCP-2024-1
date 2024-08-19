/* 
 * File:   Pedido.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:29
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Pedido.h"

Pedido::Pedido(){
    Codigo=nullptr;
    Dni_Cliente=0;
    PrecioProd=0;
}
bool Pedido::Leer(ifstream &arch){
    char Buff[100];
    arch.getline(Buff,100,',');
    SetCodigo(Buff);
    if(arch.eof()) return false;
    arch>>Dni_Cliente;
    arch.get();
    return true;
}
bool operator >>(ifstream &arch, Pedido &P){
    if(P.Leer(arch)) return true;
    else return false;
}
void Pedido::SetPrecioProd(double PrecioProd) {
    this->PrecioProd = PrecioProd;
}

double Pedido::GetPrecioProd() const {
    return PrecioProd;
}

void Pedido::SetDni_Cliente(int Dni_Cliente) {
    this->Dni_Cliente = Dni_Cliente;
}

int Pedido::GetDni_Cliente() const {
    return Dni_Cliente;
}

void Pedido::SetCodigo(char* cad) {
    if(Codigo != nullptr) delete Codigo;
    Codigo = new char[strlen(cad)+1];
    strcpy(Codigo,cad);
}

char* Pedido::GetCodigo() const {
    char *Cad;
    Cad = new char[strlen(Codigo)+1];
    strcpy(Cad,Codigo);
    return Cad;
}


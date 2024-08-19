/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Fugon.cpp
 * Author: Rosse
 * 
 * Created on 20 de junio de 2024, 14:54
 */
#include "Util.h"
#include "Fugon.h"
Fugon::Fugon(){
    
}
void Fugon::leer(ifstream &arch) {
    Vehiculo::leer(arch);
    arch>>Filas;
    arch.get();
    arch>>Puertas;
    arch.get();
}

void Fugon::imprime(ofstream &arch) {
    Vehiculo::imprime(arch);
    arch<<left<<setw(20)<<"#Filas:"<<Filas<<endl;
    arch<<left<<setw(20)<<"#Puertas:"<<Puertas<<endl;
    arch<<"Lista de Pedidos:"<<endl;
//    for(auto x: mdeposito)
//        arch<<x.second;
//    arch<<endl<<endl;
    
}
void Fugon::SetPuertas(int Puertas) {
    this->Puertas = Puertas;
}

int Fugon::GetPuertas() const {
    return Puertas;
}

void Fugon::SetFilas(int Filas) {
    this->Filas = Filas;
}

int Fugon::GetFilas() const {
    return Filas;
}
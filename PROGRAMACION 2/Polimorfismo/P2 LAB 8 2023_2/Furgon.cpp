/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 15:43
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Furgon.h"
Furgon::Furgon(){
    
}
void Furgon::lee(ifstream &arch) {
    Vehiculo::lee(arch);
    arch>>filas;
    arch.get();
    arch>>puertas;
}

void Furgon::imprime(ofstream &arch) {
    Vehiculo::imprime(arch);
    arch<<left<<setw(20)<<"#Filas: "<<right<<setw(12)<<GetFilas()<<endl;
    arch<<left<<setw(20)<<"#Puertas: "<<right<<setw(12)<<GetPuertas()<<endl;
    arch<<"Pedidos:"<<endl;
    if (Vehiculo::PilaVacia()) {
        arch << "No hay pedidos para el cliente" << endl<<endl;
    } else {
        Vehiculo::ImprimirPila(arch);
        arch<<endl;
    }
}
void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}
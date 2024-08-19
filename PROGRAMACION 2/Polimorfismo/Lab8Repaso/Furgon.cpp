/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: Rosse
 * 
 * Created on 13 de junio de 2024, 20:39
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Furgon.h"
#include "Vehiculo.h"

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
    arch << left << setw(20) << "#Filas: " << right << setw(12) << filas << endl;
    arch << left << setw(20) << "#Puertas: " << right << setw(12) << puertas << endl;
    arch<<"Pedidos:"<<endl;
}
void Furgon::setPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::getPuertas() const {
    return puertas;
}

void Furgon::setFilas(int filas) {
    this->filas = filas;
}

int Furgon::getFilas() const {
    return filas;
}
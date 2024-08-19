/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Rosse
 * 
 * Created on 13 de junio de 2024, 20:35
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Camion.h"

Camion::Camion() {
    
}

void Camion::lee(ifstream &arch) {
    Vehiculo::lee(arch);
    arch>>ejes;
    arch.get();
    arch>>llantas;
}

void Camion::imprime(ofstream &arch) {
    Vehiculo::imprime(arch);
    arch << left << setw(20) << "#Eje: " << right << setw(12) << ejes << endl;
    arch << left << setw(20) << "#Llantas: " << right << setw(12) << llantas << endl;
    arch<<"Pedidos:"<<endl;
}

void Camion::setLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::getLlantas() const {
    return llantas;
}

void Camion::setEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::getEjes() const {
    return ejes;
}
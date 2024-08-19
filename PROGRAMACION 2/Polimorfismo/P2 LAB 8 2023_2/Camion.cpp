/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 15:41
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Vehiculo.h"
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
    arch << left << setw(20) << "#Eje: " << right << setw(12) << GetEjes() << endl;
    arch << left << setw(20) << "#Llantas: " << right << setw(12) << GetLlantas() << endl;
    arch << "Pedidos:" << endl;
    if (Vehiculo::PilaVacia()) {
        arch << "No hay pedidos para el cliente" << endl;
    } else {
        Vehiculo::ImprimirPila(arch);
        arch<<endl;
    }
}

void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}
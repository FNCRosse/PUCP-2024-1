/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Rosse
 * 
 * Created on 13 de junio de 2024, 20:30
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    ped = nullptr;
    actcarga = 0;
    maxcarga = 0;
    placa = nullptr;
    cliente = 0;
}

void Vehiculo::lee(ifstream &arch) {
    char Buff[50];
    arch>>cliente;
    arch.get();
    arch.getline(Buff,50,',');
    setPlaca(Buff);
    arch>>maxcarga;
    arch.get();
}

void Vehiculo::imprime(ofstream &arch) {
    char placa[10];
    getPlaca(placa);
    arch << left << setw(20) << "Codigo Cliente: " << right << setw(12) << getCliente() << endl;
    arch << left << setw(20) << "Placa:" << right << setw(12) << placa << endl;
    arch << left << setw(20) << "Carga Maxima: " << right << setw(12) << maxcarga << endl;
    arch << left << setw(20) << "Carga Actual: " << right << setw(12) << getActcarga() << endl;
}

void Vehiculo::setActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::getActcarga() const {
    return actcarga;
}

void Vehiculo::setMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::getMaxcarga() const {
    return maxcarga;
}

void Vehiculo::setPlaca(const char* cad) {
    if (placa != nullptr) delete placa;
    placa = new char[strlen(cad) + 1];
    strcpy(placa, cad);
}

void Vehiculo::getPlaca(char* cad) const {
    if (placa == nullptr) cad[0] = 0;
    else strcpy(cad, placa);
}

void Vehiculo::setCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::getCliente() const {
    return cliente;
}
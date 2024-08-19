/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Rosse
 * 
 * Created on 21 de junio de 2024, 04:58
 */
#include "Util.h"
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    ActCarga = 0;
}

Vehiculo::~Vehiculo() {
    if(placa) delete[]placa;
}

void Vehiculo::lee(ifstream &arch) {
    char buff[20];
    arch>>cliente;
    arch.get();
    arch.getline(buff, 20, ',');
    SetPlaca(buff);
    arch>>maxCarga;
    arch.get();
}

void Vehiculo::imprime(ofstream &arch) {
    char pla[15];
    GetPlaca(pla);
    arch << left << setw(22) << "Codigo Cliente:" << cliente << endl;
    arch << left << setw(22) << "Placa:" << pla << endl;
    arch << left << setw(22) << "Carga Maxima:" << maxCarga << endl;
    arch << left << setw(22) << "Carga Actual:" << ActCarga << endl;
}

void Vehiculo::SetActCarga(double ActCarga) {
    this->ActCarga = ActCarga;
}

double Vehiculo::GetActCarga() const {
    return ActCarga;
}

void Vehiculo::SetMaxCarga(double maxCarga) {
    this->maxCarga = maxCarga;
}

double Vehiculo::GetMaxCarga() const {
    return maxCarga;
}

void Vehiculo::SetPlaca(const char* cad) {
    if (placa != nullptr) delete placa;
    placa = new char[strlen(cad) + 1];
    strcpy(placa, cad);
}

void Vehiculo::GetPlaca(char *cad) const {
    if (placa == nullptr) cad[0] = 0;
    else strcpy(cad, placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}
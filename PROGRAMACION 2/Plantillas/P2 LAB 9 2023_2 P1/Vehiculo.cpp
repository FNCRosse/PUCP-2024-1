/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Rosse
 * 
 * Created on 20 de junio de 2024, 14:35
 */
#include "Util.h"
#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    maxcarga = 0;
    actcarga = 0;
}

void Vehiculo::leer(ifstream &arch) {
   char buff[50];
   arch>>cliente;
   arch.get();
    arch.getline(buff,50,',');
    SetPlaca(buff);
    arch>>maxcarga;
    arch.get();
}

void Vehiculo::imprime(ofstream &arch) {
    char plac[15];
    GetPlaca(plac);
    arch<<left<<setw(20)<<"Codigo Cliente:"<<cliente<<endl;
    arch<<left<<setw(20)<<"Placa:"<<plac<<endl;
    arch<<left<<setw(20)<<"Carga Maxima:"<<maxcarga<<endl;
    arch<<left<<setw(20)<<"Carga Actual:"<<actcarga<<endl;
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
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
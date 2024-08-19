/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 11:48
 */

#include "Vehiculo.h"

Vehiculo::Vehiculo() {
    carga_actual =0;
}

void Vehiculo::leer(ifstream &arch) {
    //F,79464412,K0D-676,300,1,3
    arch>>dni;
    arch.get();
    getline(arch,placa,',');
    arch>>carga_maxima;
    arch.get();
}

void Vehiculo::mostrar(ofstream &arch) {
    arch<<setw(20)<<"Codigo  de Cliente:"<<dni<<endl;
    arch<<setw(20)<<"Placa:"<<placa<<endl;
    arch<<setw(20)<<"Carga Maxima:"<<carga_maxima<<endl;
    arch<<setw(20)<<"Carga Actual:"<<carga_actual<<endl;
}

void Vehiculo::insertar(Pedido &ped) {
    
}

void Vehiculo::SetCarga_actual(double carga_actual) {
    this->carga_actual = carga_actual;
}

double Vehiculo::GetCarga_actual() const {
    return carga_actual;
}

void Vehiculo::SetCarga_maxima(double carga_maxima) {
    this->carga_maxima = carga_maxima;
}

double Vehiculo::GetCarga_maxima() const {
    return carga_maxima;
}

void Vehiculo::SetPlaca(string placa) {
    this->placa = placa;
}

string Vehiculo::GetPlaca() const {
    return placa;
}

void Vehiculo::SetDni(int dni) {
    this->dni = dni;
}

int Vehiculo::GetDni() const {
    return dni;
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Vehiculo.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 15:36
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Vehiculo.h"
#include "NPedido.h"

Vehiculo::Vehiculo() {
    ped = nullptr;
    actcarga = 0;
    maxcarga = 0;
    placa = nullptr;
    cliente = 0;
}

void Vehiculo::lee(ifstream &arch) {
    char buff[50];
    arch>>cliente;
    arch.get();
    arch.getline(buff, 50, ',');
    SetPlaca(buff);
    arch>>maxcarga;
    arch.get();
}

void Vehiculo::imprime(ofstream &arch) {
    char placa[10];
    GetPlaca(placa);
    arch << left << setw(20) << "Codigo Cliente: " << right << setw(12) << GetCliente() << endl;
    arch << left << setw(20) << "Placa:" << right << setw(12) << placa << endl;
    arch << left << setw(20) << "Carga Maxima: " << right << setw(12) << GetMaxcarga() << endl;
    arch << left << setw(20) << "Carga Actual: " << right << setw(12) << GetActcarga() << endl;
}
void Vehiculo::Push(NPedido &nodoPed){
    NPedido *nuevoNodo = new NPedido(nodoPed);
    nuevoNodo->sig = ped;
    ped = nuevoNodo;
}
bool Vehiculo::PilaVacia() {
    if (ped == nullptr) return true;
    else return false;
}

void Vehiculo::ImprimirPila(ofstream &arch) {
    char cod[10];
    while(ped){
        ped->GetCodigo(cod);
        arch<<right<<setw(12)<<cod<<setw(5)<<ped->GetCantidad()<<setw(8)<<ped->GetPeso()<<endl;
        ped = ped->sig;
    }
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
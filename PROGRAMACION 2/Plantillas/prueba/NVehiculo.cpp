/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NVehiculo.cpp
 * Author: Rosse
 * 
 * Created on 21 de junio de 2024, 05:19
 */

#include "NVehiculo.h"
#include "Furgon.h"
#include "Camion.h"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}
NVehiculo::~NVehiculo() {
    
}

void NVehiculo::lee(ifstream &arch,char tipo) {
    switch(tipo){
        case 'F':
            unidad =  new Furgon;
            break;
        case 'C':
            unidad = new Camion;
            break;
    }
    unidad->lee(arch);
}

void NVehiculo::imprime(ofstream &arch) {
    unidad->imprime(arch);
}
void NVehiculo::InsertarPedido(class NPedidos &ped){
    unidad->cargadeposito(ped);
}
bool NVehiculo::operator<(const class NVehiculo &V)const {
    return unidad->GetCliente() < V.GetUnidad()->GetCliente();
}

bool NVehiculo::operator==(int cliente) {
    return unidad->GetCliente() == cliente;
}

void NVehiculo::SetUnidad(Vehiculo* unidad) {
    this->unidad = unidad;
}

Vehiculo* NVehiculo::GetUnidad() const {
    return unidad;
}
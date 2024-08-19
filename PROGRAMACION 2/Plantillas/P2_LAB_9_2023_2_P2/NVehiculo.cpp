/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NVehiculo.cpp
 * Author: Rosse
 * 
 * Created on 20 de junio de 2024, 14:57
 */
#include "Util.h"
#include "NVehiculo.h"
#include "Fugon.h"
#include "Camion.h"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

void NVehiculo::leer(ifstream &arch,char tipo) {
    switch(tipo){
        case 'F':
            unidad = new class Fugon;
            break;
        case 'C':
            unidad =  new class Camion;
            break;
    }
    unidad->leer(arch);
}

void NVehiculo::imprime(ofstream &arch) {
    unidad->imprime(arch);
}
bool NVehiculo::operator < (const class NVehiculo &V) const { 
    cout<< unidad->GetCliente() <<" "<<V.unidad->GetCliente()<<endl;
   return unidad->GetCliente()<V.unidad->GetCliente();
}
bool NVehiculo::operator == (int _cliente){
    return unidad->GetCliente() == _cliente;
}
void NVehiculo::InsertarPedido(NPedidos &ped){
    unidad->CargaDeposito(ped);
}


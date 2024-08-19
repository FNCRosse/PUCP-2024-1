/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 11:52
 */

#include "Camion.h"

Camion::Camion() {
    depositos = vector<class Pedido>();
}

void Camion::leer(ifstream &arch) {
    Vehiculo::leer(arch);
    arch>>llantas;
    arch.get();
    arch>>ejes;
    arch.get();
}

void Camion::mostrar(ofstream &arch) {
    Vehiculo::mostrar(arch);
    arch<<setw(20)<<"#Llantas:"<<llantas<<endl;
    arch<<setw(20)<<"#Ejes"<<ejes<<endl;
    arch<<"Lista de Pedidos:"<<endl;
    if(depositos.empty()){
        arch<<"No hay pedidos"<<endl<<endl;
    }else{
        for(class Pedido & ped:depositos){
            ped.ImprimirPedido(arch);
        }
    }
}

void Camion::insertar(Pedido &ped) {
    if(ped.GetPeso() + GetCarga_actual() <= GetCarga_maxima() and depositos.size() <= 5){
        depositos.push_back(ped);
        SetCarga_actual(ped.GetPeso() + GetCarga_actual());
    }
}

void Camion::SetDepositos(vector<Pedido> depositos) {
    this->depositos = depositos;
}

vector<Pedido> Camion::GetDepositos() const {
    return depositos;
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
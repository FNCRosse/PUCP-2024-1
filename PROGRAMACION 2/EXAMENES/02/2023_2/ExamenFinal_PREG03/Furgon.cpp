/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 11:55
 */

#include "Furgon.h"

Furgon::Furgon() {
    depositos = list<class Pedido>();
}

void Furgon::leer(ifstream &arch) {
    Vehiculo::leer(arch);
    arch>>puertas;
    arch.get();
    arch>>filas;
    arch.get();
}

void Furgon::mostrar(ofstream &arch) {
    Vehiculo::mostrar(arch);
    arch<<setw(20)<<"#Puertas:"<<puertas<<endl;
    arch<<setw(20)<<"#Filas"<<filas<<endl;
    arch<<"Lista de Pedidos:"<<endl;
    if(depositos.empty()){
        arch<<"No hay pedidos"<<endl<<endl;
    }else{
        for(class Pedido & ped:depositos){
            ped.ImprimirPedido(arch);
        }
    }
}

void Furgon::insertar(Pedido &ped) {
    if(ped.GetPeso() + GetCarga_actual() <= GetCarga_maxima()){
        auto pos = lower_bound(depositos.begin(),depositos.end(),ped);
        depositos.insert(pos,ped);
        SetCarga_actual(ped.GetPeso() + GetCarga_actual());
    }
}

void Furgon::setDepositos(list<Pedido> depositos) {
    this->depositos = depositos;
}

list<Pedido> Furgon::getDepositos() const {
    return depositos;
}

void Furgon::setPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::getPuertas() const {
    return puertas;
}

void Furgon::setFilas(int filas) {
    this->filas = filas;
}

int Furgon::getFilas() const {
    return filas;
}
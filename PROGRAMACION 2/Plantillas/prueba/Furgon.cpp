/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Furgon.cpp
 * Author: Rosse
 * 
 * Created on 21 de junio de 2024, 05:16
 */

#include "Furgon.h"
Furgon::Furgon(){
    
}
void Furgon::lee(ifstream &arch) {
    Vehiculo::lee(arch);
    arch>>filas;
    arch. get();
    arch>>puertas;
    arch.get();
}

void Furgon::imprime(ofstream &arch) {
    Vehiculo::imprime(arch);
    arch << left << setw(22) << "#Filas:" << filas << endl;
    arch << left << setw(22) << "#Puertas:" << puertas << endl;
    arch << "Lista de pedidos: " << endl;
    if (pdeposito.empty()) {
        arch << "No hay pedidos" << endl << endl;
    }else{
        int i=0;
        for(NPedidos x:pdeposito){
            arch<<right<<setw(4)<<i+1<<left<<setw(4)<<" ";
            x.imprime(arch);
            i++;
        }
    }
}
void Furgon::cargadeposito(NPedidos &pedido){
    if(pedido.GetPeso() + GetActCarga() <= GetMaxCarga()){
        pdeposito.push_front(pedido);
        double act = GetActCarga();
        act+=pedido.GetPeso();
        SetActCarga(act);
    }
}
void Furgon::SetPuertas(int puertas) {
    this->puertas = puertas;
}

int Furgon::GetPuertas() const {
    return puertas;
}

void Furgon::SetFilas(int filas) {
    this->filas = filas;
}

int Furgon::GetFilas() const {
    return filas;
}
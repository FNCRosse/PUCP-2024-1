/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Rosse
 * 
 * Created on 20 de junio de 2024, 15:00
 */
#include "Util.h"
#include "Flota.h"
#include "NPedidos.h"

void Flota::CargaFlota() {
    ifstream arch("Vehiculos.csv");
    class NVehiculo dato;
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        dato.leer(arch,tipo);
        vFlota.push_back(dato);
    }
    sort(vFlota.begin(),vFlota.end());
}
void Flota::CargaPedidos(){
    ifstream arch("Pedidos3.csv");
    int Cliente;
    NPedidos ped;
    while(true){
        arch>>Cliente;
        if(arch.eof()) break;
        arch.get();
        ped.lee(arch);
        auto aux = find(vFlota.begin(),vFlota.end(),Cliente);
        if(aux != vFlota.end())
            aux->InsertarPedido(ped);
    }
    
}
void Flota::MuestraCarga() {
    ofstream arch ("Reporte.txt");
    for(NVehiculo x:vFlota){
        x.imprime(arch);
    }
}
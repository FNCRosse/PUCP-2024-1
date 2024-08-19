/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Rosse
 * 
 * Created on 21 de junio de 2024, 05:26
 */
#include "Util.h"
#include "Flota.h"
#include "NPedidos.h"

Flota::Flota() {

}

void Flota::CargaFlota() {
    ifstream arch("Vehiculos.csv");
    char tipo;
    NVehiculo dato;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        dato.lee(arch,tipo);
        vflota.push_back(dato);
    }
    sort(vflota.begin(),vflota.end());
}
void Flota::CargaPedidos(){
    ifstream arch("Pedidos3.csv");
    int cliente;
    NPedidos dato;
    while(true){
        arch>>cliente;
        if(arch.eof()) break;
        arch.get();
        dato.lee(arch);
        
        auto aux = find(vflota.begin(),vflota.end(),cliente);
        if(aux !=  vflota.end()){
            aux->InsertarPedido(dato);
        }
    }
}
void Flota::MuestraCarga() {
    ofstream arch("Reporte.txt");
    for(NVehiculo x: vflota){
        x.imprime(arch);
    }
}
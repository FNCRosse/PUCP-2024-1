/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 11:59
 */

#include "Flota.h"
#include "Furgon.h"
#include "Camion.h"

void Flota::Cargar_Vehiculo() {
    ifstream arch ("Vehiculos.csv");
    char tipo;
    class Vehiculo *dato;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        switch(tipo){
            case 'F':
                dato = new Furgon();
                break;
            case 'C':
                dato = new Camion();
                break;
        }
        dato->leer(arch);
        vehiculos[dato->GetPlaca()] = dato;
    }
}

void Flota::Mostrar_Vehiculo() {
    ofstream arch ("Reporte.txt");
    arch<<left<<"Reporte de Flota"<<endl;
    for(auto const & vehiculo: vehiculos){
        ImprimirLinea(100,'=',arch);
        vehiculo.second->mostrar(arch);
        ImprimirLinea(100,'=',arch);
    }
}
void Flota::ImprimirLinea(int n, char c, ofstream &arch){
    for(int i=0;i<n;i++) arch<<c;
    arch<<endl;
}

void Flota::SetVehiculos(map<string, Vehiculo*> vehiculos) {
    this->vehiculos = vehiculos;
}

map<string, Vehiculo*> Flota::GetVehiculos() const {
    return vehiculos;
}
void Flota::Cargar_Pedido() {
    ifstream arch ("Pedidos4.csv");
    string placa;
    class Pedido dato;
    while(true){
        getline(arch,placa,',');
        if(arch.eof()) break;
        arch.get();
        auto it = vehiculos.find(placa) ;
        if(it != vehiculos.end()){
            dato.LeerPedido(arch);
            it->second->insertar(dato);
        } else while(arch.get() != '\n');
    }
}
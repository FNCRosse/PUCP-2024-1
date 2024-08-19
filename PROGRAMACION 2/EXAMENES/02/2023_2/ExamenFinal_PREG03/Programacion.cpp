/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Programacion.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 12:58
 */

#include "Programacion.h"

void Programacion::cargaVehiculos() {
    fVehiculos.Cargar_Vehiculo();
    fVehiculos.Cargar_Pedido();
}

void Programacion::CargaProgramacion() {
    map<string, Vehiculo*> mapa = fVehiculos.GetVehiculos();
    for(auto const & vehiculo: mapa){
        ADespachos.Insertar(vehiculo.second);
    }
}

void Programacion::ReduceVehiculos(int cantidad) {
    ADespachos.EliminarNodos(cantidad);
}

void Programacion::MuestraProgramacion() {
    ofstream arch ("ReporteArbol.txt");
    arch<<left;
    ADespachos.Imprimir(arch);
}
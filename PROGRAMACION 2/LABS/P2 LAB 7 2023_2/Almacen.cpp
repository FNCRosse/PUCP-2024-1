/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 15:47
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Almacen.h"

Almacen::Almacen(){
    cantidad_ordenes=0;
}

void Almacen::SetCantidad_ordenes(int cantidad_ordenes) {
    this->cantidad_ordenes = cantidad_ordenes;
}

int Almacen::GetCantidad_ordenes() const {
    return cantidad_ordenes;
}
void Almacen::CargarPedidos(){
    ifstream arch("Pedidos.csv");
    char tipo;
    while(true){
        arch<<tipo;
        if(arch.eof()) break;
        arch.get();
        ordenes[cantidad_ordenes].LeerDatos(arch,tipo);
        cantidad_ordenes++;
    }
}
void Almacen::Actualizar_Pedidos(){
    
}
void Almacen::ImprimirOrdenesVenta(){
    
}
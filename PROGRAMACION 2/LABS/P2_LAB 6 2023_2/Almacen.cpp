/* 
 * File:   Almacen.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:32
 */
#include <iostream>
using namespace std;
#include "Almacen.h"

Almacen::Almacen(){
    CantClientes=0;
    cantProductos=0;
}

void Almacen::SetCantProductos(int cantProductos) {
    this->cantProductos = cantProductos;
}

int Almacen::GetCantProductos() const {
    return cantProductos;
}

void Almacen::SetCantClientes(int CantClientes) {
    this->CantClientes = CantClientes;
}

int Almacen::GetCantClientes() const {
    return CantClientes;
}



/* 
 * File:   ProductoEntregado.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:13
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "ProductoEntregado.h"

ProductoEntregado::ProductoEntregado(){
    Codigo = nullptr;
    Precio = 0;
}

void ProductoEntregado::SetPrecio(double Precio) {
    this->Precio = Precio;
}

double ProductoEntregado::GetPrecio() const {
    return Precio;
}

void ProductoEntregado::SetCodigo(char* cad) {
    if(Codigo != nullptr) delete Codigo;
    Codigo = new char[strlen(cad)+1];
    strcpy(Codigo,cad);
}

char* ProductoEntregado::GetCodigo() const {
    char *Cad;
    Cad = new char[strlen(Codigo)+1];
    strcpy(Cad,Codigo);
    return Cad;
}


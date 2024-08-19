/* 
 * File:   Escala.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:53
 */
#include <iostream>
using namespace std;
#include "Escala.h"

Escala::Escala(){
    precio =0;
    codigo =0;
}

void Escala::SetPrecio(double precio) {
    this->precio = precio;
}

double Escala::GetPrecio() const {
    return precio;
}

void Escala::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Escala::GetCodigo() const {
    return codigo;
}


/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Escala.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 21:14
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Escala.h"
Escala::Escala(){
    codigo = 0;
    precio =0;
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
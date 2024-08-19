/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Escala.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 12:27
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "Escala.h"
Escala::Escala(){
    
}
Escala::~Escala(){
    
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
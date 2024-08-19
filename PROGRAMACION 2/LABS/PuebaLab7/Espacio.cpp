/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Espacio.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 20:50
 */
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
#include "Espacio.h"

Espacio::Espacio(){
    contenido = ' ';
    posx =0;
    posy=0;
}
void Espacio::Imprimir(ofstream &arch){
    arch<<"["<<contenido<<"]";
}
void Espacio::SetPosy(int posy) {
    this->posy = posy;
}

int Espacio::GetPosy() const {
    return posy;
}

void Espacio::SetPosx(int posx) {
    this->posx = posx;
}

int Espacio::GetPosx() const {
    return posx;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}
/* 
 * File:   Espacio.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 10:03
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "Espacio.h"

Espacio::Espacio(){
    contenido= ' ';
    PosX=0;
    PosY=0;
}

void Espacio::SetPosY(int PosY) {
    this->PosY = PosY;
}

int Espacio::GetPosY() const {
    return PosY;
}

void Espacio::SetPosX(int PosX) {
    this->PosX = PosX;
}

int Espacio::GetPosX() const {
    return PosX;
}

void Espacio::SetContenido(char contenido) {
    this->contenido = contenido;
}

char Espacio::GetContenido() const {
    return contenido;
}
void Espacio::Imprimir (ofstream &arch){
    arch<<"["<<contenido<<"] ";
}
void operator << (ofstream &arch,Espacio Es){
    Es.Imprimir(arch);
}

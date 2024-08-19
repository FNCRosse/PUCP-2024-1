
/* 
 * File:   Ficha.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 08:49
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Ficha.h"

Ficha::Ficha(){
    ID = nullptr;
}
Ficha::~Ficha(){
    if(ID !=  nullptr) delete ID;
}

void Ficha::SetCol(int col) {
    this->col = col;
}

int Ficha::GetCol() const {
    return col;
}

void Ficha::SetFila(int fila) {
    this->fila = fila;
}

int Ficha::GetFila() const {
    return fila;
}

void Ficha::SetID(const char* cad) {
    if (ID != nullptr) delete ID;
    ID = new char [strlen(cad)+1];
    strcpy(ID,cad);
}

void Ficha::GetID(char* cad) const {
    if(ID ==  nullptr) cad[0]=0;
    else strcpy(cad,ID);
}
void Ficha::Asignar(char * identidad, int f, int c){
    SetID(identidad);
    SetFila(f);
    SetCol(c);
}
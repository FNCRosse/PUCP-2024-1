/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 20:43
 */

#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Libro.h"

Libro::Libro(){
    codigo=nullptr;
    nombre = nullptr;
    alto=0;
    ancho=0;
    colocado = false;
}
void Libro::LeerDatos(ifstream &arch){
    char buff[100],c;
    arch.getline(buff,100,',');
    SetCodigo(buff);
    arch.getline(buff,100,',');
    SetNombre(buff);
    arch>>ancho>>c>>alto>>c;
}
void Libro::Imprimir(ofstream &arch){
    arch<<left<<setw(10)<<codigo<<setw(30)<<nombre<<setw(10)<<ancho<<setw(10)<<alto;
}
void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char* cad) {
    if( nombre != nullptr) delete nombre;
    nombre = new char [strlen(cad)+1];
    strcpy(nombre,cad);
}

void Libro::GetNombre(char *cad) const {
    if(nombre == nullptr) cad[0] =0;
    else strcpy(cad,nombre);
}

void Libro::SetCodigo(const char* cad) {
    if( codigo != nullptr) delete codigo;
    codigo = new char [strlen(cad)+1];
    strcpy(codigo,cad);
}

void Libro::GetCodigo(char *cad) const {
    if(codigo == nullptr) cad[0] =0;
    else strcpy(cad,codigo);
}

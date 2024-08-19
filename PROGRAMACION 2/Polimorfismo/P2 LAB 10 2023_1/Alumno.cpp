/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 21:09
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Alumno.h"

Alumno::Alumno() {
    codigo =0 ;
    nombre = nullptr;
    total =0;
}

void Alumno::leer(ifstream &arch) {
    char buff[100],c;
    arch>>codigo>>c;
    arch.getline(buff,100,',');
    arch>>escala>>c>>creditos>>c;
    SetNombre(buff);
}

void Alumno::imprime(ofstream &arch) {
    char nomb[100];
    GetNombre(nomb);
    arch<<left<<setw(15)<<GetCodigo()<<setw(50)<<nomb<<setw(5)<<GetEscala()<<setw(8)<<GetCreditos();
}
void Alumno::Actualiza(double precio){
    total = creditos*precio;
}
void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

void Alumno::GetNombre(char* cad) const {
    if (nombre == nullptr) cad[0] = 0;
    else strcpy(cad, nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

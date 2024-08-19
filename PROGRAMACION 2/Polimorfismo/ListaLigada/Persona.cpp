/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Persona.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 09:43
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Persona.h"

Persona::Persona() {
    dni = 0;
    Nombre = nullptr;
    sueldo = 0;
}

Persona::~Persona() {
    if (Nombre != nullptr) delete Nombre;
}

bool Persona::operator>(const class Persona &p) {
    return dni > p.dni;
}

void Persona::operator=(const class Persona &p) {
    char nomb[100];
    dni = p.dni;
    p.GetNombre(nomb);
    SetNombre(nomb);
    sueldo = p.sueldo;
}

ifstream &operator>>(ifstream &arch, class Persona &p) {
    int dni;
    char nomb[100];
    double sueldo;
    arch>>dni;
    if (arch.eof()) return arch;
    arch.get();
    arch.getline(nomb, 100, ',');
    arch>>sueldo;
    p.SetDni(dni);
    p.SetNombre(nomb);
    p.SetSueldo(sueldo);
    return arch;
}

ofstream &operator<<(ofstream &arch, class Persona &per) {
    char nombre[100];
    arch.precision(2);
    arch << fixed;
    per.GetNombre(nombre);
    arch << left << setw(10) << per.GetDni() << setw(40) << nombre
            << right << setw(10) << per.GetSueldo() << endl;
    return arch;
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(const char* cad) {
    if (Nombre != nullptr) delete Nombre;
    Nombre = new char[strlen(cad) + 1];
    strcpy(Nombre, cad);
}

void Persona::GetNombre(char* cad) const {
    if (Nombre == nullptr) cad[0] = 0;
    else strcpy(cad, Nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}
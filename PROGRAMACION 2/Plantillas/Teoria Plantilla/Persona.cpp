/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Persona.cpp
 * Author: Rosse
 * 
 * Created on 20 de junio de 2024, 11:04
 */
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Persona.h"

Persona::Persona() {
    nombre = nullptr;
}

Persona::Persona(const Persona& orig) {
    nombre = nullptr;
    *this = orig;
}

Persona::~Persona() {
    if (nombre != nullptr) delete nombre;
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(const char* nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Persona::GetNombre(char*nomb) const {
    if (nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb, nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::operator=(const class Persona&per) {
    char nomb[60];
    dni = per.dni;
    per.GetNombre(nomb);
    SetNombre(nomb);
    sueldo = per.sueldo;
}

void operator >> (istream &in, class Persona&per) {
    int dni;
    char nomb[60];
    double sueldo;
    in>>dni;
    in.get(); //coma
    in.getline(nomb, 60, ',');
    in>>sueldo;
    per.SetDni(dni);
    per.SetNombre(nomb);
    per.SetSueldo(sueldo);
}

ostream& operator<<(ostream &out, const class Persona&per) {
    out.precision(2);
    out << fixed;
    char nomb[60];
    per.GetNombre(nomb);
    out << left << setw(10) << per.GetDni() << setw(30) << nomb
            << right << setw(10) << per.GetSueldo();
    return out;
}
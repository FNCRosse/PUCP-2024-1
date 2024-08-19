/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Virtual.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 21:34
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Virtual.h"

Virtual::Virtual() {
    total = 0;
}

void Virtual::leer(ifstream &arch) {
    char buff[10];
    Alumno::leer(arch);
    arch.getline(buff,10,'\n');
    SetLicencia(buff);
}

void Virtual::imprime(ofstream &arch) {
    char lic[10];
    GetLicencia(lic);
    Alumno::imprime(arch);
    arch << setw(12) <<lic<< right << setw(10) << GetTotal() << endl;
}
void Virtual::Actualiza(double precio){
    Alumno::Actualiza(precio);
    double t = Alumno::GetTotal();
    total = t + 100;
    Alumno::SetTotal(total);
}
void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* cad) {
    if (licencia != nullptr) delete licencia;
    licencia = new char[strlen(cad) + 1];
    strcpy(licencia, cad);
}

void Virtual::GetLicencia(char *cad) const {
    if (licencia == nullptr) cad[0] = 0;
    else strcpy(cad, licencia);
}
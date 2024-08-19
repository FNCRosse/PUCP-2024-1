/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 21:18
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Semipresencial.h"

Semipresencial::Semipresencial(){
    total = 0;
}
void Semipresencial::leer(ifstream &arch) {
    Alumno::leer(arch);
    arch>>descuento;
    arch.get();
}

void Semipresencial::imprime(ofstream &arch) {
    Alumno::imprime(arch);
    arch<<setw(12)<<" "<<right<<setw(10)<<GetTotal()<<endl;
}

void Semipresencial::Actualiza(double precio){
    Alumno::Actualiza(precio);
    double t = Alumno::GetTotal();
    total = t - (t*(descuento/100));
    Alumno::SetTotal(total);
}
void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}
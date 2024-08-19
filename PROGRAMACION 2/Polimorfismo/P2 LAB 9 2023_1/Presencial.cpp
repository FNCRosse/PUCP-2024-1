/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Presencial.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 12:29
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Alumno.h"
#include "Presencial.h"

Presencial::Presencial(){
    total =0;
    recargo =0;
}
void Presencial::leer(ifstream &arch){
    Alumno::leer(arch);
    arch>>recargo;
    arch.get();
}
void Presencial::imprimir(ofstream &arch){
    Alumno::imprimir(arch);
    arch<<setw(10)<<" "<<right<<setw(10)<<GetTotal()<<endl;
}
void Presencial::actualizar(int precio){
    Alumno::actualizar(precio);
    int t = Alumno::GetTotal();
    total = t + (t*(recargo/100));
    Alumno::SetTotal(total);
}
void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}
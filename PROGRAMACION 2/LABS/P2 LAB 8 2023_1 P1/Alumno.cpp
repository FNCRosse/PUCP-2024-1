/* 
 * File:   Alumno.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:48
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Alumno.h"

Alumno::Alumno(){
    total =0;
    escala =0;
    Nombre=nullptr;
    codigo =0;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(const char* cad) {
    if(Nombre != nullptr) delete Nombre;
    Nombre = new char[strlen(cad)+1];
    strcpy(Nombre,cad);
}

void Alumno::GetNombre(char *&cad) const {
    if(Nombre == nullptr) cad[0]=0;
    cad = new char[strlen(cad)+1];
    strcpy(cad,Nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}
void Alumno::LeerDatos(ifstream &arch){
    char buff[100];
    arch>>codigo;
    if(arch.eof()) return;
    arch.get();
    arch.getline(buff,100,',');
    SetNombre(buff);
    arch>>escala;
    arch.get();
}
void Alumno::Imprime(ofstream &arch){
    arch<<left<<setw(20)<<codigo<<setw(50)<<Nombre<<setw(10)<<escala;
}
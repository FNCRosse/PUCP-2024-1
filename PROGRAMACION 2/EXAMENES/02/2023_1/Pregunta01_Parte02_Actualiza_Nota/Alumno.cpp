/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 16:55
 */

#include "Alumno.h"

Alumno::Alumno(){
    promedio = 0.0;
}
bool operator >> (ifstream &arch, class Alumno &al){
    int cod;
    string nombre;
    arch>>cod;
    if(arch.eof()) return true;
    arch.get();
    getline(arch,nombre,'\n');
    al.SetNombre(nombre);
    al.SetCodigo_alumno(cod);
    return false;
}
void Alumno::ImprimeAlumno(ofstream &arch){
    arch<<left<<setw(12)<<codigo_alumno<<setw(40)<<nombre<<promedio<<endl;
}
void Alumno::SetPromedio(double promedio) {
    this->promedio = promedio;
}

double Alumno::GetPromedio() const {
    return promedio;
}

void Alumno::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Alumno::GetNombre() const {
    return nombre;
}

void Alumno::SetCodigo_alumno(int codigo_alumno) {
    this->codigo_alumno = codigo_alumno;
}

int Alumno::GetCodigo_alumno() const {
    return codigo_alumno;
}
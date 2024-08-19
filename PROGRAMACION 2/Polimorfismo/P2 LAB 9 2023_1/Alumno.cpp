/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Alumno.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 12:23
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Alumno.h"
Alumno::Alumno(){
    codigo  =0;
    Nombre = nullptr;
    escala =0;
    creditos =0.0;
    total = 0.0;
}
Alumno::~Alumno(){
    if(Nombre != nullptr )delete Nombre;
}
void Alumno::leer(ifstream &arch){
    char c,buff[100];
    arch>>codigo>>c;
    arch.getline(buff,100,',');
    arch>>escala>>c>>creditos>>c;
    SetNombre(buff);
}
void Alumno::imprimir(ofstream &arch){
    char nombre[100];
    GetNombre(nombre);
    arch<<left<<setw(15)<<GetCodigo()<<setw(60)<<nombre<<setw(10)<<GetEscala()<<setw(10)<<GetCreditos();
}
void Alumno::actualizar(int precio){
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
    if(Nombre !=  nullptr) delete Nombre;
    Nombre  =new char[strlen(cad)+1];
    strcpy(Nombre,cad);
}

void  Alumno::GetNombre(char * cad) const {
     if(Nombre ==  nullptr) cad[0] = 0;
     else strcpy(cad,Nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}
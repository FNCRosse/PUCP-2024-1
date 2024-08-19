/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   medicamento.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 16:15
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "medicamento.h"

medicamento::medicamento(){
    codigo=0;
    nombreMed=nullptr;
    cantidad=0;
    precio=0;
    fecha=0;
}
void medicamento::LeerDatos(int codmediciona){
    ifstream arch("medicamentos.csv");
    int cod;
    char name[120];
    double precio;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        arch.getline(name,120,',');
        arch>>precio;
        arch.get();
        if(cod == codmediciona) break;
    }
    SetCodigo(cod);
    SetNombreMed(name);
    SetPrecio(precio);
}
void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int medicamento::GetCantidad() const {
    return cantidad;
}

void medicamento::SetNombreMed(const char* cad) {
    if(nombreMed != nullptr) delete nombreMed;
    nombreMed = new char[strlen(cad)+1];
    strcpy(nombreMed,cad);
}

void medicamento::GetNombreMed(char *cad) const {
    if(nombreMed == nullptr) cad[0]=0;
    else strcpy(cad,nombreMed);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Libro.cpp
 * Author: Rosse
 * 
 * Created on 9 de julio de 2024, 05:32
 */

#include "Libro.h"

Libro::Libro() {

}

void Libro::Leer(ifstream &arch) {
    getline(arch,nombre,',');
    arch>>pagina;
    arch.get();
    arch>>peso;
    arch.get();
}

void Libro::imprime(ofstream &arch) {
    arch<<"Titulo: "<<nombre<<endl;
    arch<<"Peso: "<<peso<<endl;
}

void Libro::SetPeso(double peso) {
    this->peso = peso;
}

double Libro::GetPeso() const {
    return peso;
}

void Libro::SetPagina(int pagina) {
    this->pagina = pagina;
}

int Libro::GetPagina() const {
    return pagina;
}

void Libro::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Libro::GetNombre() const {
    return nombre;
}
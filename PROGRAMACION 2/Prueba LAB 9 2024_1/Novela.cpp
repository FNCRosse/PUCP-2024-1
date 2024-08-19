/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Novela.cpp
 * Author: Rosse
 * 
 * Created on 9 de julio de 2024, 05:41
 */

#include "Novela.h"

Novela::Novela(){
    
}
void Novela::Leer(ifstream &arch) {
    Libro::Leer(arch);
    getline(arch,autor,'\n');
}

void Novela::imprime(ofstream &arch) {
    Libro::imprime(arch);
    arch<<"Autor: "<<autor<<endl;
}
void Novela::SetAutor(string autor) {
    this->autor = autor;
}

string Novela::GetAutor() const {
    return autor;
}
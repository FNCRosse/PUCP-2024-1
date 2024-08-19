/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Enciclopedia.cpp
 * Author: Rosse
 * 
 * Created on 9 de julio de 2024, 05:37
 */

#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() {

}

void Enciclopedia::Leer(ifstream &arch) {
    Libro::Leer(arch);
    arch>>sku;
    arch.get();
    arch>>anho;
    arch.get();
}

void Enciclopedia::imprime(ofstream &arch) {
    Libro::imprime(arch);
    arch<<"SKU: "<<setw(12)<<sku<<"Anho: "<<anho<<endl;
}

void Enciclopedia::SetAnho(int anho) {
    this->anho = anho;
}

int Enciclopedia::GetAnho() const {
    return anho;
}

void Enciclopedia::SetSku(int sku) {
    this->sku = sku;
}

int Enciclopedia::GetSku() const {
    return sku;
}
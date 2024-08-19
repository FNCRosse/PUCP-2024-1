/* 
 * File:   Libro.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 09:24
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Libro.h"

Libro::Libro(){
    colocado = false;
    alto =0;
    ancho =0;
    Nombre=nullptr;
    Codigo=nullptr;
}

void Libro::SetColocado(bool colocado) {
    this->colocado = colocado;
}

bool Libro::IsColocado() const {
    return colocado;
}

void Libro::SetAlto(int alto) {
    this->alto = alto;
}

int Libro::GetAlto() const {
    return alto;
}

void Libro::SetAncho(int ancho) {
    this->ancho = ancho;
}

int Libro::GetAncho() const {
    return ancho;
}

void Libro::SetNombre(const char* cad) {
    if(Nombre != nullptr) delete Nombre;
    Nombre = new char[strlen(cad)+1];
    strcpy(Nombre,cad);
}

void Libro::GetNombre(char* cad) const {
    if(Nombre == nullptr) cad[0] =0;
    else strcpy(cad,Nombre);
}

void Libro::SetCodigo(const char* cad) {
    if(Codigo != nullptr) delete Codigo;
    Codigo = new char[strlen(cad)+1];
    strcpy(Codigo,cad);
}

void Libro::GetCodigo(char* cad) const {
    if(Codigo == nullptr) cad[0] =0;
    else strcpy(cad,Codigo);
}
void Libro::LeerDatos(ifstream &arch){
    char buff[100],c;
    arch.getline(buff,100,',');
    SetCodigo(buff);
    arch.getline(buff,100,',');
    SetNombre(buff);
    arch>>ancho>>c>>alto;
    arch.get();
}
void Libro::Imprimir (ofstream &arch){
    arch<<left<<setw(10)<<Codigo;
    if(colocado == true){
        arch<<setw(30)<<Nombre<<setw(8)<<ancho<<alto<<endl;
    } else{
        arch<<setw(30)<<"NO SE PUDO COLOCAR"<<setw(8)<<ancho<<alto<<endl;
    }
}
void operator >> (ifstream &arch,Libro &L){
    L.LeerDatos(arch);
}
void operator << (ofstream &arch,Libro L){
    L.Imprimir(arch);
}

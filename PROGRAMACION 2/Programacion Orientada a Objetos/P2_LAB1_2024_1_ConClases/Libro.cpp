/* 
 * File:   Libro.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 15:21
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Libro.h"

Libro::Libro(){
    Codigo = "FIN";
    Titulo = nullptr;
    Autor =nullptr;
    stock = 0;
    Precio = 0.0;
}
void Libro::Leer(ifstream &arch){
    char Buff[100],extra;
    arch.getline(Buff,100,',');
    SetCodigo(Buff);
    arch.getline(Buff,100,',');
    SetTitulo(Buff);
    arch.getline(Buff,100,',');
    SetAutor(Buff);
    arch>>stock>>extra>>Precio;
    arch.get();
}
void operator >>(ifstream &arch,Libro &L){
    L.Leer(arch);
}
void operator <<(ofstream &arch,Libro L){
    arch.precision(2);
    arch<<fixed;
    char *codigo,*Titulo=new char[100]{},*Autor=new char[100]{};
    int Stock;
    double precio;
    codigo =L.GetCodigo();
    L.GetTitulo(Titulo);
    L.GetAutor(Autor);
    Stock = L.GetStock();
    precio = L.GetPrecio();
    arch<<left<<setw(12)<<codigo<<setw(60)<<Titulo<<setw(40)<<Autor<<setw(8)<<Stock<<precio<<endl;
}
void Libro::SetPrecio(double Precio) {
    this->Precio = Precio;
}

double Libro::GetPrecio() const {
    return Precio;
}

void Libro::SetStock(int stock) {
    this->stock = stock;
}

int Libro::GetStock() const {
    return stock;
}

void Libro::SetAutor(const char* cad) {
    if(Autor != nullptr) delete Autor;
    Autor = new char[strlen(cad)+1];
    strcpy(Autor,cad);
}

void Libro::GetAutor(char * cad) const {
    if(Autor == nullptr) cad[0]=0;
    strcpy(cad,Autor);
}

void Libro::SetTitulo(const char* cad) {
    if(Titulo != nullptr) delete Titulo;
    Titulo = new char[strlen(cad)+1];
    strcpy(Titulo,cad);
}

void Libro::GetTitulo(char * cad) const {
    if(Titulo == nullptr) cad[0]=0;
    strcpy(cad,Titulo);
}

void Libro::SetCodigo(const char* cad) {
    if(Codigo != nullptr) delete Codigo;
    Codigo = new char[strlen(cad)+1];
    strcpy(Codigo,cad);
}

char* Libro::GetCodigo() const {
   char *Cad;
    Cad =  new char [strlen(Codigo)+1]{};
    strcpy(Cad,Codigo);
    return Cad;
}
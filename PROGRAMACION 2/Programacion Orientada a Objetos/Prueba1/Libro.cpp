/* 
 * File:   Libro.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 19:54
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
    Autor = nullptr;
    Stock = 0;
    Precio =0;
}
void Libro::Leer(ifstream &arch){
    char Buff[100],c;
    arch.getline(Buff,100,',');
    SetCodigo(Buff);
    arch.getline(Buff,100,',');
    SetTitulo(Buff);
    arch.getline(Buff,100,',');
    SetAutor(Buff);
    arch>>Stock>>c>>Precio;
    arch.get();
}
void operator >>(ifstream &arch, Libro &L){
    L.Leer(arch);
}
void operator <<(ofstream &arch, Libro L){
    arch.precision(2);
    arch<<fixed;
    char *Cod = L.GetCodigo();
    char *titulo = L.GetTitulo();
    char *autor = L.GetAutor();
    arch<<left<<setw(12)<<Cod<<setw(60)<<titulo<<setw(40)<<autor<<setw(7)<<L.GetStock()<<L.GetPrecio()<<endl;
}
void Libro::SetPrecio(double Precio) {
    this->Precio = Precio;
}

double Libro::GetPrecio() const {
    return Precio;
}

void Libro::SetStock(int Stock) {
    this->Stock = Stock;
}

int Libro::GetStock() const {
    return Stock;
}

void Libro::SetAutor(const char*cad ) {
    if(Autor!=nullptr) delete Autor;
    Autor=new char[strlen(cad)+1];
    strcpy(Autor,cad);
}

char* Libro::GetAutor() const {
    char *cad;
    cad = new char[strlen(Autor)+1];
    strcpy(cad,Autor);
    return cad;
}

void Libro::SetTitulo(const char*cad ) {
    if(Titulo!=nullptr) delete Titulo;
    Titulo =new char[strlen(cad)+1];
    strcpy(Titulo,cad);
}

char* Libro::GetTitulo() const {
    char *cad;
    cad = new char[strlen(Titulo)+1];
    strcpy(cad,Titulo);
    return cad;
}

void Libro::SetCodigo(const char* cad) {
    if(Codigo!=nullptr) delete Codigo;
    Codigo=new char[strlen(cad)+1];
    strcpy(Codigo,cad);
}

char* Libro::GetCodigo() const {
    char *cad;
    cad = new char[strlen(Codigo)+1];
    strcpy(cad,Codigo);
    return cad;
}
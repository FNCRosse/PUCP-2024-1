/* 
 * File:   Biblioteca.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 12:55
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca(){
    cantidad_estantes=0;
    cantidad_libros=0;
}
void Biblioteca::CargaLibros(){
    ifstream arch("libros.csv");
    while(true){
        arch>>libros[cantidad_libros];
        if(arch.eof()) break;
        cantidad_libros++;
    }
}
void Biblioteca::CargaEstantes(){
    ifstream arch("estantes.csv");
    while(true){
        arch>>estantes[cantidad_estantes];
        if(arch.eof()) break;
        cantidad_estantes++;
    }
}
void Biblioteca::PosicionarLibros(){
    for(int i=0;i<cantidad_libros;i++){
        for(int k=0;k<cantidad_estantes;k++){
            if(estantes[k]+=libros[i]) break;
        }
    }
}
void Biblioteca::imprimirLinea(char letra, int cant, ofstream &arch){
    for(int i=0;i<cant;i++)arch<<letra;
    arch<<endl;
}
void Biblioteca::MostrarDatos(){
    ofstream arch("ReporteFinal.txt");
    imprimirLinea('=',100,arch);
    arch<<right<<setw(60)<<"Informacion del posicionamiento de Libros"<<endl<<setw(40)
            <<"en los estantes de la biblioteca"<<endl;
    imprimirLinea('=',100,arch);
    arch<<left<<"Cantidad de Estantes:  "<<cantidad_estantes<<endl;
    for(int i=0;i<cantidad_estantes;i++){
        imprimirLinea('-',100,arch);
        arch<<estantes[i];
    }
    imprimirLinea('=',100,arch);
    arch<<"Informacion de todos los libros: "<<endl<<"Cantidad de libros total: "<<cantidad_libros<<endl;
    for(int i=0;i<cantidad_libros;i++){
        arch<<libros[i];
    }
    imprimirLinea('=',100,arch);
}

void Biblioteca::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Biblioteca::GetCantidad_libros() const {
    return cantidad_libros;
}

void Biblioteca::SetCantidad_estantes(int cantidad_estantes) {
    this->cantidad_estantes = cantidad_estantes;
}

int Biblioteca::GetCantidad_estantes() const {
    return cantidad_estantes;
}


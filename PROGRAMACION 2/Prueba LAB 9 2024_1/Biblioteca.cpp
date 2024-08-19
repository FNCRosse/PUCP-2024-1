/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Rosse
 * 
 * Created on 9 de julio de 2024, 06:06
 */

#include "Biblioteca.h"

void Biblioteca::Carga() {
    ifstream archL("Libros31.csv");
    ifstream archE("Estantes3.csv");
    class NEstante* dato;
    AEstante.inicializarArbol();
    while(true){
        dato = new NEstante();
        if(dato->LeerDatos(archE)) break;
        dato->LeerLibros(archL);
        AEstante.Insertar(dato);
    }
}

void Biblioteca::Muestra() {
    ofstream arch ("Reporte.txt");
    arch<<left;
    arch.precision(2);
    arch<<fixed;
    AEstante.Imprimir(arch);
}

void Biblioteca::Prueba(double pesoLib) {
    ofstream arch ("ReporteBusqueda.txt");
    arch<<left;
    arch.precision(2);
    arch<<fixed;
    if(AEstante.PuedeSerAsignado(pesoLib,arch)){
        arch<<"NO Hay Espacio"<<endl;
    } 
}
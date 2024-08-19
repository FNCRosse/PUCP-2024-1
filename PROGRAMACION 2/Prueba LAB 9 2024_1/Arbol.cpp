/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Rosse
 * 
 * Created on 9 de julio de 2024, 05:53
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}
void Arbol::inicializarArbol() {
    raiz = nullptr;
}

void Arbol::Insertar(class NEstante *dato) {
    InsertarRecursivo(raiz,dato);
}

void Arbol::Imprimir(ofstream &arch) {
    ImprimirRecursivo(raiz,arch);
}

void Arbol::InsertarRecursivo(class NEstante *&raiz,class NEstante *dato) {
    if(raiz == nullptr){
        raiz = new NEstante();
        raiz = dato;
        return;
    }
    else if(raiz->disponible > dato->disponible) InsertarRecursivo(raiz->izq,dato);
    else if(raiz->disponible < dato->disponible) InsertarRecursivo(raiz->der,dato);
}

void Arbol::ImprimirRecursivo(class NEstante *&raiz, ofstream &arch) {
    if(raiz == nullptr) return;
    ImprimirRecursivo(raiz->izq,arch);
    raiz->imprimeDatos(arch);
    ImprimirRecursivo(raiz->der,arch);
}
bool Arbol::PuedeSerAsignado(double pesoLib,ofstream &arch){
    return PuedeSerAsignadoREC(raiz,pesoLib,arch);
}
bool Arbol::PuedeSerAsignadoREC(class NEstante *&raiz,double pesoLib,ofstream &arch){
    if(raiz == nullptr) return false;
     PuedeSerAsignadoREC(raiz->izq,pesoLib,arch);
     PuedeSerAsignadoREC(raiz->der,pesoLib,arch);
    if(raiz->disponible >= pesoLib){
        arch<<"SI Hay Espacio"<<endl;
        raiz->imprimeDatos(arch);
        return true;
    }
}
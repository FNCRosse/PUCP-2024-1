/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 21:27
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

void Arbol::Asignar(char tipo, ifstream &arch) {
    Boleta Dato;
    Dato.AsignarMemoria(tipo);
    Dato.LeerDatos(arch);
    Insertar(Dato);
}

void Arbol::Insertar(Boleta &dato) {
    InsertarR(raiz,dato);
}

void Arbol::InsertarR(class Nodo *&raiz, Boleta &dato) {
    if (raiz ==  nullptr){
        raiz = new class Nodo;
        raiz->dboleta = dato;
        return;
    }
    if (dato.getCodigo()< raiz->dboleta.getCodigo() ) InsertarR(raiz->izq,dato);
    else InsertarR(raiz->der,dato);
}

void Arbol::ImprimirEnOrden(ofstream &arch) {
    ImprimirEnOrdenR(arch,raiz);
}
void Arbol::ImprimirEnOrdenR(ofstream &arch, class Nodo*&raiz){
    if(raiz){
        ImprimirEnOrdenR(arch,raiz->izq);
        raiz->MostrarDatos(arch);
        ImprimirEnOrdenR(arch,raiz->der);
    }
}
void Arbol::LeerEscalas(ifstream &arch){
    int escala;
    double precio;
    while(true){
        arch>>escala;
        if(arch.eof()) break;
        arch.get();
        arch>>precio;arch.get();
        lescala[escala-1].SetCodigo(escala);
        lescala[escala-1].SetPrecio(precio);
    }
}
void Arbol::ActualizarBoleta(){
    ActualizarBoletaR(raiz);
}
void Arbol::ActualizarBoletaR(class Nodo*&raiz){
    if(raiz){
        ActualizarBoletaR(raiz->izq);
        raiz->ActualizaPrecio(lescala);
        ActualizarBoletaR(raiz->der);
    }
}
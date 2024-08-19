/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 12:05
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Arbol.h"

Arbol::Arbol() {
    arbol = nullptr;
}

Arbol::~Arbol() {
    elimina(arbol);
}

void Arbol::Crear(const char* namefile) {
    ifstream arch (namefile);
    int dato;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        insertarR(arbol,dato);
    }
}

void Arbol::Insertar(int dato) {
    insertarR(arbol,dato);
}

void Arbol::MostrarEnOrden() {
    MostrarEnOrdenR(arbol);
    cout<<endl;
}

int Arbol::buscar(int dato) {
    return buscarR(arbol,dato);
}
int Arbol::buscarR(class Nodo *arbol, int dato){
    if(arbol == nullptr) return -1;
    if(arbol->dato == dato ) return dato;
    if ( dato < arbol->dato) return buscarR(arbol->izq,dato);
    else return buscarR(arbol->der,dato);
}
void Arbol::insertarR(class Nodo *&arbol, int dato) {
    if(arbol == nullptr){
        arbol = new class Nodo;
        arbol->dato = dato;
        return;
    }
    if(dato < arbol->dato ) insertarR(arbol->izq,dato);
    else insertarR(arbol->der,dato);
}

void Arbol::MostrarEnOrdenR(class Nodo *arbol) {
    if(arbol){
        MostrarEnOrdenR(arbol->izq);
        cout<<setw(4)<<arbol->dato;
        MostrarEnOrdenR(arbol->der);
    }
}

void Arbol::elimina(class Nodo *arbol) {
    if(arbol){
        elimina(arbol->izq);
        elimina(arbol->der);
        delete arbol;
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
//        lescala[escala-1];
    }
}
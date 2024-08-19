/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Lista.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 10:14
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "Lista.h"
#include "Persona.h"

Lista::Lista() {
    lista = nullptr;
}

Lista::~Lista() {
    elimina();
}

void Lista::Crear(const char* filename) {
    ifstream arch(filename);
    class Persona dato;
    while (true) {
        arch>>dato;
        if (arch.eof()) break;
        Insetar(dato);
    }
}

void Lista::Insetar(const Persona &dato) {
    class Nodo *p = lista, *ant = nullptr, *nuevo;
    nuevo = new class Nodo;
    nuevo->dato = dato;
    while (p) {
        if (p->dato > dato) break;
        ant = p;
        p = p->sig;
    }
    nuevo->sig = p;
    if (ant != nullptr) ant->sig = nuevo;
    else lista = nuevo;
}

void Lista::Imprimir(const char *filename) {
    ofstream arch(filename);
    class Nodo *p = lista;
    while (p) {
        arch << p->dato;
        p = p->sig;
    }
    arch << endl;
}

void Lista::elimina() {
    class Nodo *sale;
    while (lista) {
        sale = lista;
       lista = lista->sig;
       delete sale;
    }
    lista = nullptr;
}

void Lista::ImrprimirR(const char *filename) {
    ofstream arch(filename);
    imprimeRecursivo(arch,lista);
    arch<<endl;
}
void Lista::imprimeRecursivo(ofstream &arch,class Nodo *p){
    if(p == nullptr) return;
    imprimeRecursivo(arch,p->sig);
    arch<<p->dato;  
}
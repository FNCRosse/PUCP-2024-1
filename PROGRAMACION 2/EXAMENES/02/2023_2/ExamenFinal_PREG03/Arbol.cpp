/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Arbol.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 12:57
 */

#include "Arbol.h"
Arbol::Arbol(){
    raiz = nullptr;
}

void Arbol::Insertar(class Vehiculo* dato){
    InsertarRecursivo(raiz,dato);
}
void Arbol::InsertarRecursivo(class Nodo*&raiz, class Vehiculo* dato){
    if(raiz == nullptr){
        raiz = new class Nodo();
        raiz->unidad = dato;
        return;
    } 
    else if(raiz->unidad->GetDni() > dato->GetDni()) InsertarRecursivo(raiz->izq,dato);
    else if(raiz->unidad->GetDni() < dato->GetDni()) InsertarRecursivo(raiz->der,dato);
}
void Arbol::Imprimir(ofstream &arch){
    ImprimirRecursivo(arch,raiz);
}
void Arbol::ImprimirRecursivo(ofstream &arch, class Nodo *&raiz){
    if(raiz == nullptr) return;
    ImprimirRecursivo(arch,raiz->izq);
    raiz->unidad->mostrar(arch);
    ImprimirRecursivo(arch,raiz->der);
}
void  Arbol::EliminarNodos(int cantidad){
    int contador =0;
    EliminarNodosRecursivo(contador,cantidad,raiz);
}
void Arbol::EliminarNodosRecursivo(int& contador,int cantidad, class Nodo *&raiz){
    if(cantidad <= contador or raiz==nullptr) return;
    EliminarNodosRecursivo(contador,cantidad,raiz->izq);
    EliminarNodosRecursivo(contador,cantidad,raiz->der);
    if(contador<=cantidad and not TieneHijos(raiz)){
        class Nodo* temp = raiz;
        raiz = nullptr;
        delete temp;
        contador++;
    }
}
bool Arbol::TieneHijos(class Nodo* raiz){
    if (raiz->der != nullptr or raiz->izq!= nullptr) return true;
    else return false;
}
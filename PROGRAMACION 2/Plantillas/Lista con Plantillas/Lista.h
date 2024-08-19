/* 
 * File:   Lista.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de junio de 2024, 11:12
 */

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <fstream>

#include "Nodo.h"
using namespace std;

template <typename T>
class Lista {
private:
    class Nodo<T> *lista;
    void imprimeRecursivo(ofstream &arch, class Nodo<T> *p);
public:
    Lista();
    virtual ~Lista();
    void Crear(const char *filename);
    void Insertar(T &dato);
    void imprimir(const char *filename);
    void elimina();
    void ImprimeR(const char * filename);
};

template <typename T>
Lista<T>::Lista(){
    lista=nullptr;
}
template <typename T>
Lista<T>::~Lista(){
    elimina();
}
template <typename T>
void Lista<T>::Crear(const char* filename){
    ifstream arch(filename);
    T dato;
    while(true){
        arch>>dato;
        if(arch.eof()) break;
        Insertar(dato);
    }
}
template <typename T>
void Lista<T>::Insertar(T& dato){
    class Nodo<T> *p=lista, *ant=nullptr,*nuevo;
    nuevo = new class Nodo<T>;
    nuevo->dato = dato;
    while(p){
        if(p->dato > dato) break;
        ant = p;
        p=p->sig;
    }
    nuevo->sig = p;
    if(ant!= nullptr) ant->sig = nuevo;
    else lista = nuevo;
}
template <typename T>
void Lista<T>::imprimir(const char* filename){
    ofstream arch(filename);
    class Nodo<T> *p=lista;
    arch<<"Datos de la lista:"<<endl;
    while(p){
        arch<<p->dato;
        arch<<endl;
        p = p->sig;
    }
}
template <typename T>
void Lista<T>::elimina(){
    class Nodo<T> *sale;
    while(lista){
        sale = lista;
        lista = lista->sig;
        delete sale;
    }
    lista = nullptr;
}
template <typename T>
void Lista<T>::ImprimeR(const char* filename){
    ofstream arch(filename);
    arch<<"Datos de la lista:"<<endl;
    imprimeRecursivo(arch,lista);
    arch<<endl;
}
template <typename T>
void Lista<T>::imprimeRecursivo(ofstream& arch, Nodo<T>* p){
    if(p== nullptr) return;
    imprimeRecursivo(arch,p->sig);
    arch<<p->dato;
    arch<<endl;
}
#endif /* LISTA_H */


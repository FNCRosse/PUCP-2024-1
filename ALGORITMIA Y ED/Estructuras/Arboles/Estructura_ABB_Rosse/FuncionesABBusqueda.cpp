/* 
 * File:   FuncionesABBusqueda.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de octubre de 2023, 11:14
 */
#include <iostream>
#include <complex>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
#include "ListaP.h"
#include "Pila.h"
#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "FuncionesArbolBinario.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
#include "funcionesListaP.h"
#include "funcionesPila.h"
#include "FuncionesABBusqueda.h"

//INSERTAR ELEMENTOS EN EL ARBOL
void plantarArbolBB(struct NodoArbol *&arbol,
                                struct NodoArbol *arbolIzq, int elemento, struct NodoArbol *arbolDer){
    struct NodoArbol *nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->derecha = arbolDer;
    nuevoNodo->izquierda = arbolIzq;
    arbol = nuevoNodo;
}
void InsertarRecursivo (struct NodoArbol *& raiz, int elemento){
    if(raiz == nullptr)
        plantarArbolBB(raiz,nullptr,elemento,nullptr);
    else 
        if(raiz->elemento > elemento)
            InsertarRecursivo(raiz->izquierda,elemento);
        else
            InsertarRecursivo(raiz->derecha,elemento);
}
void Insertar (struct ArbolBinario &arbol, int elemento){
    InsertarRecursivo(arbol.raiz,elemento);
}
//MINIMO ELEMENTO DE UN ARBOL
int MinimoRecursivoABB(struct NodoArbol *nodo){
    if(esNodoVacio(nodo)){
        cout<<"El arbol esta vacio"<<endl;
        exit(1);
    }
    if(esNodoVacio(nodo->izquierda)) return nodo->elemento;
    MinimoRecursivoABB(nodo->izquierda);
}
int MinimoABB(struct ArbolBinario arbol){
    return MinimoRecursivoABB(arbol.raiz);
}
//MAXIMO ELEMENTO DE UN ARBOL
int MaximoRecursivoABB(struct NodoArbol *nodo){
    if(esNodoVacio(nodo)){
        cout<<"El arbol esta vacio"<<endl;
        exit(1);
    }
    if(esNodoVacio(nodo->derecha)) return nodo->elemento;
    MaximoRecursivoABB(nodo->derecha);
}
int MaximoABB(struct ArbolBinario arbol){
    return MaximoRecursivoABB(arbol.raiz);
}
//ELIMINAR UN NODO DE UN ARBOL
struct NodoArbol *  minimoArbol(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    minimoArbol(nodo->izquierda);
}
int ComprararABB(int elementoA, int elementoB){
    if(elementoA == elementoB) return 0;
    else if (elementoA < elementoB) return -1;
    else if (elementoA > elementoB) return 1;
}
struct NodoArbol *borrarNodoRecursivo(struct NodoArbol *nodo,int dato){
    if(esNodoVacio(nodo)) return nodo;
    if (ComprararABB(nodo->elemento,dato) == 1) //Nodo mayor que el dato
        nodo->izquierda = borrarNodoRecursivo(nodo->izquierda,dato);
    else{
        if (ComprararABB(nodo->elemento,dato) == -1) //Nodo menor que el dato
            nodo->derecha = borrarNodoRecursivo(nodo->derecha,dato);
        else{
            if (esNodoVacio(nodo->izquierda)){
                struct NodoArbol *elimina = nodo->derecha;
                delete nodo;
                nodo = nullptr;
                return elimina;
            }
            else{
                if(esNodoVacio(nodo->derecha)){
                    struct NodoArbol *elimina = nodo->izquierda;
                    delete nodo;
                    nodo = nullptr;
                    return elimina;
                }
                else{
                    struct NodoArbol *temp = minimoArbol(nodo->derecha);
                    nodo->elemento = temp->elemento;
                    nodo->derecha = borrarNodoRecursivo(nodo->derecha,temp->elemento);
                }
            }
        }
    }
    return nodo;
}
void borrarNodo(struct ArbolBinario arbol,int dato){
    arbol.raiz= borrarNodoRecursivo(arbol.raiz,dato);
}
// SUMAR LOS ELEMENOS DE TODO EL ARBOL
int SumarNodosRecursivo(struct NodoArbol *nodo){
    if(esNodoVacio(nodo)) return 0;
    else
        return nodo->elemento + SumarNodosRecursivo(nodo->izquierda)+SumarNodosRecursivo(nodo->derecha);
}
int SumarNodos(struct ArbolBinario arbol){
    return SumarNodosRecursivo(arbol.raiz);
}
//SI SE ENCUENTRA EL ELEMENTO EN EL ARBOL
bool buscarArbolRecursivo(struct NodoArbol* nodo,int dato){
    if(esNodoVacio(nodo)) return false;
    if(ComprararABB(nodo->elemento,dato) == 0) return true;
    if(ComprararABB(nodo->elemento,dato) == 1) return buscarArbolRecursivo(nodo->izquierda,dato);
    else if(ComprararABB(nodo->elemento,dato) == -1) return buscarArbolRecursivo(nodo->derecha,dato);
}
bool buscarArbol(struct ArbolBinario arbol,int dato){
    return buscarArbolRecursivo(arbol.raiz,dato);
}
//FUSIONAR ARBOLES
void FusionarRecursivo(struct NodoArbol *nodo1, struct NodoArbol* nodo2){
    int valor;
    struct NodoArbol* nodoAux;
    nodoAux = nodo2;
    if(nodo2 == nullptr) return; // Caso Base
    if(nodoAux){
        FusionarRecursivo(nodo1,nodoAux->izquierda);
        FusionarRecursivo(nodo1,nodoAux->derecha);
        valor = nodoAux->elemento; //Guardamos el valor del elemento del nodo
        delete nodoAux; //Liberamos la memoria que ocupa el nodo
        //Antes de insertar el valor del nodo, se tiene que verificar que el nodo no exista en el arbol de destino
        if(!buscarArbolRecursivo(nodo1,valor)) 
            InsertarRecursivo(nodo1,valor); // insertamos en el arbol destino
        nodo2 = nullptr; 
    }
}
void Fusionar(struct ArbolBinario *arbol1, struct ArbolBinario *arbol2){
    FusionarRecursivo(arbol1->raiz,arbol2->raiz);
    arbol2->raiz = nullptr;
}

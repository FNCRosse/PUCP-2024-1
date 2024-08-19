/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 24 de septiembre de 2023, 10:36 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ArbolBinario.h"
#include "funcionesArbolesBB.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "NodoArbol.h"

void construir(struct ArbolBinarioBusqueda & arbol){
    construir(arbol.arbolBinario);
}

bool esArbolVacio(struct ArbolBinarioBusqueda  arbol){
    esArbolVacio(arbol.arbolBinario);
}

void plantarArbolBB(struct NodoArbol *& arbol, 
                         struct NodoArbol * arbolIzquierdo, int elemento, 
                         struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    arbol = nuevoNodo;
}

void insertarRecursivo(struct NodoArbol *& raiz, int elemento){
    if(raiz == nullptr)
        plantarArbolBB(raiz, nullptr, elemento, nullptr);
    else
        if (raiz->elemento > elemento)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            insertarRecursivo(raiz->derecha, elemento);
}

void insertar(struct ArbolBinarioBusqueda & arbol, int elemento){
    insertarRecursivo(arbol.arbolBinario.raiz, elemento);
}

void enOrden(struct ArbolBinarioBusqueda arbol){
    recorrerEnOrden(arbol.arbolBinario);
}

void preOrden(struct ArbolBinarioBusqueda arbol){
    recorrerPreOrden(arbol.arbolBinario);
}

void postOrden(struct ArbolBinarioBusqueda arbol){
    recorrerPostOrden(arbol.arbolBinario);
}

void destruirArbolBB(struct ArbolBinarioBusqueda arbol){
    destruirArbolBinario(arbol.arbolBinario);
}

int minimoABBRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo)){
        cout<<"El árbol está vacío"<<endl;
        exit(1);
    }
    if(esNodoVacio(nodo->izquierda))
        return nodo->elemento;
    minimoABBRecursivo(nodo->izquierda);
}

int minimoABB(struct ArbolBinarioBusqueda arbol){
    return minimoABBRecursivo(arbol.arbolBinario.raiz);
}

int maximoABBRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo)){
        cout<<"El árbol está vacío"<<endl;
        exit(1);
    }
    if(esNodoVacio(nodo->derecha))
        return nodo->elemento;
    maximoABBRecursivo(nodo->derecha);
}

int maximoABB(struct ArbolBinarioBusqueda arbol){
    return maximoABBRecursivo(arbol.arbolBinario.raiz);
}
struct NodoArbol *  minimoArbol(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    minimoArbol(nodo->izquierda);
}

struct NodoArbol * borraNodoRecursivo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo))
        return nodo;
    if(comparaABB(nodo->elemento, dato) == 1){ //nodo mayor que el dato
        nodo->izquierda = borraNodoRecursivo(nodo->izquierda, dato);
    }
    else{
        if(comparaABB(nodo->elemento, dato) == -1){ //nodo menor que el dato
            nodo->derecha = borraNodoRecursivo(nodo->derecha, dato);
        }
        else{
            if(esNodoVacio(nodo->izquierda)){
                struct NodoArbol * elimina = nodo->derecha;
                delete nodo;
                nodo = nullptr;
                return elimina;
            }
            else{
                if(esNodoVacio(nodo->derecha)){
                    struct NodoArbol * elimina = nodo->izquierda;
                    delete nodo;
                    nodo = nullptr;
                    return elimina;
                }
                else{
                    struct NodoArbol * temp = minimoArbol(nodo->derecha);
                    nodo->elemento = temp->elemento;
                    nodo->derecha = borraNodoRecursivo(nodo->derecha, temp->elemento);
                }
            }
        }
    }
    return nodo;
}

void  borraNodo(struct ArbolBinarioBusqueda arbol, int dato){
    arbol.arbolBinario.raiz = borraNodoRecursivo(arbol.arbolBinario.raiz, dato);
}

int comparaABB(int elementoA, int elementoB ){
    if(elementoA == elementoB) return 0;
    else if(elementoA < elementoB) return -1;
    else if (elementoA > elementoB) return 1;
}

bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo)){
        return false;
    } 
    if(comparaABB(nodo->elemento, dato) == 0)
        return true;
    if(comparaABB(nodo->elemento, dato) == 1)
        return buscaArbolRecursivo(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento, dato) == -1) 
            return buscaArbolRecursivo(nodo->derecha, dato);
}

bool buscaArbol(struct ArbolBinarioBusqueda arbol ,int dato){
    return buscaArbolRecursivo(arbol.arbolBinario.raiz, dato);
}
void recorridoPorNivel(struct ArbolBinarioBusqueda arbol){
    recorridoPorNivel(arbol.arbolBinario);
}

int sumarNodos(struct ArbolBinarioBusqueda arbol){
    return sumarNodos(arbol.arbolBinario);
}

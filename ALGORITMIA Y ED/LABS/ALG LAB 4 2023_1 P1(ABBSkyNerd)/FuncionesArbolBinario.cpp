/* 
 * File:   FuncionesArbolBinario.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de octubre de 2023, 19:49
 */
#include <iostream>
#include <iomanip>
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

//------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------Estructura---------------------------------------------//
//------------------------------------------------------------------------------------------------------------//
 //Inicializar la raiz 
void contruir(struct ArbolBinario &arbol){
    arbol.raiz = nullptr;
}
// se hace otra funcion mas , por que no se puede hacer directamente a q arbol.raiz sea null por 
    // el encapsulamiento: para que el codigo sea mas modular y entendible
    // la abstraccion: ocultar detalles interno al usuario 
bool esNodoVacio (struct NodoArbol * nodo){
    return nodo == nullptr;
}
bool esArbolVacio(struct ArbolBinario arbol){
    return esNodoVacio(arbol.raiz);
}
struct NodoArbol *CrearNuevoNodoArbol(struct NodoArbol *HijoIzq,Servidor elemento,struct NodoArbol *HijoDer){
    struct NodoArbol *nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = HijoIzq;
    nuevoNodo->derecha = HijoDer;
    return nuevoNodo;
}
//------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------Plantar------------------------------------------------//
//------------------------------------------------------------------------------------------------------------//
//Hay funciones con el mismo nombre q tienes parametros diferentes(sobrecarga de funciones)
//En este caso es para plantar arboles binario apartir de nodos o arboles
void PlantarArbolBinario(struct ArbolBinario &arbol,
                                          struct NodoArbol * HijoIzq, Servidor elemento, struct NodoArbol * HijoDer){
    struct NodoArbol * nuevoNodo = CrearNuevoNodoArbol(HijoIzq,elemento,HijoDer);
    arbol.raiz = nuevoNodo;
}
void PlantarArbolBinario(struct ArbolBinario &arbol,
                                          struct ArbolBinario arbolIzq,Servidor elemento,struct ArbolBinario arbolDer){
    struct NodoArbol * nuevoNodo = CrearNuevoNodoArbol(arbolIzq.raiz,elemento,arbolDer.raiz);
    arbol.raiz = nuevoNodo;
}
//------------------------------------------------------------------------------------------------------------//
//--------------------------------------------------Recorrer-----------------------------------------------//
//------------------------------------------------------------------------------------------------------------//
void ImprimirRaiz(struct ArbolBinario arbol){
    ImprimirNodo(arbol.raiz);
}
void ImprimirNodo(struct NodoArbol *nodo){
    cout<<setw(5)<<nodo->elemento.tipo<<"-"<<nodo->elemento.velocidad<<"  ";
}
//RECORRER RECURSIVO EN ORDEN (D-E-B-A-C)
void RecorrerEnOrdenRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo)) return;
    RecorrerEnOrdenRecursivo(nodo->izquierda);
    ImprimirNodo(nodo);
    RecorrerEnOrdenRecursivo(nodo->derecha);
};
void recorrerEnOrden(struct ArbolBinario arbol){
    if( esArbolVacio(arbol)) return;
    //Se crea otra funcion por que para recorrer necesitamos el nodo, la cual si tiene la estructura enseñada
    RecorrerEnOrdenRecursivo(arbol.raiz);
    cout<<endl;
}
//RECORRER RECURSIVO EN PREORDEN / DESCENDENTE (A-B-D-E-C)
void RecorrerEnPreOrdenRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo)) return;
    ImprimirNodo(nodo);
    RecorrerEnPreOrdenRecursivo(nodo->izquierda);
    RecorrerEnPreOrdenRecursivo(nodo->derecha);
};
void recorrerEnPreOrden(struct ArbolBinario arbol){
    if( esArbolVacio(arbol)) return;
    RecorrerEnPreOrdenRecursivo(arbol.raiz);
    cout<<endl;
}
//RECORRER RECURSIVO EN POSTORDEN / ASCENDENTE (D-E-B-C-A)
void RecorrerEnPostOrdenRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo)) return;
    RecorrerEnPostOrdenRecursivo(nodo->izquierda);
    RecorrerEnPostOrdenRecursivo(nodo->derecha);
    ImprimirNodo(nodo);
};
void recorrerEnPostOrden(struct ArbolBinario arbol){
    if( esArbolVacio(arbol)) return;
    RecorrerEnPostOrdenRecursivo(arbol.raiz);
    cout<<endl;
}
//RECORRER POR NIVELES (A-B-C-D-E)
void recorrerPorNivel(struct ArbolBinario arbol){
    if(esArbolVacio(arbol)) return;
    struct Cola cola;
    construir(cola);
    encolar(cola,arbol.raiz);
    while(!esColaVacia(cola)){
        struct NodoArbol *nodo = desencolar(cola);
        ImprimirNodo(nodo);
        if(!esNodoVacio(nodo->izquierda)) encolar(cola,nodo->izquierda);
        if(!esNodoVacio(nodo->derecha)) encolar(cola,nodo->derecha);
    }
    destruirCola(cola);
    cout<<endl;
}
//RECORRER ITERATIVO EN ORDEN (D-E-B-A-C)
void recorreriIterativoEnOrden(struct ArbolBinario arbol){
    struct Pila pila;
    construir(pila);
    int fin = 0;
    do{
        while(!esArbolVacio(arbol)){
            apilar(pila,arbol.raiz);
            arbol.raiz = arbol.raiz->izquierda;
        }
        if(esPilaVacia(pila)) fin = 1;
        else{
            arbol.raiz = desapilar(pila);
            ImprimirRaiz(arbol);
            arbol.raiz = arbol.raiz->derecha;
        }
    }while(fin==0);
    destruirPila(pila);
    cout<<endl;
}
//RECORRER ITERATIVO EN PREORDEN / DESCENDENTE (A-B-D-E-C)
void recorreriIterativoEnPreOrden(struct ArbolBinario arbol){
    struct Pila pila;  /*Se usa una pila para acceder a los nodos*/
    construir(pila);
    if (not esArbolVacio(arbol)){        
        apilar(pila, arbol.raiz);
        while(not esPilaVacia(pila)){
            struct NodoArbol * nodo = desapilar(pila);
            ImprimirNodo(nodo);
            if (not esNodoVacio(nodo->derecha))
                apilar(pila, nodo->derecha);
            if (not esNodoVacio(nodo->izquierda))
                apilar(pila, nodo->izquierda);           
        }
    }
    destruirPila(pila);   
    cout<<endl;
}
//RECORRER DE MAYOR A MENOR ELEMENTO 
void recorrerMayorAMenor(struct ArbolBinario arbol){
    struct Pila pila;
    construir(pila);
    int fin = 0;
    do{
        while(!esArbolVacio(arbol)){
            apilar(pila,arbol.raiz);
            arbol.raiz = arbol.raiz->derecha;
        }
        if(esPilaVacia(pila)) fin = 1;
        else{
            arbol.raiz = desapilar(pila);
            ImprimirRaiz(arbol);
            arbol.raiz = arbol.raiz->izquierda;
        }
    }while(fin==0);
    destruirPila(pila);
    cout<<endl;
}
//------------------------------------------------------------------------------------------------------------//
//------------------------------------------Caracteristicas-----------------------------------------------//
//------------------------------------------------------------------------------------------------------------//
//HALLAR LA ALTURA DEL ARBOL
int maximo (int a, int b){
    return a>=b?a:b;
}
int AlturaRecursiva (struct NodoArbol *nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0;
    else 
        return 1 + maximo( AlturaRecursiva(nodo->izquierda), AlturaRecursiva(nodo->derecha));
}
int Altura (struct ArbolBinario arbol){
    return AlturaRecursiva(arbol.raiz);
}
//HALLAR NUMERO DE ELEMENTOS DEL ARBOL
int numeroNodosRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);   
}
int numeroNodos(struct ArbolBinario arbol){
    return numeroNodosRecursivo(arbol.raiz);
}
//HALLAR NUMERO DE HOJAS
int numeroHojasRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if ( esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha) )
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}
int numeroHojas(struct ArbolBinario arbol){
    return numeroHojasRecursivo(arbol.raiz);
}
//SABER SI EL ARBOL ES EQUILIBRADO DE MANERA RECURSIVA
int esEquilibradoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 1;
    else{
        int alturaHijoIzquierdo = AlturaRecursiva(nodo->izquierda);
        int alturaHijoDerecho = AlturaRecursiva(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia<=1 and 
               esEquilibradoRecursivo(nodo->izquierda) and 
               esEquilibradoRecursivo(nodo->derecha);
    }        
}
int esEquilibrado(struct ArbolBinario arbol ){
    return esEquilibradoRecursivo(arbol.raiz);
}
//SABER SI EL NODO ES HOJA O NO
int esHoja(struct ArbolBinario arbol){
    if(esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}
//------------------------------------------------------------------------------------------------------------//
//---------------------------------------------DESTRUIR-------------------------------------------------//
//------------------------------------------------------------------------------------------------------------//
void destruirRecursivo(struct NodoArbol * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
        nodo = nullptr;
    }
}
void destruirArbolBinario(struct ArbolBinario &arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}
//------------------------------------------------------------------------------------------------------------//
//---------------------------------------------POSTFIJO.-------------------------------------------------//
//------------------------------------------------------------------------------------------------------------//


/* 
 * File:   funcionesArbolesBB.cpp
 * Author: ANA RONCAL
 * Created on 19 de septiembre de 2023, 10:46 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "NodoArbol.h"
#include "Nodo.h"
#include "ArbolBinario.h"
#include "Lista.h"
#include "ListaP.h"
#include "Cola.h"
#include "Pila.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"
#include "funcionesPila.h"

void construir(struct ArbolBinario & arbol ){
    arbol.raiz = nullptr;
}

bool esNodoVacio(struct NodoArbol * nodo){
    return nodo == nullptr;
}

bool esArbolVacio( struct ArbolBinario arbol){
    return esNodoVacio(arbol.raiz);
}

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol * arbolIzquierdo, 
                               int elemento, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct NodoArbol * arbolIzquierdo,
                         int elemento, struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo, elemento, arbolDerecho);
    arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(struct ArbolBinario & arbol, struct ArbolBinario arbolIzquierdo,
                         int elemento, struct ArbolBinario arbolDerecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(arbolIzquierdo.raiz, elemento, arbolDerecho.raiz);
    arbol.raiz = nuevoNodo;
}

char raiz(struct NodoArbol * nodo){
    if (esNodoVacio(nodo)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return nodo->elemento;
}

struct NodoArbol * hijoDerecho(struct ArbolBinario arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    return arbol.raiz->derecha;
}

struct  NodoArbol * hijoIzquierdo(struct ArbolBinario arbol){
    if (esArbolVacio(arbol)){
        cout<<"No se puede obtener raíz de un árbol vacio"<<endl;
        exit(1);
    }
    
    return arbol.raiz->izquierda;
 }

void imprimeRaiz(struct ArbolBinario arbol){
    imprimeNodo(arbol.raiz);
}

void imprimeNodo(struct NodoArbol * nodo){
    cout<<setw(5)<<nodo->elemento;
}

void recorrerEnOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimeNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

/*En árbol, se lleva a cabo visitando el hijo izquierdo del nodo, luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerEnOrden(struct ArbolBinario arbol){
    /*Imprime en orden*/
    if (not esArbolVacio(arbol)){
        recorrerEnOrdenRecursivo(arbol.raiz);
    }
}

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        imprimeNodo(nodo);
        recorrerEnPreOrdenRecursivo(nodo->izquierda);
        recorrerEnPreOrdenRecursivo(nodo->derecha);
    }
}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la raíz*/
void recorrerPreOrden(struct ArbolBinario arbol){
    if (not esArbolVacio(arbol)){
        recorrerEnPreOrdenRecursivo(arbol.raiz);
    }
}

void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo){
    if(not esNodoVacio(nodo)){
        recorrerEnPostOrdenRecursivo(nodo->izquierda);
        recorrerEnPostOrdenRecursivo(nodo->derecha);
        imprimeNodo(nodo);
    }
}

/*recorrido ascendente, se lleva a cabo visitando los hijos, y luego el nodo
 luego todos los restantes, comenzando por la raíz*/
void recorrerPostOrden(struct ArbolBinario arbol){
   
    if (not esArbolVacio(arbol)){
        recorrerEnPostOrdenRecursivo(arbol.raiz);
    }
}

int maximo(int a, int b){
    return a>=b ? a: b;
}

int alturaRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 0; 
    else
        return 1 + maximo( alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(struct ArbolBinario arbol){
    return alturaRecursivo(arbol.raiz); //como el arbol ha sido construido no va apuntar a nullptr
}

int numeroNodosRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);   
}

/*Determina el número de elementos del árbol*/
int numeroNodos(struct ArbolBinario arbol){
    return numeroNodosRecursivo(arbol.raiz);
}

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

int esEquilibradoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return 1;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia<=1 and 
               esEquilibradoRecursivo(nodo->izquierda) and 
               esEquilibradoRecursivo(nodo->derecha);
    }        
}

int esEquilibrado(struct ArbolBinario arbol ){
    return esEquilibradoRecursivo(arbol.raiz);
}

int esHoja(struct ArbolBinario arbol){
    if(esArbolVacio(arbol))
        return 0;
    else
        return esNodoVacio(arbol.raiz->izquierda) and esNodoVacio(arbol.raiz->derecha);
}

void destruirArbolBinario(struct ArbolBinario arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbol * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
        nodo = nullptr;
    }
}

/*recorre el árbol por niveles usando una cola*/
void recorridoPorNivel(struct ArbolBinario arbol){
    struct Cola cola; /*Se usa una cola para acceder a los nodos*/
    construir(cola);
    if(not esArbolVacio(arbol)){
        encolar(cola, arbol.raiz);
        while(not esColaVacia(cola)){
            struct NodoArbol * nodo = desencolar(cola);
            imprimeNodo(nodo);
            if (not esNodoVacio(nodo->izquierda)){
                encolar(cola, nodo->izquierda);
            }
            if (not esNodoVacio(nodo->derecha)){
                encolar(cola, nodo->derecha);  
            }
        }
    }
    destruirCola(cola);   
}

void enOrdenIterativo(struct ArbolBinario arbol){
    struct Pila pila; /*Se usa una pila para acceder a los nodos*/
    construir(pila);
    int fin = 0;
    do{
        while (not esArbolVacio(arbol)){
            apilar(pila, arbol.raiz);
            arbol.raiz = arbol.raiz->izquierda;
        }
        if (esPilaVacia(pila))
            fin = 1;
        else{
            arbol.raiz = desapilar(pila);
            imprimeRaiz(arbol);
            arbol.raiz = arbol.raiz->derecha;
        }
    } while(fin == 0);
    destruirPila(pila);
}

void preOrdenIterativo(struct ArbolBinario arbol){
    struct Pila pila;  /*Se usa una pila para acceder a los nodos*/
    construir(pila);
    if (not esArbolVacio(arbol)){        
        apilar(pila, arbol.raiz);
        while(not esPilaVacia(pila)){
            struct NodoArbol * nodo = desapilar(pila);
            imprimeNodo(nodo);
            if (not esNodoVacio(nodo->derecha))
                apilar(pila, nodo->derecha);
            if (not esNodoVacio(nodo->izquierda))
                apilar(pila, nodo->izquierda);           
        }
    }
    destruirPila(pila);   
}

void notacionPostfija(struct ArbolBinario & arbol){
    struct NodoArbol * operando1;
    struct NodoArbol * operando2;
    int resultado;
    
    char valor; //para guardar el valor que puede ser operando o operador
    struct Pila pila;
    construir(pila);
    while(not cin.eof()){
        cin>>valor;
        if (valor == '!') break; // Sale de la lectura con el cáracter '!'
        if (esOperador(valor)){
            operando2 = desapilar(pila);
            operando1 = desapilar(pila);
            plantarArbolBinario(arbol, operando1, valor, operando2);
            apilar(pila, arbol.raiz);
        }
        else{
            struct ArbolBinario arbol;
            construir(arbol); 
            plantarArbolBinario(arbol, nullptr, valor, nullptr);
            apilar(pila, arbol.raiz); 
        }
    }
}

int esOperador(char c){
    return (c == '+') or (c == '-') or (c == '*') or (c == '/');
}

int opera(char c, int operando1, int operando2){
    int resultado = 0;
   
    if (c == '+') 
        resultado = operando1 + operando2;
    else if (c == '-') 
        resultado = operando1 - operando2;
    else if (c == '*') 
        resultado = operando1 * operando2;
    else if(c == '/') 
        resultado = operando1 / operando2;
    
    return resultado;
}

int evaluaExpresionRecursiva(struct NodoArbol * nodo){
    int resultado, operando1, operando2;
    char elemento;
    if (esNodoVacio(nodo))
        resultado = 0;
    else{
        elemento = raiz(nodo);
        if(esOperador(elemento)){
            operando1 = evaluaExpresionRecursiva(nodo->izquierda);
            operando2 = evaluaExpresionRecursiva(nodo->derecha);
            resultado = opera(elemento, operando1, operando2);
        }
        else
            resultado = elemento - '0';
    }
    return resultado;
    
}
int evaluarExpresion(struct ArbolBinario arbol){
    evaluaExpresionRecursiva(arbol.raiz);
}

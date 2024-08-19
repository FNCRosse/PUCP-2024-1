/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#include <iostream>
#include <iomanip>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
using namespace std;
#include "funcionesLista.h"
#include "funcionesCola.h"


#define PROCESO 120
#define MAX_CAJEROS 10
#define NUM_CLIENTES 100

void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia( struct Cola  cola){
    return esListaVacia(cola.lista);
}

int longitud(struct Cola cola){
    return longitud(cola.lista);
}

void encolar(struct Cola & cola, struct NodoArbol * nodo){
    insertarAlFinal(cola.lista, nodo);
}

struct NodoArbol *  desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(1);
    }
    
    struct NodoArbol * nodo = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return nodo;
}

void destruirCola(struct Cola & cola){
    destruirLista(cola.lista);
}

void imprime( struct Cola  cola){
    imprime(cola.lista);
}
/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */


#include <iostream>
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"
using namespace std;
#include "funcionesLista.h"
#include "funcionesCola.h"

void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

int longitud(struct Cola cola){
    return longitud(cola.lista);
}

void encolar(struct Cola & cola, int elemento){
    insertarAlFinal(cola.lista, elemento);
}

int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(1);
    }
    int elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
}

void imprime(const struct Cola & cola){
    imprime(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruirLista(cola.lista);
}

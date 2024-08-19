/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 18 de abril de 2024, 10:28 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;

/*constructor de Cola*/
void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

void encolar(struct Cola & cola, int elemento){
    //cout<<"Encolando..."<<elemento<<endl;
    insertarAlFinal(cola.lista, elemento);
}

int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        return -10;
    }
    int elemento = retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return elemento;
}

int longitud(const struct Cola & cola){
    return longitud(cola.lista);
}

/*Se debe respetar el principio de la cola*/
void ordenarCola(struct Cola & cola, int n){
    
    if(esColaVacia(cola)) return;
    int mayor = desencolar(cola);
    int m = n;
    while(m > 0 and not(esColaVacia(cola))){
        int aux = desencolar(cola);
        if(mayor > aux){
            encolar(cola, aux);
        }
        else{
            encolar(cola, mayor);
            mayor = aux;
        }
        m--;
    }
    ordenarCola(cola, n - 1);
    encolar(cola, mayor);     
}

void imprimir(const struct Cola & cola){
    imprimir(cola.lista);
}
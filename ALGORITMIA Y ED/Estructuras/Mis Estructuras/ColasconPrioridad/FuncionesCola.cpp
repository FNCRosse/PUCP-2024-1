/* 
 * File:   FuncionesCola.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 15:21
 */
#include <iostream>
using namespace std;
#include "Cola.h"
#include "FuncionesListas.h"
#include "FuncionesCola.h"

void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

int longitud(struct Cola cola){
    return longitud(cola.lista);
}

void encolar(struct Cola & cola,struct Cliente cliente){
    insertarAlFinal(cola.lista, cliente);
}

int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola estÃ¡ vacÃ­a no se puede desencolar"<<endl;
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
void encolarConPrioridad(struct Cola &cola,const struct Cliente &Cliente){
    InsertarConPrioridad(cola.lista, Cliente);
}
void OrdenarCola(struct Cola &cola,int n/*longitud de la cola*/){
    if (esColaVacia(cola)) return;
    int mayor = desencolar(cola);
    int m =n;
    while(m>0 and not (esColaVacia(cola))){
        int aux = desencolar(cola);
        if(mayor > aux){
            encolar(cola, aux);
        } else {
            encolar(cola,mayor);
            mayor = aux;
        }
        m--;
    }
    OrdenarCola(cola, n-1);
    encolar(cola,mayor);
}
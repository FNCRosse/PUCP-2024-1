/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "Cola.h"
using namespace std;

#include "funcionesCola.h"
#include "funcionesLista.h"

void construir(struct Cola & cola){
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

int longitud(struct Cola cola){
    return longitud(cola.lista);
}

void encolar(struct Cola & cola, const struct Cliente & cliente){
    insertarAlFinal(cola.lista, cliente);
}

const struct Cliente desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        exit(1);
    }
    const struct Cliente cliente= retornaCabeza(cola.lista);
    eliminaCabeza(cola.lista);
    return cliente;
}


void destruirCola(struct Cola & cola){
    destruirLista(cola.lista);
}

void imprimir(const struct Cola & cola){
    imprimir(cola.lista);
}

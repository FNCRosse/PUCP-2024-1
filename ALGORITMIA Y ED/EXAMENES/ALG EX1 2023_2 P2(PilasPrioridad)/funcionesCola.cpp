/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 7 de abril de 2024, 06:07 PM
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"

using namespace std;
#include "funcionesLista.h"
#include "funcionesCola.h"

/*Construye la Cola*/
void construir(struct Cola & cola){
    construir(cola.lista);
}

/*Verifica si la cola está vacía*/
bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

/*Devuelve la longitud de la cola*/
int longitud(const struct Cola & cola){
    return longitud(cola.lista);
}

/*Añade un elemento a la cola*/
void encolar(struct Cola & cola, int elemento){
    insertarencola(cola.lista, elemento);
    //cout<<"Encolando: "<<elemento<<endl;
}

/*Elimina un elemento de la cola*/
int desencolar(struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
        return -1; //Cero o algún elemento que no esté en la cola
    }
    else{
        int elemento = retornaCabeza(cola.lista);
        eliminaCabeza(cola.lista);
        if(esColaVacia(cola))
            cola.lista.cola = nullptr;
        return elemento;
    }
    
}

/*Muestra los elementos de la cola*/
void imprime(const struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede mostrar"<<endl;
    }
    else
        imprime(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruir(cola.lista);
}

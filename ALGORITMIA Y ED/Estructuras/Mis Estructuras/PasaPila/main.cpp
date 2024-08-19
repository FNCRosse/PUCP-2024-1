/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Pila.h"

using namespace std;
#include "funcionesPila.h"

/*
 * IMPLEMENTACIÓN DE UNA PILA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2024-1
 */

void pasaPila(struct Pila &pila, struct Pila &pila2){
    int valor, n, aux;
    while (!esPilaVacia(pila)){
        valor = desapilar(pila);
        n=0;
        while (!esPilaVacia(pila)){
            apilar(pila2,valor);
            n++;
            valor = desapilar(pila);
        }
        while (n>0){
            aux = desapilar(pila2);
            apilar(pila,aux);
            n--;
        }
        apilar(pila2,valor);
    }
}

void pasaPilaRecursivo(struct Pila &pila,struct Pila &pila2){
    if (esPilaVacia(pila)){
        return ;
    }
    int valor = desapilar(pila);
    pasaPilaRecursivo(pila,pila2);
    apilar(pila2,valor);
}

int main(int argc, char** argv) {

    struct Pila pila;
    struct Pila pila2;
    construir(pila);
    construir(pila2);
    
    /*Apilamos elementos en la pila*/
    apilar(pila, 1);
    apilar(pila, 3);
    apilar(pila, 2);
    apilar(pila, 4);
    cout << "Pila" << endl;
    imprimir(pila);
    cout << "Pila2" << endl;
    imprimir(pila2);
    pasaPila(pila,pila2);
    cout << "Pasa pila iterativo " << endl;
    cout << "Pila" << endl;
    imprimir(pila);
    cout << "Pila2" << endl;
    imprimir(pila2);
    pasaPilaRecursivo(pila2,pila);
    cout << "Pasa pila recursivo " << endl;
    cout << "Pila" << endl;
    imprimir(pila);
    cout << "Pila2" << endl;
    imprimir(pila2);
    return 0;
}


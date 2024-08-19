/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"

using namespace std;
#include "funcionesCola.h"

void ordenarec(Cola &ptrcola,int n){
    int mayor,aux,i=1;
    
    if(esColaVacia(ptrcola)) return;
    mayor = desencolar(ptrcola);
    while(i<n){
        aux = desencolar(ptrcola);
        if(aux>mayor){
            encolar(ptrcola,mayor);
            mayor = aux;
        }
        else
            encolar(ptrcola,aux);
        i++;
    }
    ordenarec(ptrcola,n-1);
    encolar(ptrcola,mayor);
}

int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    cout<<"La cola está vacía: "<<esColaVacia(cola)<<endl;
    encolar(cola, 8);
    encolar(cola, 21);
    encolar(cola, 10);
    encolar(cola, 15);
    encolar(cola, 7);
    imprime(cola);
    ordenarec(cola,cola.lista.longitud);
    imprime(cola);
    destruirCola(cola);

    return 0;
}


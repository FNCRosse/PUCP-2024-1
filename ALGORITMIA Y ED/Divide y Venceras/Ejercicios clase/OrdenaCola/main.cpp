/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 24 de abril de 2024, 01:24 PM
 */

#include <iostream>

using namespace std;
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
#define NOENCONTRADO -1
/*
 * 
 */
int main(int argc, char** argv) {

    struct Cola cola;
    construir(cola);

    encolar(cola, 5);
    encolar(cola, 15);
    encolar(cola, 10);
    encolar(cola, 20);
    encolar(cola, 1);

    imprimir(cola);
    int n = longitud(cola);
    ordenarCola(cola, n);
    imprimir(cola);

    cout << endl << "ORDENAR POR MERGE: " << endl;

    int arreglo[] = {11, 2, 8, 4}; //arreglo
    n = 4; //longitud del arreglo
    int i;

    for (i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;

    mergeSort(arreglo, 0, n - 1);

    cout << "MERGE SORT: " << endl;
    for (i = 0; i < n; i++)
        cout << arreglo[i] << " ";
    cout << endl;

    int valores[] = {1, 5, 7, 9, 12, 15, 17}; //arreglo
    n = 7; //longitud del arreglo
    int clave = 15; //Número a buscar

    int indice = busquedaBinaria(valores, clave, 0, n - 1);

    if (indice == NOENCONTRADO)
        cout << "No se encontró el elemento" << endl;
    else
        cout << "Se encuentra en la posición " << indice + 1 << endl;

    return 0;
}


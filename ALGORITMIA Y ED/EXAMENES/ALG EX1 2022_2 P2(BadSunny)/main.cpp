/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de septiembre de 2023, 12:30 PM
 */
#include "funcionesPila.h"
#include "Pila.h"
#include <iostream>
using namespace std;

int CalcularFrecuenciaMax(int frecuencias[], int size, int &duracion, double &area) {
    int i = 0, frecMax, frec, indiceFrecMax, duracionActual;
    double areaActual, areaMax = 0;
    Pila ptrPila;
    construir(ptrPila);
    while (i < size || !esPilaVacia(ptrPila)) {
        if (i<size && (esPilaVacia(ptrPila) || frecuencias[cima(ptrPila)] <= frecuencias[i])) {
            apilar(ptrPila, i);
            i++;
        } else {
            indiceFrecMax = desapilar(ptrPila);
            frec = frecuencias[indiceFrecMax];
            if (esPilaVacia(ptrPila)) {
                areaActual = frec*i;
                duracionActual = i;
            } else {
                areaActual = frec * (i - cima(ptrPila)-1);
                duracionActual = i - cima(ptrPila)-1;
            }
            if (areaMax < areaActual) {
                areaMax = areaActual;
                frecMax = frec;
                duracion = duracionActual;
                area = areaMax;
            }
        }
    }
    return frecMax;
}


int main(int argc, char** argv) {
    int Frecuencias[11] = {1, 2, 1, 4, 5, 6, 4, 5, 2, 2, 1};
    int duracion = 0;
    double area;
    cout << "Frecuencia Maxima: " << CalcularFrecuenciaMax(Frecuencias, 11, duracion, area) << endl;
    cout << "Duracion: " << duracion<<endl;
    cout << "Area: " << area<<endl;
    return 0;
}


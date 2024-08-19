/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 6 de septiembre de 2023, 12:48 PM
 */

#include <cstdlib>
#include <iostream>
#include "Lista.h" /*necesitamos incluir a la lista*/
#include "Pila.h"
using namespace std;
#include "funcionesPila.h"

/*
 * NOTACIÓN POSTFIJA USANDO PILAS
 */
int main(int argc, char** argv) {

    // 7 4 -3 * 1 5 + / *   el resultado es -14
    // 3 4 * 2 5 + - 4 * 2 /  el resultados es 10
    struct Pila pila;
    int respuesta;
   
    construir(pila); 
    notacionPostfija(pila);
    /*si hay mas de un elemento al terminar el proceso debe dar un error*/
    respuesta = desapilar(pila);
    if(esPilaVacia(pila))
        cout<<"Respuesta: "<<respuesta;
    else
        cout<<"No hay resultado, la operación no es postfija";
    destruirPila(pila);    
    
    return 0;
}


/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de septiembre de 2023, 10:49 AM
 */
#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"

using namespace std;



int main(int argc, char** argv) {
    
    Lista lista1;
    construir(lista1);
    insertarAlFinal(lista1,13);
    insertarAlFinal(lista1,34);
    insertarAlFinal(lista1,25);
    insertarAlFinal(lista1,55);
    
    imprime(lista1);

    
    return 0;
}


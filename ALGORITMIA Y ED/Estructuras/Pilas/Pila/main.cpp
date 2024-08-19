/* 
 * File:   main.cpp
 * Author: cueva.r
 *
 * Created on 25 de septiembre de 2023, 12:30 PM
 */
#include "funcionesPila.h"
#include "Pila.h"

using namespace std;


int main(int argc, char** argv) {
    
    Pila pila1;
    construir(pila1);
    
    apilar(pila1,20);
    apilar(pila1,15);
    apilar(pila1,10);
    apilar(pila1,5);
    apilar(pila1,2);
    
    imprimir(pila1);
    

    return 0;
}


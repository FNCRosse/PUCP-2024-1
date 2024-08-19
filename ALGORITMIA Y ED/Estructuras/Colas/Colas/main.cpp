/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 07:21 PM
 */

#include <iostream>
#include "Lista.h"
#include "Cola.h"
#include "funcionesCola.h"

using namespace std;



int main(int argc, char** argv) {
    
    Cola cola;
    construir(cola);
    encolar(cola, 8);
    encolar(cola, 21);
    encolar(cola, 10);
    encolar(cola, 15);
    encolar(cola, 7);
    imprime(cola);   

    return 0;
}


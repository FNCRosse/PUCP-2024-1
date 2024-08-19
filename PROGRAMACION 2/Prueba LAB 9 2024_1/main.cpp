/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 9 de julio de 2024, 05:29
 */

#include <iostream>
using namespace std;
#include "Biblioteca.h"

int main(int argc, char** argv) {
    Biblioteca bli;
    bli.Carga();
    bli.Muestra();
    bli.Prueba(8);

    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de marzo de 2024, 10:27
 */

#include <iostream>
using namespace std;
#include "Funciones.h"
#define XMAX 4
#define YMAX 10
#define MAXP 3

int main(int argc, char** argv) {
    char Tablero [XMAX][YMAX];
    char Palabra[MAXP];
    LeerDatos(Tablero,Palabra);
    EncontrarHSO(Tablero,Palabra);
    return 0;
}


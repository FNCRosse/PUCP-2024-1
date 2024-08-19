/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de marzo de 2024, 09:23
 */

#include <iostream>
using namespace std;
#include "Contenedor.h"
#include "Funciones.h"
#define PESOMAX 100
#define NMAX 4

int main(int argc, char** argv) {
    struct Contenedor contenedor[NMAX][NMAX];
    LeerContenedores(contenedor);
    MostrarContenedores(contenedor);
    SolucionMaxValor(contenedor);

    return 0;
}


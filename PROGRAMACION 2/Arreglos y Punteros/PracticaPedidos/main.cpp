/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 11 de abril de 2024, 22:37
 */

#include <iostream>
using namespace std;
#include "Estructuras.h"
#include "Funciones.h"

int main(int argc, char** argv) {
    int *NumPed, *DniPed;
    char ***CodLibrosPedido;
    
    LeerDatos(NumPed, DniPed,CodLibrosPedido);
    mostrar(NumPed,DniPed, CodLibrosPedido);
    return 0;
}


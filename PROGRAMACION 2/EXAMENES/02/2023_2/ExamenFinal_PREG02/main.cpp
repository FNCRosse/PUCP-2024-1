/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 8 de julio de 2024, 11:44
 */

#include <iostream>
using namespace std;
#include "Flota.h"

int main(int argc, char** argv) {
    Flota flota;
    flota.Cargar_Vehiculo();
    flota.Cargar_Pedido();
    flota.Mostrar_Vehiculo();

    return 0;
}


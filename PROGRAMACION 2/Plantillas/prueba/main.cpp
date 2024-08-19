/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 21 de junio de 2024, 04:51
 */

#include <iostream>
using namespace std;
#include "Flota.h"

int main(int argc, char** argv) {
    Flota unidades;
    unidades.CargaFlota();
    unidades.CargaPedidos();
    unidades.MuestraCarga();

    return 0;
}


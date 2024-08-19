/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 12 de junio de 2024, 15:31
 */

#include <iostream>
using namespace std;
#include "Flota.h"

int main(int argc, char** argv) {
    class Flota flota;
    flota.CargaFlota();
    flota.CargaPedidos();
    flota.MuestraCarga();
    return 0;
}


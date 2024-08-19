/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 8 de julio de 2024, 11:44
 */

#include <iostream>
using namespace std;
#include "Programacion.h"

int main(int argc, char** argv) {
    Programacion pro;
    pro.cargaVehiculos();
    pro.CargaProgramacion();
    pro.ReduceVehiculos(120);
    pro.MuestraProgramacion();
    return 0;
}


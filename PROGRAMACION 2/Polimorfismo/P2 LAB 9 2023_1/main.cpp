/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 12 de junio de 2024, 12:22
 */

#include <iostream>
using namespace std;
#include "Tesoreria.h"

int main(int argc, char** argv) {
    class Tesoreria OTeso;
    OTeso.CargaEscalas();
    OTeso.CargaAlumnos();
    OTeso.ActualizarBoleta();
    OTeso.ImprimirBoleta();

    return 0;
}


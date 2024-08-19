/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 12 de junio de 2024, 21:09
 */

#include <iostream>
using namespace std;
#include "Tesoreria.h"

int main(int argc, char** argv) {
    Tesoreria ABoleta;
    ABoleta.CargaAlumnos();
    ABoleta.ActualizarBoleta();
    ABoleta.ImprimeBoleta();
    return 0;
}


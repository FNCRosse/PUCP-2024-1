/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:46
 */

#include <iostream>
using namespace std;
#include "Tesoreria.h"
int main(int argc, char** argv) {
    Tesoreria caja;
    caja.CargarEscalas("escalas.csv");
    caja.CargarAlumnos("Alumnos.csv");
    caja.Actualiza(20);
    caja.Imprime("Reporte.txt");
    

    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 16:08
 */

#include <iostream>
using namespace std;
#include "farmacia.h"

int main(int argc, char** argv) {
    farmacia ofarma;
    ofarma.CargarMedico();
    ofarma.LeeRecetas();
    ofarma.ImprimirRecetas();
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 12:21
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "Pregunta02Examen01PunteroGenericos.h"

int main(int argc, char** argv) {
    void *Productos;
    cargarProductos(Productos,"Productos.csv");
   // pruebaDeCargaDeProductos(Productos);
    OrdenarProductos(Productos);
    pruebaDeCargaDeProductos(Productos);
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 12 de junio de 2024, 08:48
 */

#include <iostream>
using namespace std;
#include "Juego.h"

int main(int argc, char** argv) {
    class Juego juego;
    juego.CargarYMoverFichas("Fichas.txt","Movimientos.txt","Reporte.txt");
    return 0;
}


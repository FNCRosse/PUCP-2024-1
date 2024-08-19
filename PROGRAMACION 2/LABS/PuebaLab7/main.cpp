/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 20:41
 */

#include <iostream>
using namespace std;
#include "Biblioteca.h"
int main(int argc, char** argv) {
    Biblioteca biblioteca;
    biblioteca.CargarLibros();
    biblioteca.CargarEstantes();
    biblioteca.PosicionarLibros();
    biblioteca.MostrarDatos();
    return 0;
}


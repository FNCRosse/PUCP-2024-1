/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 09:23
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "Libro.h"
#include "Estante.h"
#include "Biblioteca.h"

int main(int argc, char** argv) {
 //PARTE 1
//    ifstream archL ("libros.csv");
//    ofstream RepL ("TestLibro.txt");
//    Libro lib;
//    archL>>lib;
//    RepL<<lib;
//
//    ifstream archE ("estantes.csv");
//    ofstream RepE ("TestEstante.txt");
//    Estante est;
//    archE>>est;
//    est+=lib;
//    RepE<<est;
    
//PARTE 2
    Biblioteca biblioteca;
    biblioteca.CargaLibros();
    biblioteca.CargaEstantes();
    biblioteca.PosicionarLibros();
    biblioteca.MostrarDatos();
    
    return 0;
}


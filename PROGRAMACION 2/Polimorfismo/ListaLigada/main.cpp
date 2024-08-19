/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 12 de junio de 2024, 09:42
 */

#include <iostream>
using namespace std;
#include "Lista.h"
#include "Persona.h"

int main(int argc, char** argv) {
    class Lista lista;
    lista.Crear("personal.csv");
    lista.Imprimir("Reporte.txt");
    lista.ImrprimirR("RepRecursivo.txt");
    return 0;
}


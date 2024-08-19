/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de junio de 2024, 11:10
 */

#include <iostream>
using namespace std;
#include "Lista.h"
#include "Persona.h" 

int main(int argc, char** argv) {
    //    class Lista<int> lista;
    //    lista.Crear("datos.txt");
    //    lista.imprimir("ReporteInt.txt");
    //    lista.ImprimeR("ReporteIntREC.txt");

    class Lista<Persona> lista;
    lista.Crear("personal.csv");
    lista.imprimir("ReportePersoanas.txt");
    lista.ImprimeR("ReportePersonasREC.txt");
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de junio de 2024, 10:53
 */

#include <iostream>
using namespace std;
#include "Plantilla.h"
#include "Persona.h"

int main(int argc, char** argv) {
//    class Plantilla<int> CasoInt;
//    CasoInt.SetDato(40);
//    CasoInt.Leer();
//    CasoInt.imprimir();
    class Plantilla<Persona> CasoClases;
    CasoClases.Leer();
    CasoClases.imprimir();
    
    return 0;
}


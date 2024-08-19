/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 26 de marzo de 2024, 16:48
 */

#include <iostream>
using namespace std;
#include "Controles.h"
#include "FuncionesAux.h"

int main(int argc, char** argv) {
    int Presupuesto = 100000, CantControles = 8;
    struct Controles controles[CantControles];
    LeerDatos(controles,CantControles);
    Soluciones(controles,CantControles,Presupuesto);
    

    return 0;
}


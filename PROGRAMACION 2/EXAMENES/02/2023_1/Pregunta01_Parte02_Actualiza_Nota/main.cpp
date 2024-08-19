/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 8 de julio de 2024, 16:49
 */

#include <iostream>
using namespace std;
#include "Facultad.h"

int main(int argc, char** argv) {
    class Facultad facultad;
    facultad.LeerAlumnosNotas("Alumnos-Preg01.csv","Notas-Preg01.csv");
    facultad.ImprimeAlumnosNotas("PruebaAlumnosNotas.txt");
    facultad.ActualizaNota();
    facultad.ImprimeAlumnosNotas("PruebaNotasActualizadas.txt");

    return 0;
}


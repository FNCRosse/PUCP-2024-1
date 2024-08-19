/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 5 de abril de 2024, 15:15
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "Funciones.h"

int main(int argc, char** argv) {
    char** Codigos;
    char** Nombres;
    char*** Cursos;
    
    LeerDatos("Alumnos-Cursos.csv",Codigos,Nombres,Cursos);
    MostrarDatos(Codigos,Nombres,Cursos);
    
    return 0;
}


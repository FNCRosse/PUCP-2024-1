/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 17:39
 */

#include <iostream>
using namespace std;
#include "Preg1_Funciones_de_cursos_y_alumnos.h"

int main(int argc, char** argv) {
    char ***Cursos,***Alumnos_nom_mod;
    double *Cursos_cred, escalas[5];
    int *alumnos_cod,**alumnos;
    cargasCursosYEscalas (Cursos,Cursos_cred,escalas,"Cursos.csv","Escalas.csv");
    pruebaDeCargaDeCursos(Cursos,Cursos_cred,"PruebaCursos.txt");
    
    CargaAlumnos(alumnos_cod,alumnos,Alumnos_nom_mod,"Alumnos.csv");
    pruebaDeCargaAlumnos(alumnos_cod,alumnos,Alumnos_nom_mod,"PruebaAlumnos.txt");
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de abril de 2024, 22:28
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "Estructuras.h"
#include "FuncionesAux.h"

int main(int argc, char** argv) {
    StCurso ArrCursos[10];
    StAlumno ArrAlumnos[80];
    
    LeerCursos(ArrCursos,"Cursos.txt");
    LeerAlumnos(ArrAlumnos,"Alumnos.txt");
    AsignacionMatricula(ArrCursos,ArrAlumnos,"Matricula.txt");
    ImprimirReportes(ArrCursos,ArrAlumnos,"Reporte_Cliente.txt","Reporte_Cursos.txt");
    return 0;
}


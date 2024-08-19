/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Joshua Haro
 *
 * Created on May 16, 2023, 8:28 AM
 */

#include <cstdlib>
#include <iostream>
#include "arbolBinario.h"
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int mejorNota, aprobados=0, desaprobados=0;
    ABB alumnos;
    NodoCurso *punteroCurso;
    construir(&alumnos);
    registrarAlumno(&alumnos,"Juan");
    registrarAlumno(&alumnos,"David");
    registrarAlumno(&alumnos,"Elmer");
    registrarAlumno(&alumnos,"Elmer");
    registrarAlumno(&alumnos,"Carlos");
    registrarAlumno(&alumnos,"Maria");
    registrarNota(&alumnos, "Carlos", 15, "EDPM");
    registrarNota(&alumnos, "Carlos", 20, "ALGOR");
    registrarNota(&alumnos, "Carlos", 18, "LP1");
    registrarNota(&alumnos, "Juan", 15, "EDPM");
    registrarNota(&alumnos, "Elmer", 20, "EDPM");
    registrarNota(&alumnos, "Maria", 9, "EDPM");
    registrarNota(&alumnos, "David", 10, "EDPM");
    mostrarNotasCurso(alumnos.raiz);
    mejorNota=obtenerCursoMejorNota(alumnos.raiz,"Carlos");
    cout<<"La mejor nota del alumno es: "<< mejorNota<<endl;
    //aprobadosDesaprobados(alumnos.raiz,"EDPM", &aprobados,&desaprobados);
    cout<<"Los alumnos aprobados en el curso de EDPM son "<<aprobados<<" y los"
            "desaprobados son "<<desaprobados;
    return 0;
}


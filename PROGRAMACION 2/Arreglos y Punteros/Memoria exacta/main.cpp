/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 10 de abril de 2024, 08:52
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "funcionesAux.h"

int main(int argc, char** argv) {
    //PARA UN SOLO ARCHIVO
    //20196975,Hijar Pairazaman Jenny Delicia,INF239,FIS248,MEC270,INF245,MEC286
    int *codigo; //array de codigos;
    char** nombres; // array de cadena de caracteres
    char*** cursos; // array de array de cadena de caracteres
    LeerAlumnos_Cursos(codigo,nombres,cursos,"Alumnos-Cursos.csv");
    MostrarAlumnos_Cursos(codigo,nombres,cursos,"ReporteAC.txt");

    //PARA DOS ARCHIVOS
    //20196975,Hijar Pairazaman Jenny Delicia
    //20187490,MAT219
    int *codigos2;
    char **nombres2;
    char ***Cursos2;
    LeerDatosAlumnos(codigos2,nombres2,"Alumnos.csv");
    LeerDatosCursos(codigos2,Cursos2,"Cursos.csv");
    MostrarAlumnos_Cursos(codigos2,nombres2,Cursos2,"Reporte2Archivos.txt");
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 11 de abril de 2024, 20:22
 */

#include <iostream>
using namespace std;
#include "MetodoDinamicoExacto.h"

int main(int argc, char** argv) {
    char **alumno_nombre,**curso_Nombre,*alumno_Modalidad;
    int *alumno_Codigo, *alumno_porcentaje,*alumno_escala;
    int **curso_Alumnos;
    double *curso_credito;
    
    LecturaAlumnos("alumnos.csv",alumno_Codigo,alumno_nombre,alumno_Modalidad,alumno_porcentaje,
            alumno_escala);
    PruebaLecturaAlumnos("ReporteAlumnos.txt",alumno_Codigo,alumno_nombre,alumno_Modalidad,
            alumno_porcentaje,alumno_escala);
    
    LecturaCursos("alumnos_cursos.csv",alumno_Codigo,alumno_escala,curso_Nombre,curso_credito,
            curso_Alumnos);
    PruebaLecturaCursos("ReporteCursos.txt",curso_Nombre,curso_credito,curso_Alumnos);
    
    ReporteDeRecaudacionPorModalidad("ReporteRecaudacionModalidad.txt",alumno_Codigo,alumno_Modalidad,
            alumno_porcentaje,alumno_nombre,curso_Nombre,curso_credito,curso_Alumnos);
    
    return 0;
}


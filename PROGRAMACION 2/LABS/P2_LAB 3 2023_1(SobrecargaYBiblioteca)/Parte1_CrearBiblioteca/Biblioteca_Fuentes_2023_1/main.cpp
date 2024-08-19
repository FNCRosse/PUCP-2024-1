/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de abril de 2024, 11:18
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "SobreCarga.h"

int main(int argc, char** argv) {
    ifstream archC ("Cursos.txt");
    ifstream archA ("Alumnos.txt");
    ifstream archRM ("Matricula.txt");
    ofstream archR("Prueba.txt");
    
    StCurso Arrcurso[10], curso;
    StAlumno ArrAlumno[10],alumno;
    StRegistroDeMatricula RegMat;
    
    strcpy(Arrcurso[0].codigoDelCurso,"XXXXXX");
    ArrAlumno[0].semestre =0;
    
    for (int i = 0; i < 10; i++) {
        if (!(archC >> curso)) break;
        Arrcurso += curso;
    }

    for (int i = 0; i < 10; i++) {
        if (!(archA >> alumno)) break;
        ArrAlumno += alumno;
    }

    archRM>>RegMat;
    Arrcurso *= RegMat;
    ArrAlumno *= RegMat;
    
    archRM>>RegMat;
    Arrcurso *= RegMat;
    ArrAlumno *= RegMat;
    
    for(int i=0; strcmp(Arrcurso[i].codigoDelCurso, "XXXXXX")!=0;i++){
        archR<<Arrcurso[i];
        archR<<endl;
    }
    for(int i=0; ArrAlumno[i].semestre != 0;i++){
        archR<<ArrAlumno[i];
        archR<<endl;
    }

    return 0;
}


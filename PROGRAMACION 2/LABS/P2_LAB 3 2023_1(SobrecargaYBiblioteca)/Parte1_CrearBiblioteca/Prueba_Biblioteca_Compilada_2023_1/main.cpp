/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de abril de 2024, 11:19
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "SobreCarga.h"


int main(int argc, char** argv) {
    ifstream archC, archA, archRM;
    ofstream archRep;
    AperturaDeUnArchivoDeTextosParaLeer(archC,"Cursos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archA,"Alumnos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archRM,"Matricula.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archRep,"Pruebas.txt");
    
    StCurso curso, ArrCurso[20];
    StAlumno alumno, ArrAlumno[20];
    StRegistroDeMatricula RegMat;
    
    strcpy(ArrCurso[0].codigoDelCurso,"XXXXXX");
    ArrAlumno[0].semestre = 0;
    
    for (int i = 0; i < 20; i++) {
        if (!(archC >> curso)) break;
        ArrCurso += curso;
    }

    for (int i = 0; i < 20; i++) {
        if (!(archA >> alumno)) break;
        ArrAlumno += alumno;
    }

    archRM>>RegMat;
    ArrCurso *= RegMat;
    ArrAlumno *= RegMat;
    
    archRM>>RegMat;
    ArrCurso *= RegMat;
    ArrAlumno *= RegMat;
    
    for(int i=0; strcmp(ArrCurso[i].codigoDelCurso, "XXXXXX")!=0;i++){
        archRep<<ArrCurso[i];
        archRep<<endl;
    }
    for(int i=0; ArrAlumno[i].semestre != 0;i++){
        archRep<<ArrAlumno[i];
        archRep<<endl;
    }

    return 0;
}


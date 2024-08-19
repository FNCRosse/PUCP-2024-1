/* 
 * File:   FuncionesAux.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de abril de 2024, 22:30
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "SobreCarga.h"

void LeerCursos(struct StCurso *ArrCursos, const char* namefile){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    strcpy(ArrCursos[0].codigoDelCurso,"XXXXXX");
    StCurso curso;
    while(true){
        if ( !(arch>>curso)) break;
        ArrCursos += curso;
    }
    arch.close();
}
void LeerAlumnos(struct StAlumno * ArrAlumnos, const char* namefile){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    ArrAlumnos[0].semestre = 0;
    StAlumno alumno;
    while(true){
        if ( !(arch>>alumno)) break;
        ArrAlumnos += alumno;
    }
    arch.close();
}

void AsignacionMatricula(struct StCurso * ArrCursos, struct StAlumno * ArrAlumno, const char* namefile){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,namefile);
    StRegistroDeMatricula RegMat;
    while(true){
        arch>>RegMat;
         if ( arch.eof()) break;
         ArrCursos *= RegMat;
         ArrAlumno *= RegMat;
    }
    arch.close();
}

void ImprimirReportes(const struct StCurso * ArrCursos, const struct StAlumno * ArrAlumno,
                                    const char* RepAlumnoName,const char* RepCursosName){
    ofstream ArchA, ArchCur;
    AperturaDeUnArchivoDeTextosParaEscribir(ArchA,RepAlumnoName);
    AperturaDeUnArchivoDeTextosParaEscribir(ArchCur,RepCursosName);
    for(int i=0; strcmp(ArrCursos[i].codigoDelCurso, "XXXXXX")!=0;i++){
        ArchCur<<ArrCursos[i];
        ArchCur<<endl;
    }
    for(int i=0; ArrAlumno[i].semestre != 0;i++){
        ArchA<<ArrAlumno[i];
        ArchA<<endl;
    }
    ArchA.close();
    ArchCur.close();
}
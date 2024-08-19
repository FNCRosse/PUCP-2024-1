/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Facultad.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 17:17
 */

#include "Facultad.h"
#include "Alumno.h"

void Facultad::LeerAlumnosNotas(const char* namefile1,const char* namefile2) {
    ifstream archA (namefile1);
    ifstream archN (namefile2);
    Alumno datoA;
    while(true){
        if(archA>>datoA) break;
        alumnosxNotas.insertarAlumno(datoA);
    }
    int ciclo,codAlumno;
    while(true){
        archN>>ciclo;
        if(archN.eof()) break;
        archN.get();
        archN>>codAlumno;
        archN.get();
        alumnosxNotas.insertarNotas(ciclo,codAlumno,archN);
    }
    
}

void Facultad::ImprimeAlumnosNotas(const char* namefile) {
    ofstream archA (namefile);
    alumnosxNotas.Imprimir(archA);
}
void  Facultad::ActualizaNota(){
    alumnosxNotas.ActualizarCalificaciones();
}
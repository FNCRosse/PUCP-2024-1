/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   AlumnoNotas.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 16:56
 */

#include "AlumnoNotas.h"

AlumnoNotas::AlumnoNotas(){
    notas = vector<class Nota>();
}

void AlumnoNotas::SetNotas(ifstream &arch,int ciclo) {
    class Nota nota;
    while(true){
        arch>>nota;
        nota.SetCiclo(ciclo);
        nota.SetVez(1);
        notas.push_back(nota);
        if(arch.get() == '\n') break;
    }
}

vector<Nota> AlumnoNotas::GetNotas() const {
    return notas;
}

void AlumnoNotas::SetAlumno(Alumno alumno) {
    this->alumno = alumno;
}

Alumno AlumnoNotas::GetAlumno() const {
    return alumno;
}
int AlumnoNotas::GetCodigo(){
    return alumno.GetCodigo_alumno();
}

void AlumnoNotas::Imprimir(ofstream &arch){
    alumno.ImprimeAlumno(arch);
    for(class Nota n:notas){
        n.imprimir(arch);
    }
    arch<<endl;
}

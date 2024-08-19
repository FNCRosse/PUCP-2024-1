/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Nota.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 16:52
 */

#include "Nota.h"

Nota::Nota(){
    vez =0;
}
void operator >> (ifstream &arch, class Nota &n){
    string codCurso;
    double cred;
    int nota;
    getline(arch,codCurso,',');
    arch>>cred;
    arch.get();
    arch>>nota;
    n.SetCodigo_curso(codCurso);
    n.SetCredito(cred);
    n.SetCalificacion(nota);
}
void Nota::imprimir(ofstream &arch){
    arch<<left<<setw(5)<<" "<<setw(8)<<ciclo<<setw(12)<<codigo_curso<<setw(8)<<credito<<calificacion<<endl;
}
bool Nota::operator<(const Nota &other) const {
    if (codigo_curso == other.GetCodigo_curso()) {
        return ciclo > other.GetCiclo(); // Ciclos mayores primero
    }
    return codigo_curso < other.GetCodigo_curso(); // Menor primero para ordenar alfabeticamente
}
void Nota::SetVez(int vez) {
    this->vez = vez;
}

int Nota::GetVez() const {
    return vez;
}

void Nota::SetCalificacion(int calificacion) {
    this->calificacion = calificacion;
}

int Nota::GetCalificacion() const {
    return calificacion;
}

void Nota::SetCredito(double credito) {
    this->credito = credito;
}

double Nota::GetCredito() const {
    return credito;
}

void Nota::SetCodigo_curso(string codigo_curso) {
    this->codigo_curso = codigo_curso;
}

string Nota::GetCodigo_curso() const {
    return codigo_curso;
}

void Nota::SetCiclo(int ciclo) {
    this->ciclo = ciclo;
}

int Nota::GetCiclo() const {
    return ciclo;
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 21:16
 */
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
#include "Biblioteca.h"

Biblioteca::Biblioteca(){
    cant_Lib_Edu=0;
    cant_Lib_Psi=0;
    cant_est_Cole=0;
    cant_est_Psi=0;
}
void Biblioteca::CargarLibros(){
    ifstream arch("libros.csv");
    char Tipo[30];
    while(true){
        arch.getline(Tipo,30,',');
        if(arch.eof()) break;
        if(strcmp(Tipo,"Educativo")==0){
            librosEdu[cant_Lib_Edu].Leer(arch);
            cant_Lib_Edu++;
        } else if (strcmp(Tipo,"Motivacional")==0){
            librosPsico[cant_Lib_Psi].Leer(arch);
            cant_Lib_Psi++;
        }
    }
}
void Biblioteca::CargarEstantes(){
    ifstream arch("estantes.csv");
    char Tipo[30];
    while(true){
        arch.getline(Tipo,30,',');
        if(arch.eof()) break;
        if(strcmp(Tipo,"Colegio")==0){
            estantesCole[cant_est_Cole].Leer(arch);
            cant_est_Cole++;
        } else if (strcmp(Tipo,"Psicologo")==0){
            estantesPsico[cant_est_Psi].Leer(arch);
            cant_est_Psi++;
        }
    }
}
void Biblioteca::PosicionarLibros(){
    for(int i=0;i<cant_Lib_Edu;i++){
        for(int k=0;k<cant_est_Cole;k++){
            if(estantesCole[k].AgregarLibro(librosEdu[i])) break;
        }
    }
    for(int i=0;i<cant_Lib_Psi;i++){
        for(int k=0;k<cant_est_Psi;k++){
            if(estantesPsico[k].AgregarLibro(librosPsico[i])) break;
        }
    }
}
void Biblioteca::MostrarDatos(){
    ofstream arch("ReporteFinal.txt");
    arch<<"ESTANTERIAS DEL COLEGIO"<<endl;
    for(int i=0;i<cant_est_Cole;i++){
        estantesCole[i].Imprimir(arch);
        arch<<endl;
    }
    arch<<endl<<endl;
    arch<<"ESTANTERIAS DE PSICOLOGIA"<<endl;
    for(int i=0;i<cant_est_Psi;i++){
        estantesPsico[i].Imprimir(arch);
        arch<<endl;
    }
}
void Biblioteca::SetCant_est_Psi(int cant_est_Psi) {
    this->cant_est_Psi = cant_est_Psi;
}

int Biblioteca::GetCant_est_Psi() const {
    return cant_est_Psi;
}

void Biblioteca::SetCant_est_Cole(int cant_est_Cole) {
    this->cant_est_Cole = cant_est_Cole;
}

int Biblioteca::GetCant_est_Cole() const {
    return cant_est_Cole;
}

void Biblioteca::SetCant_Lib_Psi(int cant_Lib_Psi) {
    this->cant_Lib_Psi = cant_Lib_Psi;
}

int Biblioteca::GetCant_Lib_Psi() const {
    return cant_Lib_Psi;
}

void Biblioteca::SetCant_Lib_Edu(int cant_Lib_Edu) {
    this->cant_Lib_Edu = cant_Lib_Edu;
}

int Biblioteca::GetCant_Lib_Edu() const {
    return cant_Lib_Edu;
}
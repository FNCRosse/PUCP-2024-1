/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 21:29
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::CargaAlumnos() {
    ifstream arch ("Alumnos.csv");
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        aboleta.Asignar(tipo,arch);
    }
}

void Tesoreria::ImprimeBoleta() {
    ofstream arch ("ReporteAlumno.txt");
    arch.precision(2);
    arch<<fixed;
    aboleta.ImprimirEnOrden(arch);
}
void Tesoreria::ActualizarBoleta(){
    ifstream arch ("escalas.csv");
    aboleta.LeerEscalas(arch);
    aboleta.ActualizarBoleta();
}
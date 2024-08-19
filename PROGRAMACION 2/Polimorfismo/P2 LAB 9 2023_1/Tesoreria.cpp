/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 12:37
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::CargaEscalas() {
    ifstream arch("escalas.csv");
    int cod;
    double costo;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        arch>>costo;
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(costo);
    }
}

void Tesoreria::CargaAlumnos() {
    ifstream arch("Alumnos.csv");
    char tipo;
    int nd=0;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        lboleta[nd].AsignarAlumno(tipo,arch);
        nd++;
    }
}

void Tesoreria::ImprimirBoleta() {
    ofstream arch("Reporte.txt");
    arch.precision(2);
    arch<<fixed;
    for(int i=0;lboleta[i].ExisteBoleta();i++){
        lboleta[i].ImprimirDatos(arch);
    }
}

void Tesoreria::ActualizarBoleta(){
    for(int i=0;lboleta[i].ExisteBoleta();i++){
        int escala = lboleta[i].GetEscala();
        int precio = lescala[escala-1].GetPrecio();
        lboleta[i].ActualizarDatos(precio);
    }
}
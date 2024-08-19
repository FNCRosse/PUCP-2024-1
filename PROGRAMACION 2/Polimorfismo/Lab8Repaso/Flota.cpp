/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Rosse
 * 
 * Created on 13 de junio de 2024, 20:49
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Flota.h"

void Flota::CargaFlota() {
    ifstream arch ("Vehiculos.csv");
    char tipo;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        lista.AsignarVehiculo(tipo,arch);
    }
}

void Flota::MuestraCarga() {
    ofstream arch ("Reporte1.txt");
    arch.precision(2);
    arch.fixed;
    lista.ImprimirFlota(arch);
}

void Flota::CargaPedidos() {

}
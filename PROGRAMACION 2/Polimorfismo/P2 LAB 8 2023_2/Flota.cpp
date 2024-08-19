/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Flota.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 15:49
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
        lista.Asignar(tipo,arch);
    }
}

void Flota::CargaPedidos() {
    ifstream arch ("Pedidos3.csv");
    lista.ColocarPedidos(arch);
}

void Flota::MuestraCarga() {
    ofstream arch("ReporteCarga.txt");
    lista.Imprimir(arch);
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NodoLista.cpp
 * Author: Rosse
 * 
 * Created on 13 de junio de 2024, 20:46
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "NodoLista.h"
#include "Vehiculo.h"
#include "Furgon.h"
#include "Camion.h"

NodoLista::NodoLista(char tipo){
    sig = nullptr;
    switch(tipo){
        case 'F':
            unidad = new class Furgon;
            break;
        case 'C':
            unidad = new class Camion;
            break;
    }
}
void NodoLista::Imprimir(ofstream&arch){
    unidad->imprime(arch);
}
void NodoLista::Leer(ifstream&arch){
    unidad->lee(arch);
}
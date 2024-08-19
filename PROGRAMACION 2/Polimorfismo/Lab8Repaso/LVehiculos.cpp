/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   LVehiculos.cpp
 * Author: Rosse
 * 
 * Created on 13 de junio de 2024, 20:48
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "LVehiculos.h"
#include "NodoLista.h"

LVehiculos::LVehiculos(){
    lfin = nullptr;
    lini = nullptr;
}
void LVehiculos::AsignarVehiculo(char tipo,ifstream &arch){
    NodoLista *nuevoNodo = new class NodoLista(tipo);
    nuevoNodo->Leer(arch);
    Insertar(nuevoNodo);
}
void LVehiculos::Insertar(class NodoLista *&nuevoNodo){
    if(lini == nullptr){
        lini = nuevoNodo;
        lfin = nuevoNodo;
    } else {
        lfin->sig = nuevoNodo;
        lfin = nuevoNodo;
    }
}
void LVehiculos::ImprimirFlota(ofstream&arch){
    NodoLista *recorrer = lini;
    while(recorrer){
        recorrer->Imprimir(arch);
        recorrer = recorrer->sig;
    }
}
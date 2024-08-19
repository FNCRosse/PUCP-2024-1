/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 21:25
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Nodo.h"

Nodo::Nodo() {
    der = nullptr;
    izq = nullptr;
}

void Nodo::LeerDatos(ifstream &arch) {
    dboleta.LeerDatos(arch);
}

void Nodo::MostrarDatos(ofstream &arch) {
    dboleta.MostrarDatos(arch);
}
void Nodo::ActualizaPrecio(class Escala *lescala){
    dboleta.ActualizaPrecio(lescala);
}
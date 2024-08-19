/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NVehiculo.cpp
 * Author: Rosse
 * 
 * Created on 20 de junio de 2024, 14:57
 */
#include "Util.h"
#include "NVehiculo.h"
#include "Fugon.h"
#include "Camion.h"

NVehiculo::NVehiculo() {
    unidad = nullptr;
}

void NVehiculo::leer(ifstream &arch,char tipo) {
    switch(tipo){
        case 'F':
            unidad = new class Fugon;
            break;
        case 'C':
            unidad =  new class Camion;
            break;
    }
    unidad->leer(arch);
}

void NVehiculo::imprime(ofstream &arch) {
    unidad->imprime(arch);
}


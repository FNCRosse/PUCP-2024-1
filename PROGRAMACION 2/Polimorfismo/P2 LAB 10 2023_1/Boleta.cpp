/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Boleta.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 21:23
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
#include "Escala.h"
void Boleta::AsignarMemoria(char tipo){
    switch(tipo){
        case 'S':
            pboleta  = new class Semipresencial;
            break;
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;
    }
}
void Boleta::LeerDatos(ifstream &arch) {
    pboleta->leer(arch);
}

void Boleta::MostrarDatos(ofstream &arch) {
    pboleta->imprime(arch);
}
int Boleta::getCodigo(){
    return pboleta->GetCodigo();
}
void Boleta::ActualizaPrecio(class Escala *lescala){
    int esc = pboleta->GetEscala();
    double precio = lescala[esc-1].GetPrecio();
    pboleta->Actualiza(precio);
}
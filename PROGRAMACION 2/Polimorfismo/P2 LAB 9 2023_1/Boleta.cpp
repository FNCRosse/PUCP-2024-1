/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Boleta.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 12:35
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"
Boleta::Boleta(){
    pboleta = nullptr;
}
Boleta::~Boleta(){
    if(pboleta != nullptr) delete pboleta;
}
void Boleta::AsignarAlumno(char tipo, ifstream &arch){
    switch(tipo){
        case 'S':
            pboleta = new class Semipresencial;
            break;
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;
    }
    pboleta->leer(arch);
}
bool Boleta::ExisteBoleta(){
    if(pboleta == nullptr) return false;
    else return true;
}
void Boleta::ImprimirDatos(ofstream &arch){
    pboleta->imprimir(arch);
}
int Boleta::GetEscala(){
    return pboleta->GetEscala();
}
 void Boleta::ActualizarDatos(int precio){
     pboleta->actualizar(precio);
 }
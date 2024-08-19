/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NodoLista.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 15:45
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "NodoLista.h"
#include "Camion.h"
#include "Furgon.h"

NodoLista::NodoLista(char tipo){
    sig =nullptr;
    switch(tipo){
        case 'F':
            unidad = new class Furgon;
            break;
        case 'C':
            unidad = new class Camion;
            break;
    }
}
void NodoLista::LeerDatos(ifstream &arch){
    unidad->lee(arch);
}
void NodoLista::ImprimirDatos(ofstream &arch){
    unidad->imprime(arch);
}
void NodoLista::InsertarPedido(class NPedido &nodoPed){
    unidad->Push(nodoPed);
}
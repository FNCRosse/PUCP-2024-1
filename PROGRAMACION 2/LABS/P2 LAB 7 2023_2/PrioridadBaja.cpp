/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PrioridadBaja.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 15:43
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "PrioridadBaja.h"

PrioridadBaja::PrioridadBaja(){
    
}

void PrioridadBaja::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadBaja::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadBaja::SetDias_espera(int dias_espera) {
    this->dias_espera = dias_espera;
}

int PrioridadBaja::GetDias_espera() const {
    return dias_espera;
}
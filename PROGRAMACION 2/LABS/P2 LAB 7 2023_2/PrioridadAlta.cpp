/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   PrioridadAlta.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 15:37
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "PrioridadAlta.h"

PrioridadAlta::PrioridadAlta(){
    
}

void PrioridadAlta::SetTotal(double total) {
    this->total = total;
}

double PrioridadAlta::GetTotal() const {
    return total;
}

void PrioridadAlta::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double PrioridadAlta::GetRecargo() const {
    return recargo;
}

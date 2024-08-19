/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   A.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 08:49
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Ficha.h"
#include "A.h"

void A::imprime(ofstream &arch){
    char identidad[10];
    GetID(identidad);
    arch<<"Tipo A: "<<left<<setw(5)<<identidad<<right<<setw(5)<<GetFila()<<setw(5)<<GetCol()<<endl;
    
}
void A::mover(char mov, int cant){
    switch(mov){
        case 'P': //Arriba
            SetFila(GetFila()-cant);
            break;
        case 'Q':
            SetCol(GetCol()+cant);
            break;
        case 'R':
            SetFila(GetFila()+cant);
            break;
        case 'S':
            SetCol(GetCol()-cant);
            break;
    }
}
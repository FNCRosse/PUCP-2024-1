/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   C.cpp
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
#include "C.h"

void C::imprime(ofstream &arch){
    char identidad[10];
    GetID(identidad);
    arch<<"Tipo C: "<<left<<setw(5)<<identidad<<right<<setw(5)<<GetFila()<<setw(5)<<GetCol()<<endl;
    
}
void C::mover(char mov, int cant){
    switch(mov){
        case 'P': //Arriba
            SetFila(GetFila()-2);
            SetCol(GetCol()+1);
            break;
        case 'Q':
            SetFila(GetFila()+1);
            SetCol(GetCol()+2);
            break;
        case 'R':
            SetFila(GetFila()+2);
            SetCol(GetCol()-1);
            break;
        case 'S':
            SetFila(GetFila()-1);
            SetCol(GetCol()-2);
            break;
    }
}

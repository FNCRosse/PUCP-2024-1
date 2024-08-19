/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Juego.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 09:23
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Juego.h"

void Juego::CargarYMoverFichas(const char*filenameFichas, const char*filenameMov,const char*filenameRep){
    ifstream archF(filenameFichas,ios::in);
    ifstream archM(filenameMov,ios::in);
    ofstream archR(filenameRep,ios::out);
    tablero.leerFichas(archF);
    archR<<"Posiciones inicales de las fichas:"<<endl;
    tablero.imprimirDatos(archR);
    archR<<endl<<endl;
    tablero.leerMovimiento(archM);
    archR<<"Posiciones Finales:"<<endl;
    tablero.imprimirDatos(archR);
}
/*
 * ClickFun nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: USER
 *
 * Created on 6 de octubre de 2023, 11:06 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    int fechaSolicitada;
    
    ingresoDeFecha(fechaSolicitada);
    emitirReporte(fechaSolicitada,"funciones.txt","peliculas.txt","salas.txt",
            "ventas_y_ocupacion.txt","reporte.txt");
    
    return 0;
}


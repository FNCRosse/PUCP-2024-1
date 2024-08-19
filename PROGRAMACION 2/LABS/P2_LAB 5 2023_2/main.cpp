/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de mayo de 2024, 19:50
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "ListaConRegistro.h"
#include "ListaConEntero.h"
#include "FlotaGenerica.h"

int main(int argc, char** argv) {
    int numCamiones;
    double PesoMaximo;
    void *Flota;
    
    numCamiones =5,PesoMaximo = 10;
    CargaCamiones(Flota,numCamiones,PesoMaximo,LeeNumero,CalcularNumero,"numeros.txt");
    qsort(Flota,numCamiones,sizeof(void*),cmpNumero);
    MuestraCamiones(Flota,numCamiones,imprimeNumero,"ReporteNum.txt");
    
    numCamiones =100,PesoMaximo = 400;
    CargaCamiones(Flota,numCamiones,PesoMaximo,LeeRegistro,CalcularRegistro,"pedidos3.csv");
    qsort(Flota,numCamiones,sizeof(void*),cmpRegistro);
    MuestraCamiones(Flota,numCamiones,imprimeRegistro,"ReporteRegistro.txt");

    return 0;
}


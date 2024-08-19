/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de abril de 2024, 19:49
 */

#include <iostream>
using namespace std;
#include "Funciones.h"

int main(int argc, char** argv) {
    void *Lista;
    
    CrearLista("personal.csv",Lista,leeReg,regSueldoCMP);
    ImprimirLista(Lista,ImprimeReg);
    EliminarLista(Lista,EliminaReg);

    return 0;
}


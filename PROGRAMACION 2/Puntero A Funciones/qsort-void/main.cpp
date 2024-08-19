/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de abril de 2024, 18:06
 */

#include <iostream>
using namespace std;
#include "Funciones.h"

int main(int argc, char** argv) {
    void *Personal;
    int nd;
    
    LeerDatos(Personal,nd,"personal.csv");
//    qsort (Personal,nd,sizeof(void*),voidCMPSueldo);
//    qsort (Personal,nd,sizeof(void*),voidCMPCodigo);
    qsort (Personal,nd,sizeof(void*),voidCMPNombres);
    ImprimirDatos(Personal,nd);
    
    return 0;
}


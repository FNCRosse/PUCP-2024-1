/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de abril de 2024, 19:04
 */

#include <iostream>
using namespace std;
#include "Funciones.h"

int main(int argc, char** argv) {
    void *Personal;
    int nd;
    
    LeerDatos(Personal,nd,"personal.csv");
//    OrdenarGenerico(Personal,0,nd-1,voidCMPSueldo);
//    OrdenarGenerico(Personal,0,nd-1,voidCMPCodigo);
    OrdenarGenerico(Personal,0,nd-1,voidCMPNombres);
    ImprimirDatos(Personal,nd);
    return 0;
}


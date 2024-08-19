/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 26 de marzo de 2024, 19:15
 */

#include <iostream>
using namespace std;
#include "Funciones.h"
#define MAXC 5
#define MAXP 10

int main(int argc, char** argv) {
    int CantCamiones,CantPaquetes;
    int ArrCamiones[MAXC];
    int ArrPaquetes[MAXP];
    
    LeerDatos(ArrCamiones,ArrPaquetes,CantCamiones,CantPaquetes);
    //En este caso como son 3 camiones, tenemos que cambiar de base, en vez de 2 a 3
    multiplesCamiones(CantCamiones,CantPaquetes,ArrCamiones,ArrPaquetes);
    

    return 0;
}


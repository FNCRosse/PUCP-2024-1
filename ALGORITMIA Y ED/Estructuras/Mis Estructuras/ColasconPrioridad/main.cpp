/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 15:19
 */

#include <iostream>
using namespace std;
#include "Cola.h"
#include "FuncionesCola.h"
#define MAXD 6
int main(int argc, char** argv) {
    struct Cola cola;
    construir(cola);
    struct Cliente ArrClientes[MAXD] ={{1,{'0','1','2'}},
                                                            {2,{'1','4','4'}},
                                                            {2,{'4','6','2'}},
                                                            {2,{'2','7','4'}},
                                                            {1,{'5','8','5'}},
                                                            {1,{'2','3','2'}},};
    for(int i=0;i<MAXD;i++){
        encolarConPrioridad(cola,ArrClientes[i]);
    }
    imprime(cola);
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de junio de 2024, 11:10
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include "GrafoLista.h"

int main(int argc, char** argv) {
    GrafoLista grafoL(4);
    
    grafoL.AgregarArista(1,2);
    grafoL.AgregarArista(1,3);
    grafoL.AgregarArista(2,3);
    
    grafoL.imprimirGrafo();

    return 0;
}


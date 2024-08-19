/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 2 de mayo de 2024, 12:35 PM
 */

#include <iostream>

using namespace std;
#include "funciones.h"

/*
 * 
 */
int main(int argc, char** argv) {

    int arreglo[] = {0, 0, 0, 0, 0, 1, 1, 1};
    
    
    int n = 8;

    cout << "CUENTA UNOS: " << cuentaUnos(arreglo, 0, n - 1, 0) << endl;

    cout << "CUENTA CEROS: " << cuentaCeros(arreglo, 0, n - 1, 0) << endl;

    int arreglo2[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    n = 11;
    buscaSolo(arreglo2, 0, n - 1);
        
    int arreglo3[] = {12, 24, 32, 12, 11, 10};
    n = 6;
    cout << "BUSCA MAX: " << buscaMax(arreglo3, 0, n - 1);

    return 0;
}


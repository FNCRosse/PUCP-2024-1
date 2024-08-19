/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:28 AM
 */

#include <cstdlib>
#include <iostream>
#include "Lista.h" /*necesitamos incluir a la lista*/
#include "Pila.h"
using namespace std;
#include "funcionesPila.h"
#include "funcionesLaberinto.h"
/*
 *Laberinto usando PILAS 
 */
int main(int argc, char** argv) {
    
    struct Pila pila;
    
    construir(pila);
    int tablero[3][5] = {{1, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1},
                         {0, 0, 1, 0, 1}};
    bool terminado;
    
    mostrar(tablero);
    terminado = laberinto(pila, tablero, 0, 0);
    if(terminado)
        mostrar(tablero);
    else
        cout<<"No fue posible terminar el laberinto";
    destruirPila(pila);
    return 0;
}


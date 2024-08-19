/* 
 * File:   funcionesPosicion.cpp
 * Author: ANA RONCAL
 * Created on 5 de septiembre de 2023, 09:10 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Posicion.h"
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
using namespace std;

#include "funcionesPosicion.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
#include "funcionesLaberinto.h"

void constructor(struct Posicion & posicion, int x, int y){
    
    posicion.x = x;
    posicion.y = y;
            
}

int getX(struct Posicion posicion){
    return posicion.x;
}

int getY(struct Posicion posicion){
    return posicion.y;
}



/* 
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 18 de abril de 2024, 10:28 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;


/*constructor de Cola*/
void construir(struct Cola & cola) {
    construir(cola.lista);
}

bool esColaVacia(const struct Cola & cola) {
    return esListaVacia(cola.lista);
}

void encolarConPrioridad(struct Cola & cola, const struct Cliente & cliente){
    insertarConPrioridad(cola.lista, cliente);
}

void imprimir(const struct Cola & cola) {
    imprimir(cola.lista);
}





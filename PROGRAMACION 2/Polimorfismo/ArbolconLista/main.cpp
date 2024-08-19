/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 12 de junio de 2024, 12:01
 */

#include <iostream>
using namespace std;
#include "Arbol.h"

int main(int argc, char** argv) {
    class Arbol arbol;
    arbol.Crear("datos.txt");
    arbol.MostrarEnOrden();
    cout<<"El dato buscado: "<<arbol.buscar(1)<<endl;

    return 0;
}


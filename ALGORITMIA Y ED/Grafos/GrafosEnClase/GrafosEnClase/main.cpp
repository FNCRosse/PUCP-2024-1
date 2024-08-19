/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 20 de junio de 2024, 12:44
 */

#include <iostream>
#include "Grafo.h"
using namespace std;
#include "funcionesGrafo.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    struct Grafo grafo;
    
    //Construir el Grafo
    construirGrafo(grafo);

    //Agregar los vértices
    agregarVertice(grafo, 'A');
    agregarVertice(grafo, 'B');
    agregarVertice(grafo, 'C');
    agregarVertice(grafo, 'D');
    
    agregarArista(grafo, 'A', 'B'); 
    agregarArista(grafo, 'A', 'C'); 
    agregarArista(grafo, 'B', 'A'); 
    agregarArista(grafo, 'B', 'D'); 
    mostrarVerticeYAristas(grafo);
    
    
    return 0;
}


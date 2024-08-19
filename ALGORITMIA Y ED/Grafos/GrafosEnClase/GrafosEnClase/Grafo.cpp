/* 
 * File:   Grafo.cpp
 * Author: Ana Roncal
 * 
 * Created on 20 de junio de 2024, 12:54
 */


#include <iostream>
#include <iomanip>
#include "Grafo.h"

using namespace std;
#include "funcionesVertice.h"
#include "funcionesGrafo.h"


void construirGrafo(struct Grafo & grafo){
    construirListaVertice(grafo.listaVertice);
    grafo.longitud = 0;
}
bool seEncuentraVertice(const struct Grafo & grafo, int elemento){
    return seEncuentraVerticeLista(grafo.listaVertice, elemento);
}

void agregarVertice(struct Grafo & grafo, char elemento){
    if(not seEncuentraVertice(grafo, elemento)){
        insertarVerticeAlFinal(grafo.listaVertice, elemento);
        grafo.longitud++;
    }
}

void eliminarVertice(struct Grafo & grafo, char vertice){
    if(seEncuentraVertice(grafo, vertice)){
        eliminarVerticeEnLista(grafo.listaVertice, vertice);
        grafo.longitud--;
    }
}

void eliminarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino){
   bool seEncuentraVerticeO = seEncuentraVertice(grafo, verticeOrigen);
   if(seEncuentraVerticeO)
       eliminarDeListaDeAristas(grafo.listaVertice, verticeOrigen, verticeDestino);
}

void mostrarVerticeYAristas(const struct Grafo & grafo){
    struct NodoVertice * recorridoG = new struct NodoVertice;
    struct NodoArista * recorridoA = new struct NodoArista;
    recorridoG = grafo.listaVertice.cabeza;
    
    if (recorridoG == nullptr){
        cout<<"No se puede mostrar, el grafo está vacío"<<endl;
        return;
    }
    else{
        while(recorridoG != nullptr){
            cout<<left<<setw(2)<<recorridoG->elemento<<":";
            recorridoA = recorridoG->listaArista.cabeza;
            while(recorridoA != nullptr){
                cout<<' '<<recorridoA->elemento<<' ';
                recorridoA = recorridoA->siguiente; 
            }
            recorridoG = recorridoG->siguiente; 
            cout<<endl;
        }
        delete recorridoG;
    }
}

bool seEncuentraArista(struct Grafo grafo, char verticeOrigen, char verticeDestino){
    return seEncuentraAristaLista(grafo.listaVertice, verticeOrigen, verticeDestino);
}

void agregarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino){
    bool seEncuentraVerticeOrigen = seEncuentraVertice(grafo, verticeOrigen);
    bool seEncuentraVerticeDestino = seEncuentraVertice(grafo, verticeDestino);
    if((not seEncuentraVerticeOrigen) or (not seEncuentraVerticeDestino)){
        cout<<"No se ha encontrado algún vértice";
        return;
    }
  
    if(not seEncuentraArista(grafo, verticeOrigen, verticeDestino)){
        insertarListaAristas(grafo.listaVertice, verticeOrigen, verticeDestino);
    }
}

void destruirGrafo(struct Grafo & grafo){
    destruirListaVertice(grafo.listaVertice);
    grafo.longitud = 0;
}
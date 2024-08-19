/* 
 * File:   funcionesVertice.cpp
 * Author: Ana Roncal
 * 
 * Created on 20 de junio de 2024, 13:02
 */

#include <iostream>
#include "Vertice.h"
using namespace std;
#include "funcionesVertice.h"
#include "funcionesArista.h"

void construirListaVertice(struct Vertice & listaVertice){
    listaVertice.cabeza = nullptr;
    listaVertice.longitud = 0;
}

bool seEncuentraAristaLista(struct Vertice listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen == nullptr)
	return false;
    return seEncuentraAristaEnListaArista(nodoVerticeOrigen->listaArista, verticeDestino);
}

bool seEncuentraVerticeLista(struct Vertice listaVertice, char llave){
    struct NodoVertice * recorrido = listaVertice.cabeza;
    while(recorrido != nullptr and recorrido->elemento != llave){        
        recorrido = recorrido->siguiente;
    }
    return recorrido != nullptr; 
}

void insertarVerticeAlFinal(struct Vertice & listaVertice, char elemento){
    struct NodoVertice * ultimoNodo = obtenerUltimoNodoV(listaVertice);
    struct NodoVertice * nuevoNodo = crearNodoV(elemento, nullptr);
   
    if (ultimoNodo == nullptr)  /*Si la lista está vacia*/
        listaVertice.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
    else    //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
    listaVertice.longitud++;
}

struct NodoVertice * obtenerUltimoNodoV( struct Vertice  listaVertice){
    struct NodoVertice * ultimo = nullptr;
    struct NodoVertice * recorrido = listaVertice.cabeza;
    
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

struct NodoVertice * crearNodoV(char elemento, struct NodoVertice * siguiente){
    struct NodoVertice * nuevoNodo = new struct NodoVertice;
    
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    construirListaAristas(nuevoNodo->listaArista);
    return nuevoNodo;
}

void insertarListaAristas(struct Vertice & listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen == nullptr){
        cout<<"Error al insertar la lista de arista. No se ha encontrado el vértice"<<verticeOrigen<<endl;
        return;
    }

    if ( not seEncuentraAristaEnListaArista(nodoVerticeOrigen->listaArista, verticeDestino)){
        insertarAristaAlFinal(nodoVerticeOrigen->listaArista, verticeDestino);
    }
}

struct NodoVertice * obtenerNodoVertice(struct Vertice listaVertice, char clave){
    struct NodoVertice * recorrido = listaVertice.cabeza;
    while((recorrido != nullptr) and (recorrido->elemento != clave)){        
        recorrido = recorrido->siguiente;
    }
    return recorrido;        
}

void eliminarDeListaDeAristas(struct Vertice & listaVertice, char verticeOrigen, char verticeDestino){
    struct NodoVertice * nodoVerticeOrigen = obtenerNodoVertice(listaVertice, verticeOrigen);
    if (nodoVerticeOrigen != nullptr)
        eliminarAristaEnLista(nodoVerticeOrigen->listaArista, verticeDestino);

}

void eliminarVerticeEnLista(struct Vertice & listaVertice, char vertice){
    struct NodoVertice * ultimoNodo = nullptr;
    struct NodoVertice * recorrido = listaVertice.cabeza;

    while(recorrido != nullptr and recorrido->elemento != vertice){
        ultimoNodo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    if (recorrido != nullptr){
        if (ultimoNodo == nullptr)
            listaVertice.cabeza=recorrido->siguiente;
        else    
            ultimoNodo->siguiente = recorrido->siguiente;
        destruirListaArista(recorrido->listaArista);
        delete recorrido;
        listaVertice.longitud--;
    }
}


void destruirListaVertice(struct Vertice & listaVertice){    
    
    struct NodoVertice * recorrido = listaVertice.cabeza;
    while(recorrido != nullptr){
    	destruirListaArista(recorrido->listaArista);
        struct NodoVertice * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    listaVertice.cabeza = nullptr;
    listaVertice.longitud = 0;
    
}

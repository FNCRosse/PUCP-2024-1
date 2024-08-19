/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:32 AM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "NodoArbol.h"
#include "ListaP.h"
using namespace std;
#include "funcionesListaP.h"
#include "funcionesArbolesBinarios.h"
#include "Nodo.h"
#include "ListaP.h"

/*Valores iniciales de la lista*/
void construirP(struct Lista & tad){
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVaciaP(struct Lista  tad){
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitudP( struct Lista tad){
    return tad.longitud;
}

struct NodoArbol * retornaCabezaP(struct Lista tad){
    if (esListaVaciaP(tad)){
        cout<<"No existe la cabeza por que la cola está vacía"<<endl;
        exit(1);
    }
    return tad.cabeza->nodo;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, struct NodoArbol * nodo){
  
    /*Crea un nuevo nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo = crearNodoP(nodo, tad.cabeza);
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parÃ¡metros*/
struct Nodo * crearNodoP(struct NodoArbol * nodo, struct Nodo * siguiente){
    
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->nodo = nodo;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}


void eliminaCabezaP(struct Lista  & lista){
    struct Nodo * nodoEliminar = lista.cabeza;
    if (nodoEliminar == nullptr ){
        cout<<"No se puede eliminar la cabeza pues la lista estÃ¡ vacÃ­a";
        exit(1);
    }
    else{
        lista.cabeza = lista.cabeza->siguiente;
        delete nodoEliminar;
        lista.longitud--;
    }
}

void destruir(struct Lista & tad){
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;
    
    while(recorrido != nullptr){
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;        
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimeP( struct Lista  tad){

    if (esListaVaciaP(tad)){
        cout<<"La Pila está vacía"<<endl;
    }
    else{
        
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";

        while(recorrido != nullptr){
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout<<", ";
            estaImprimiendoLaCabeza = 0;
            imprimeNodo(recorrido->nodo);    
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}


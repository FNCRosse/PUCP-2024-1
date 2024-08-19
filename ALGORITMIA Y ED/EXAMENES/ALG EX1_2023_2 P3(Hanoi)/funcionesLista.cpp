/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:32 AM
 */

#include <iostream>
#include "Nodo.h"
#include "Lista.h"
using namespace std;
#include "funcionesLista.h"

/*Valores iniciales de la lista*/
void construir(struct Lista & tad){
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia(const struct Lista & tad){
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista & tad){
    return tad.longitud;
}

int retornaCabeza(struct Lista tad){
    return tad.cabeza->elemento;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, int elemento){
  
    /*Crea un nuevo nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo = crearNodo(elemento, tad.cabeza);
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parÃ¡metros*/
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente){
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}


void eliminaCabeza(struct Lista  & tad){
    struct Nodo * nodoAEliminar = tad.cabeza;
    if (nodoAEliminar != nullptr){
        tad.cabeza = tad.cabeza->siguiente;
        delete nodoAEliminar; 
        tad.longitud--;      
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
void imprime(const struct Lista & tad){

    if (esListaVacia(tad)){
        cout<<"La lista está vacía"<<endl;
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
            cout<<recorrido->elemento;        
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}


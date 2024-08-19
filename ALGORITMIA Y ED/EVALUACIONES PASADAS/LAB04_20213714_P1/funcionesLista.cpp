/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "NodoArbol.h"
#include "Lista.h"
using namespace std;
#include "funcionesLista.h"
#include "funcionesArbolesBinarios.h"
#include "Nodo.h"
#include "Lista.h"


/*Valores iniciales de la lista*/
void construir(struct Lista & lista){
    lista.cabeza = nullptr;
    lista.cola = nullptr;
    lista.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia( struct Lista  lista){
    return lista.cabeza == nullptr;
}

/*DEVUELVE LA CANTIDAD DE ELEMENTOS DE LA LISTA*/
int longitud(struct Lista tad ){
    return tad.longitud;
}

/*CREA UN NUEVO ELEMENTO CON VALORES INICIALES*/
struct Nodo * crearNodo(struct NodoArbol * nodo, struct Nodo * siguiente){

    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->nodo = nodo;
    nuevoNodo->siguiente = siguiente; 
    return nuevoNodo;
}

/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA*/
void insertarAlFinal(struct Lista & lista, struct NodoArbol * nodo){
   
    struct Nodo * nuevoNodo = crearNodo(nodo, nullptr);
    Nodo * ultimoNodo = lista.cola; /*obtiene el último nodo*/
    if (ultimoNodo == nullptr){
        lista.cabeza = nuevoNodo;
        lista.cola = nuevoNodo;
    }
    else{
        ultimoNodo->siguiente = nuevoNodo;
        lista.cola = nuevoNodo;
    }            
    lista.longitud++;  
}

struct NodoArbol * retornaCabeza( struct Lista  lista){
    if (esListaVacia(lista)){
        cout<<"No existe la cabeza por que la cola está vacía"<<endl;
        exit(1);
    }
   
    return lista.cabeza->nodo;
}

/*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
void eliminaCabeza(struct Lista  & lista){
    struct Nodo * nodoEliminar = lista.cabeza;
    if (nodoEliminar == nullptr ){
        cout<<"No se puede eliminar la cabeza pues la lista estÃ¡ vacÃ­a";
        exit(1);
    }
    else{
        lista.cabeza = lista.cabeza->siguiente;
        if(lista.cabeza == nullptr)
            lista.cola = nullptr;
        delete nodoEliminar;
        lista.longitud--;
    }
}

/*LIBERA LA MEMORIA*/
void destruirLista(struct Lista & tad){
    struct Nodo * recorrido = tad.cabeza;
    struct Nodo * eliminarNodo;
    
    while(recorrido != nullptr){
        eliminarNodo = recorrido;        
        recorrido = recorrido->siguiente;
        delete eliminarNodo;
    }
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

void imprime(struct Lista lista){
       
    if (esListaVacia(lista)){
        cout<<"La cola esta vacía"<<endl;
    }
    else{
        struct Nodo * recorrido = lista.cabeza;
        while(recorrido != nullptr){
            imprimeNodo(recorrido->nodo);
            recorrido = recorrido->siguiente;
        }   
    }
    cout<<endl;
}

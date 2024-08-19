/* 
 * File:   FuncionesLista.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 19:51
 */
#include <iostream>
using namespace std;
#include "Estructuras.h"
#include "FuncionesLista.h"

void construir (struct Lista &tad){
    tad.Cabeza = nullptr;
    tad.cola= nullptr;
    tad.longitud=0;
}
void insertarEnOrden(struct Lista &tad, struct Pedido pedido){
    struct Nodo* NodoAnterior = ObtenerNodoAnterior(tad, pedido);
    struct Nodo* NuevoNodo = CrearNodo(pedido, nullptr);
    if ( NodoAnterior == nullptr){
        NuevoNodo->sig = tad.Cabeza;
        tad.Cabeza = NuevoNodo;
        if(tad.Cabeza->sig == nullptr) tad.cola = NuevoNodo;
    } else {
        NuevoNodo->sig = NodoAnterior->sig;
        NodoAnterior->sig = NuevoNodo;
        if(NuevoNodo->sig ==nullptr) tad.cola = NuevoNodo;
    }
    tad.longitud++;
}
void InsertarFinal(struct Lista &tad, struct Pedido pedido){
    struct Nodo* UltimoNodo = ObtenerUltimoNodo(tad);
    struct Nodo* NuevoNodo = CrearNodo(pedido, nullptr);
    if(UltimoNodo == nullptr){
        tad.Cabeza = NuevoNodo;
        
    }else {
        UltimoNodo->sig = NuevoNodo;
        tad.cola = NuevoNodo;
    }
    tad.longitud++;
}
struct Nodo* ObtenerUltimoNodo(struct Lista &tad){
    struct Nodo* Ultimo = nullptr;
    struct Nodo* recorrer = tad.Cabeza;
    while(recorrer!= nullptr){
        Ultimo = recorrer;
        recorrer = recorrer->sig;
    }
    return Ultimo;
}
struct Nodo* ObtenerNodoAnterior(struct Lista &tad,struct Pedido pedido){
    struct Nodo* Anterior = nullptr;
    struct Nodo* recorrido = tad.Cabeza;
    while((recorrido !=  nullptr) and (recorrido->elem.hora < pedido.hora)){
        Anterior = recorrido;
        recorrido = recorrido->sig;
    }
    return Anterior;
}
struct Nodo* CrearNodo(struct Pedido pedido,struct Nodo* sig){
    struct Nodo* nuevoNodo = new struct Nodo;
    nuevoNodo->elem = pedido;
    nuevoNodo->sig = sig;
    return nuevoNodo;
}
void Imprimir (const struct Lista &tad){
    if( tad.Cabeza == nullptr){
        cout<<"Lista esta vacia"<<endl; return;
    }
    struct Nodo * recorrer = tad.Cabeza;
    int n =tad.longitud,i=0;
    while(recorrer != nullptr){
        cout<<recorrer->elem.hora<<"("<<recorrer->elem.sucursal<<")";
        if(i<n-1) cout<<" ->  ";
        i++;
        recorrer = recorrer->sig;
    }
    cout <<endl;
}
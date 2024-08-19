/* 
 * File:   funcionesListaS.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 14:44
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "Pila.h"
#include "funcionesListaS.h"

///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct Lista &tad){
    tad.Cabeza = nullptr;
    tad.Longitud =0;
}
bool ListaEstaVacia(const struct Lista &tad){
    return tad.Cabeza == nullptr;
}
int LongitudLista(const struct Lista &tad){
    return tad.Longitud;
}

/////////////////////////////////////////////////////////////////////// INSERTAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void InsertarInicio(struct Lista &tad,int elem){
    struct Nodo* nuevoNodo = CrearNodo(elem, tad.Cabeza);
    tad.Cabeza = nuevoNodo;
    tad.Longitud++;
}
void InsertarInicioPorArchivo(struct Lista &tad,const char *namefile){
    ifstream arch (namefile,ios::in);
    int num;
    while(true){
        arch>>num;
        if(arch.eof()) break;
        InsertarInicio(tad,num);
    }
}

struct Nodo* ObtenerUltimoNodo(const Lista &tad){
    struct Nodo* ultimo = nullptr;
    struct Nodo* recorrido = tad.Cabeza;
    while(recorrido !=  nullptr){
        ultimo = recorrido;
        recorrido = recorrido->sig;
    }
    return ultimo;
}
struct Nodo* CrearNodo(int elem,struct Nodo *sig){
    struct Nodo* nuevoNodo = new struct Nodo;
    nuevoNodo->elem = elem;
    nuevoNodo->sig = nullptr;
    return nuevoNodo;
}
struct Nodo* EncontrarNodo(const struct Lista &tad, int  elem){
    struct Nodo* recorrer = tad.Cabeza;
    while((recorrer != nullptr) and (recorrer->elem !=  elem )){
        recorrer = recorrer->sig;
    }
    return recorrer;
}
/////////////////////////////////////////////////////////////////////// ELIMINAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void EliminarCabeza(struct Lista&tad){
    struct Nodo* nodoEliminar = tad.Cabeza;
    if(nodoEliminar != nullptr){
        tad.Cabeza = tad.Cabeza->sig;
        delete nodoEliminar;
        tad.Longitud--;
    }
}

/////////////////////////////////////////////////////////////////////// DESTRUIR LISTA S ///////////////////////////////////////////////////////////////////////
void Destruir(struct Lista &tad){
    struct Nodo* recorrer = tad.Cabeza;
    while(recorrer !=  nullptr){
        struct Nodo * Eliminar = recorrer;
        recorrer = recorrer->sig;
        delete Eliminar;
    }
    tad.Cabeza=nullptr;
    tad.Longitud=0;
}

/////////////////////////////////////////////////////////////////////// MOSTRAR LISTA S ///////////////////////////////////////////////////////////////////////
void mostrar(const struct Lista &tad){
    if (ListaEstaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    }
    struct Nodo* Recorrer = tad.Cabeza;
    while(Recorrer != nullptr){
        cout<<Recorrer->elem<<"  ";
        Recorrer = Recorrer->sig;
    }
}
int retornarCabeza(const struct Lista &tad){
    return tad.Cabeza->elem;
}
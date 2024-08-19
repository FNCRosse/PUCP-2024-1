/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:11 PM
 */

#include <iostream>
#include <iomanip> /*formato de números*/
#include <fstream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

/*Valores iniciales de la lista*/
void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
    tad.cola = nullptr;
    tad.colaMay = nullptr;
    tad.colaMen = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & tad) {
    return tad.longitud;
}

/*inserta un nodo siempre al final de la cola*/
void insertarencola(struct Lista & tad, struct Paciente elemento) {
//
//    struct Nodo * ultimoNodo = tad.cola;
//    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
//
//    if (ultimoNodo == nullptr){/*Si la lista está vacia*/
//        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
//        tad.cola = nuevoNodo;
//    } 
//    else{ //La lista ya tiene nodos
//        ultimoNodo->siguiente = nuevoNodo;
//        tad.cola = nuevoNodo;
//    }
//    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(struct Paciente elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}


int retornaCabeza(const struct Lista & tad){
    return tad.cabeza->elemento.fecha;
}



void eliminaCabeza(struct Lista & tad) {
    struct Nodo * nodoAEliminar = tad.cabeza;
    if (nodoAEliminar != nullptr) {
        tad.cabeza = tad.cabeza->siguiente;
        delete nodoAEliminar;
        tad.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            tad.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        tad.longitud--;
    }
}

void destruir(struct Lista & tad) {
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            ImprimirFecha(recorrido);
            cout <<" "<<recorrido->elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}
void ImprimirFecha(struct Nodo *recorrido){
    int dia,mes, anio;
    int fecha = recorrido->elemento.fecha;
    anio = fecha/10000;
    fecha = fecha%10000;
    mes = fecha/100;
    fecha = fecha%100;
    dia = fecha;
    cout<<dia<<"/"<<mes<<"/"<<anio;
}
int obtenerEdad(struct Nodo* paciente){
    //dia de hoy;
    int diaHoy = 20240427;
    return diaHoy - paciente->elemento.fecha;
}
void InsetarConPrioridad(struct Lista &tad,struct Paciente paciente){
    struct Nodo* NuevoNodo = crearNodo(paciente,nullptr);
    int edadNuevo = obtenerEdad(NuevoNodo);
    if(esListaVacia(tad)){
        tad.cabeza = NuevoNodo;
        if(edadNuevo>800000) tad.colaMay = NuevoNodo;
        if(edadNuevo<100000) tad.colaMen = NuevoNodo;
        tad.cola = NuevoNodo;
    } else {
        if(edadNuevo>800000){ // Para mayores de 80
            if(tad.colaMay != nullptr){
                NuevoNodo->siguiente = tad.colaMay->siguiente;
                tad.colaMay->siguiente = NuevoNodo;
                tad.colaMay = NuevoNodo;
                if(tad.colaMay->siguiente == nullptr) tad.cola = NuevoNodo;
            } else {
                NuevoNodo->siguiente = tad.cabeza;
                tad.cabeza = NuevoNodo;
                tad.colaMay = NuevoNodo;
            }
        }
        else if (edadNuevo<100000){ // Para menores de 10 años
            if (tad.colaMen != nullptr){
                NuevoNodo->siguiente = tad.colaMen->siguiente;
                tad.colaMen->siguiente = NuevoNodo;
                tad.colaMen = NuevoNodo;
                if(tad.colaMen->siguiente == nullptr) tad.cola = NuevoNodo;
            }else{
                if(tad.colaMay != nullptr){
                    NuevoNodo->siguiente = tad.colaMay->siguiente;
                    tad.colaMay->siguiente = NuevoNodo;
                    tad.colaMen = NuevoNodo;
                    if(tad.colaMen->siguiente == nullptr) tad.cola = NuevoNodo;
                } else{
                    NuevoNodo->siguiente = tad.cabeza;
                    tad.cabeza = NuevoNodo;
                    tad.colaMen = NuevoNodo;
                }
            }
        } 
        else {//Los demas simplemente insierto al final
            tad.cola->siguiente=NuevoNodo;
            tad.cola = NuevoNodo;
        }
    }
    tad.longitud++;
}
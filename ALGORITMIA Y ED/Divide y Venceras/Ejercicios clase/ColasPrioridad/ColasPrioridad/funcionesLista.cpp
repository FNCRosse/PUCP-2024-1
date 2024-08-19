/* 
 * File:   funcionesLista.cpp
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
void construir(struct Lista & lista) {
    lista.cabeza = nullptr;
    lista.colaVIP = nullptr;
    lista.cola = nullptr; //puntero cola a null
    lista.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & lista) {
    return lista.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista & lista) {
    return lista.longitud;
}


void insertarConPrioridad(struct Lista & lista, const struct Cliente & cliente) {

    struct Nodo * nuevoNodo = crearNodo(cliente, nullptr);
    if (esListaVacia(lista)) {
        lista.cabeza = nuevoNodo;
        lista.cola = nuevoNodo;
        if(cliente.prioridad == 1) //solo si es uno
            lista.colaVIP = nuevoNodo;
    } 
    else{ 
        if(cliente.prioridad == 1){
            if(lista.colaVIP != nullptr){ //Solo hay VIP en cola
                nuevoNodo->siguiente=lista.colaVIP->siguiente;
                lista.colaVIP->siguiente = nuevoNodo;
                lista.colaVIP = nuevoNodo;  
                if(lista.colaVIP->siguiente == nullptr) //esta al final
                    lista.cola = nuevoNodo;
            }
            else{ //se inserta un tipo VIP a la cabeza
                nuevoNodo->siguiente = lista.cabeza;
                lista.cabeza = nuevoNodo;
                lista.colaVIP = nuevoNodo;
            }
        }
        else{
            lista.cola->siguiente = nuevoNodo;
            lista.cola = nuevoNodo;        
        }
    }
    lista.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(const struct Cliente & cliente, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->cliente = cliente;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía




struct Cliente retornaCabeza(const struct Lista & lista) {
    return lista.cabeza->cliente;
}


void eliminaCabeza(struct Lista & lista) {
    struct Nodo * nodoAEliminar = lista.cabeza;
    if (nodoAEliminar != nullptr) {
        lista.cabeza = lista.cabeza->siguiente;
        if (lista.cabeza == nullptr) /*falta añadir para que coloque*/
            lista.cola = nullptr; /*cola en null*/
        delete nodoAEliminar;
        lista.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista lista) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            lista.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        lista.longitud--;
    }
}

void destruir(struct Lista & lista) {
    /*recorrido apunta al inicio del lista*/
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    lista.cabeza = nullptr;
    lista.cola = nullptr;
    lista.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo lista.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & lista) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(lista)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = lista.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            //cout << recorrido->elemento;
            cout << recorrido->cliente.prioridad << " ";
            cout << recorrido->cliente.dni;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}
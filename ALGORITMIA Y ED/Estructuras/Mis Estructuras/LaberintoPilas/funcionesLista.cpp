/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:32 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Posicion.h"
#include "Nodo.h"
#include "Lista.h"
using namespace std;
#include "funcionesLista.h"
#include "Posicion.h"

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

struct Posicion retornaCabeza(const struct Lista & tad){
    return tad.cabeza->posicion;
}
/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & tad, struct Posicion elemento){
  
    /*Crea un nuevo nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->posicion = elemento;
    nuevoNodo->siguiente = tad.cabeza;
    
    tad.cabeza = nuevoNodo;
    tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parÃ¡metros*/
struct Nodo * crearNodo(struct Posicion elemento, struct Nodo * siguiente){
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->posicion.x = elemento.x;
    nuevoNodo->posicion.y = elemento.y;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta funciÃ³n retorna nulo cuando la lista es vacÃ­a
/*Obtiene el Ãºltimo nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & tad){
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = tad.cabeza;
    
    while(recorrido != nullptr){
        ultimo = recorrido;        
        recorrido = recorrido->siguiente;
    }
    return ultimo;
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

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/
/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad){
    cout<<fixed;   
    cout<<setprecision(2); 
    if (esListaVacia(tad)){
        cout<<"La lista estÃ¡ vacÃ­a"<<endl;
    }
    else{
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout<<"[";

        while(recorrido != nullptr){
            /*Este artificio coloca la primera coma despuÃ©s de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout<<", ";
            estaImprimiendoLaCabeza = 0;
            cout<<recorrido->posicion.x;        
            recorrido = recorrido->siguiente;
        }
        cout<<"]"<<endl;
    }
}
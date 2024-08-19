/* 
 * File:   FuncionesListas.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 15:31
 */
#include <iostream>
using namespace std;
#include "Cola.h"
#include "FuncionesListas.h"
/*Valores iniciales de la lista*/

void construir(struct Lista & lista){
    lista.cabeza = nullptr;
    lista.colaNor = nullptr;
    lista.colaVip = nullptr;
    lista.Longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
bool esListaVacia(const struct Lista & lista){
    return lista.cabeza == nullptr;
}

/*DEVUELVE LA CANTIDAD DE ELEMENTOS DE LA LISTA*/
int longitud(struct Lista tad ){
    return tad.Longitud;
}

/*CREA UN NUEVO ELEMENTO CON VALORES INICIALES*/
struct Nodo * crearNodo(struct Cliente cliente, struct Nodo * siguiente){

    struct Nodo * nuevoNodo = new struct Nodo;
    
    nuevoNodo->cliente = cliente;
    nuevoNodo->sig = siguiente; 
    return nuevoNodo;
}


/*INSERTA UN ELEMENTO AL FINAL DE LA LISTA*/
void insertarAlFinal(struct Lista & lista, struct Cliente cliente){
    struct Nodo * nuevoNodo = crearNodo(cliente, nullptr);
    Nodo * ultimoNodo = lista.colaNor; /*obtiene el Ãºltimo nodo*/
    if (ultimoNodo == nullptr){
        lista.cabeza = nuevoNodo;
        lista.colaNor = nuevoNodo;
    }
    else{
        ultimoNodo->sig = nuevoNodo;
        lista.colaNor = nuevoNodo;
    }            
    lista.Longitud++;  
}

int retornaCabeza(const struct Lista & lista){
    if (esListaVacia(lista)){
        cout<<"No existe la cabeza por que la cola estÃ¡ vacÃ­a"<<endl;
        exit(1);
    }
    return lista.cabeza->cliente.prioridad;
}

/*ELIMINA EL PRIMER ELEMENTO DE LA LISTA*/
void eliminaCabeza(struct Lista  & lista){
    struct Nodo * nodoEliminar = lista.cabeza;
    if (nodoEliminar == nullptr ){
        cout<<"No se puede eliminar la cabeza pues la lista estÃƒÂ¡ vacÃƒÂ­a";
        exit(1);
    }
    else{
        lista.cabeza = lista.cabeza->sig;
        if(lista.cabeza == nullptr)
            lista.colaNor = nullptr;
        delete nodoEliminar;
        lista.Longitud--;
    }
}

/*LIBERA LA MEMORIA*/
void destruirLista(struct Lista & tad){
    struct Nodo * recorrido = tad.cabeza;
    struct Nodo * eliminarNodo;
    
    while(recorrido != nullptr){
        eliminarNodo = recorrido;        
        recorrido = recorrido->sig;
        delete eliminarNodo;
    }
    tad.cabeza = nullptr;
    tad.colaNor = nullptr;
    tad.colaVip = nullptr;
    tad.Longitud = 0;
}

void imprime(const struct Lista & lista){
       
    if (esListaVacia(lista)){
        cout<<"La cola esta vacÃ­a"<<endl;
    }
    else{
        struct Nodo * recorrido = lista.cabeza;
        while(recorrido != nullptr){
            cout<<recorrido->cliente.prioridad<<" ";
            cout<<recorrido->cliente.dni[0]<<recorrido->cliente.dni[1]<<recorrido->cliente.dni[2]<<endl;
            recorrido = recorrido->sig;
        }   
    }
    cout<<endl;
}

void InsertarConPrioridad(struct Lista &lista, const struct Cliente cliente){
    struct Nodo* NuevoNodo = crearNodo(cliente,nullptr);
    if(esListaVacia(lista)){
        lista.cabeza = NuevoNodo;
        if(NuevoNodo->cliente.prioridad ==1 ) lista.colaVip = NuevoNodo;
        lista.colaNor = NuevoNodo;
    } else {
        if(cliente.prioridad == 1){
            if(lista.colaVip != nullptr){
                NuevoNodo->sig = lista.colaVip->sig;
                lista.colaVip->sig = NuevoNodo;
                lista.colaVip = NuevoNodo;
                if(lista.colaVip->sig == nullptr) lista.colaNor =NuevoNodo;
            } else {
                NuevoNodo->sig = lista.cabeza;
                lista.cabeza = NuevoNodo;
                lista.colaVip = NuevoNodo;
            }
        } else {
            lista.colaNor->sig = NuevoNodo;
            lista.colaNor = NuevoNodo;
        }
    }
    lista.Longitud++;
}
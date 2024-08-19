/* 
 * File:   FuncionesPila.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 15:03
 */
#include <iostream>
using namespace std;
#include "Pila.h"
#include "funcionesListaS.h"
#include "FuncionesPila.h"

///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct Pila &pila){
    Construir(pila.lista);
}
bool PilaEstaVacia(const struct Pila &pila){
    return ListaEstaVacia(pila.lista);
}
int LongitudPila(const struct Pila &pila){
    return LongitudLista(pila.lista);
}

//////////////////////////////////////////////////////////////////   OPERACIONES DE PILA  ///////////////////////////////////////////////////////////////////////
void Apilar (struct Pila &pila, int elem){
    InsertarInicio(pila.lista,elem);
}
int Desapilar (struct Pila &pila){
    if(PilaEstaVacia(pila)){
        cout<<"La pila esta vacia, por lo tanto no se puede desapilar"<<endl;
        return -1;
    } else {
        int elemento = cima(pila);
        EliminarCabeza(pila.lista);
        return elemento;
    }
}
int cima (const struct Pila & pila){
    if(PilaEstaVacia(pila)){
        cout<<"La pila esta vacia, por lo tanto no se puede desapilar"<<endl;
        return -1;
    } else {
        retornarCabeza(pila.lista);
    }
}
void DestruirPila(struct Pila &pila){
    Destruir(pila.lista);
}
void MostrarPila(const struct Pila &pila){
    if(PilaEstaVacia(pila)){
        cout<<"La pila está vacía no se puede mostrar"<<endl;
    }
    else{
        mostrar(pila.lista);
    }
}

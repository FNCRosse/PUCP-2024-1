/* 
 * File:   ColaGenerica.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 14:43
 */
#include <iostream>
using namespace std;
#include "ColaGenerica.h"
enum RegCola {CABEZA,COLA,TAMN};
enum RegNodo {DATO,SIG};

void GeneraCola(void* &Cola){
    void **Aux = new  void* [3]{};
    int *cant =new int;
    *cant = 0;
    Aux[CABEZA] = nullptr;
    Aux[COLA] = nullptr;
    Aux[TAMN] = cant;
    Cola = Aux;
}
void Encola(void *Cola, void*Dato){
    void ** Aux =(void **)Cola;
    void **Nodo = new void *[2]{};
    Nodo[DATO] = Dato;
    if(ColaVacia(Aux[CABEZA])){
        Aux[CABEZA] = Nodo;
        Aux[COLA] = Nodo;
        Nodo[SIG] = nullptr;
    }else{
        void **Ultimo = (void **) Aux[COLA];
        Ultimo[SIG] = Nodo;
        Nodo[SIG] = nullptr;
        Aux[COLA] = Nodo;
    }
    int* cant = (int *)Aux[TAMN];
    *cant++;
    Aux[TAMN] = cant;
}
void* Desencola(void *Cola){
    void **Aux = (void**)Cola;
    void **Eliminar = (void**)Aux[CABEZA];
    Aux[CABEZA] = Eliminar[SIG];
    int* cant = (int *)Aux[TAMN];
    *cant--;
    Aux[TAMN] = cant;
    return Eliminar;
}
bool ColaVacia(void *Cola){
    if(Cola == nullptr) return true;
    else return false;
}
/* 
 * File:   ColaGenerica.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 07:38
 */
#include <iostream>
using namespace std;
#include "ColaGenerica.h"
enum RegCola {CABEZA,COLA,TOTAL};
enum RegNodo {DATO,SIG};
void GeneraCola(void *&Cola){
    void **AuxCola = new void*[3]{};
    int *Total =new int;
    *Total =0;
    AuxCola[CABEZA] = nullptr;
    AuxCola[COLA] = nullptr;
    AuxCola[TOTAL] = Total;
    Cola = AuxCola;
}
void Encola(void* Cola, void* Dato){
    void **AuxCola = (void **)Cola;
    void **Nodo = new void *[2]{};
    Nodo[DATO] = Dato;
    if(ColaVacia(AuxCola[CABEZA])){
        AuxCola[CABEZA] = Nodo;
        AuxCola[COLA] = Nodo;
        Nodo[SIG] = nullptr;
    } else {
        void ** Ultimo = (void **)AuxCola[COLA];
        Ultimo[SIG] = Nodo;
        Nodo[SIG] = nullptr;
        AuxCola[COLA] = Nodo;
    }
    int * Total = (int *)AuxCola[TOTAL];
    *Total++;
    AuxCola[TOTAL] = Total;
}
void * Desencola (void* Cola){
    void **AuxCola = (void **)Cola;
    void **Eliminar = (void **)AuxCola[CABEZA];
    AuxCola[CABEZA] = Eliminar[SIG];
    int * Total = (int *)AuxCola[TOTAL];
    *Total--;
    AuxCola[TOTAL] = Total;
    return Eliminar;
}
bool ColaVacia(void* Cola){
    if(Cola == nullptr) return true;
    else return false;
}
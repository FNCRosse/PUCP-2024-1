/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de octubre de 2023, 19:45
 */

#include <iostream>
using namespace std;
#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "FuncionesArbolBinario.h"
#include "funcionesCola.h"
#include "Nodo.h"
#include "Lista.h"
#include "Cola.h"

void PlantarArbolBinario(struct NodoArbol *&arbol,struct NodoArbol *Arbizq,Guerrero dato, struct NodoArbol *ArbDer){
    struct NodoArbol *nuevo = new  struct NodoArbol;
    nuevo->derecha = ArbDer;
    nuevo->izquierda = Arbizq;
    nuevo->elemento = dato;
    arbol = nuevo;
}
void  InsertarRecursivo(struct NodoArbol *&ejercito, Guerrero guerrero){
    if(ejercito == nullptr){
        PlantarArbolBinario(ejercito,nullptr,guerrero,nullptr);
    } else if (ejercito->elemento.poder > guerrero.poder){
        InsertarRecursivo(ejercito->izquierda,guerrero);
    } else if (ejercito->elemento.poder < guerrero.poder){
        InsertarRecursivo(ejercito->derecha,guerrero);
    } else{
        ejercito->elemento.Cantidad += guerrero.Cantidad;
    }
}
void FusionarRecursivo(struct NodoArbol *nodo1, struct NodoArbol *nodo2){
    if(nodo2 != nullptr){
        FusionarRecursivo(nodo1,nodo2->izquierda);
        FusionarRecursivo(nodo1,nodo2->derecha);
        InsertarRecursivo(nodo1,nodo2->elemento);
        delete nodo2;
    }
}

void FusionDeEjercitos(struct ArbolBinario &Peach,struct ArbolBinario &DonkeyKong){
    FusionarRecursivo(Peach.raiz,DonkeyKong.raiz);
    DonkeyKong.raiz =nullptr;
}
void InsertarEnEjercito(struct ArbolBinario &ejercito,Guerrero guerrero){
    InsertarRecursivo(ejercito.raiz,guerrero);
}
int main(int argc, char** argv) {
    //Parte A
    struct ArbolBinario Peach,DonkeyKong;
    contruir(Peach);
    contruir(DonkeyKong);
    Guerrero EjercitoPeach[5]={{52,2},{40,1},{25,3},{42,2},{60,1}};
    for(int i=0;i<5;i++) InsertarEnEjercito(Peach,EjercitoPeach[i]);
    
    Guerrero EjercitoDonkeyKong[6]={{65,1},{25,1},{12,2},{34,1},{75,2},{70,1}};
    for(int i=0;i<6;i++) InsertarEnEjercito(DonkeyKong,EjercitoDonkeyKong[i]);
    recorrerEnPreOrden(Peach);
    recorrerEnPreOrden(DonkeyKong);
    //Parte B
    FusionDeEjercitos(Peach,DonkeyKong);
    recorrerEnPreOrden(Peach);
    //Parte C
    recorreriIterativoEnPreOrden(Peach);
    return 0;
}


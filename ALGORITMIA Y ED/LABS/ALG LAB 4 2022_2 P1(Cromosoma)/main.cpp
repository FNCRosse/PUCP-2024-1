/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"

void plantarArbolBinario(struct NodoArbol *&raiz, struct NodoArbol * izquierdo,
                         cromo elemento, struct NodoArbol * derecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(izquierdo, elemento, derecho);
    raiz = nuevoNodo;
}
void InsertarRecursivo(NodoArbol *&nodo,int valor,int Dato){
    if(esNodoVacio(nodo)){
        plantarArbolBinario(nodo,nullptr,{Dato,valor},nullptr);
        return;
    }
    InsertarRecursivo(nodo->derecha,1,Dato);
    InsertarRecursivo(nodo->izquierda,0,Dato);
    
}
void InsertarEnCromosoma(ArbolBinario &cromosoma,int Dato){
    InsertarRecursivo(cromosoma.raiz,0,Dato);
}
int ObtenerCantCombRecursivo(NodoArbol *&nodo,int PesoTotal,int PesoParcial){
    PesoParcial += nodo->elemento.num * nodo->elemento.valor;
    if(nodo->derecha == nullptr && nodo->izquierda == nullptr){
        if(PesoParcial == PesoTotal) return 1;
        else return 0;
    } 
    return ObtenerCantCombRecursivo(nodo->izquierda,PesoTotal,PesoParcial) +
            ObtenerCantCombRecursivo(nodo->derecha,PesoTotal,PesoParcial);
}
int ObtenerCantCombinaciones(ArbolBinario cromosoma,int PesoTotal){
    int PesoParcial =0;
    return ObtenerCantCombRecursivo(cromosoma.raiz,PesoTotal,PesoParcial);
}
int main(int argc, char** argv) {

    struct ArbolBinario cromosoma;
    construir(cromosoma);
    //PARTE 1
    int nDatos=2;
    int Datos[nDatos]={10,50};
    int peso = 60;
    //Cargar  comosoma
    plantarArbolBinario(cromosoma, nullptr,{0,0},nullptr);
    for(int i=0;i<nDatos;i++){
        InsertarEnCromosoma(cromosoma,Datos[i]);
    }
    destruirArbolBinario(cromosoma);
    //Parte B
    construir(cromosoma);
    int PesoTotal =70,CantCombinaciones=0;
    nDatos=5;
    int Datos2[nDatos]={10,50,20,30,40};
    plantarArbolBinario(cromosoma, nullptr,{0,0},nullptr);
    for(int i=0;i<nDatos;i++){
        InsertarEnCromosoma(cromosoma,Datos2[i]);
    }
    CantCombinaciones=ObtenerCantCombinaciones(cromosoma,PesoTotal);
    cout<<"Hay "<<CantCombinaciones<<" combinaciones"<<endl;
    

    
    return 0;
}


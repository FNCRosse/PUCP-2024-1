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

NodoArbol* ObtenerRaiz(struct ArbolBinario &arbol){
    return arbol.raiz;
}
bool EsSkyNerd(struct NodoArbol *nodo) {
    if(nodo->elemento.tipo == 'S' and nodo->elemento.velocidad == 200) return true;
    else return false;
}
bool HaySkyNerd(struct ArbolBinario &SkyNerd, int &nivel){
    if(esArbolVacio(SkyNerd)) return false;
    int altura=0;
    struct Cola cola;
    construir(cola);
    encolar(cola,SkyNerd.raiz);
    while(!esColaVacia(cola)){
        struct NodoArbol *nodo = desencolar(cola);
        if(nodo->elemento.velocidad==200 ){
            if(EsSkyNerd(nodo->derecha) or EsSkyNerd(nodo->izquierda) ){
                nivel=altura;
                return true;
            }
        }
        if(!esNodoVacio(nodo->izquierda)) encolar(cola,nodo->izquierda);
        if(!esNodoVacio(nodo->derecha)) encolar(cola,nodo->derecha);
        altura++;
    }
    destruirCola(cola);
    return false;
}
int main(int argc, char** argv) {
    struct ArbolBinario SkyNerd,arbol1,arbol2,arbol3,arbol4,arbol5,arbol6,arbol7,arbol8;
    struct ArbolBinario arbol9,arbol10,arbol11,arbol12,arbol13;
    NodoArbol *nodo1,*nodo2;
    //Parte A
    contruir(SkyNerd);
    PlantarArbolBinario(arbol1,nullptr,{'E',50},nullptr);
    PlantarArbolBinario(arbol2,nullptr,{'E',100},nullptr);
    nodo1 = ObtenerRaiz(arbol1);
    nodo2 = ObtenerRaiz(arbol2);
    PlantarArbolBinario(arbol3,nodo1,{'S',50},nullptr);
    PlantarArbolBinario(arbol4,nodo2,{'Z',200},nullptr);
    PlantarArbolBinario(arbol5,arbol3,{'E',100},arbol4);
    PlantarArbolBinario(arbol6,nullptr,{'S',50},nullptr);
    PlantarArbolBinario(arbol7,arbol5,{'Z',50},arbol6);
    
    PlantarArbolBinario(arbol9,nullptr,{'S',100},nullptr);
    PlantarArbolBinario(arbol10,nullptr,{'E',200},nullptr);
    PlantarArbolBinario(arbol11,arbol9,{'S',200},arbol10);
    PlantarArbolBinario(arbol12,nullptr,{'S',150},nullptr);
    PlantarArbolBinario(arbol13,arbol11,{'E',200},arbol12);
    
    PlantarArbolBinario(SkyNerd,arbol7,{'Z',100},arbol13);
    
    //Parte B y C
    int nivel;
    if(HaySkyNerd(SkyNerd,nivel)){
        cout<<"Si hay SkyNerd es la red"<<endl;
        cout<<"Esta en el nivel: "<<nivel<<endl;
    }else{
        cout<<"NO hay SkyNerd es la red"<<endl;
    }
    return 0;
}


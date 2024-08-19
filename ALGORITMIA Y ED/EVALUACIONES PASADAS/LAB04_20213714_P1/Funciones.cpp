/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cstdlib>
using namespace std;
#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "Funciones.h"
#include "Lista.h"
#include "Cola.h"
#include "funcionesCola.h"

void plantarABBnew(struct NodoArbol *&Arbol,struct NodoArbol *arbolIzq,
                    int Codigo, struct NodoArbol *arbolDer){
    struct NodoArbol* nuevoNodo = new struct NodoArbol;
    nuevoNodo->Codigo = Codigo;
    nuevoNodo->izquierda = arbolIzq;
    nuevoNodo->derecha = arbolDer;
    Arbol = nuevoNodo;
}
void InsertarRecursivo(struct NodoArbol *&Arbol,int Codigo){
    if(esNodoVacio(Arbol)) plantarABBnew(Arbol,nullptr,Codigo,nullptr);
    else
        if(Codigo < Arbol->Codigo)
            InsertarRecursivo(Arbol->izquierda,Codigo);
        else 
            InsertarRecursivo(Arbol->derecha,Codigo);
}
void Insertar(struct ArbolBinario &Arbol,int Codigo){
    InsertarRecursivo(Arbol.raiz,Codigo);
}
int CompararABB(int a, int b){
    if(a == b)return 0;
    else if( a < b)return 1;
    else if( a > b)return -1;
}
struct NodoArbol* busca_primer_ancestro_comun(NodoArbol *Raiz,int num1, int num2){
    struct NodoArbol *NodoEncontrado, *nodo1,*nodo2;
    //Caso base
    if(esNodoVacio(Raiz)) return nullptr;
    NodoEncontrado = Raiz;
    busca_primer_ancestro_comun(Raiz->izquierda,num1,num2);
    if(CompararABB(Raiz->Codigo,num1)== 1 || CompararABB(Raiz->Codigo,num2)== 1)
        return NodoEncontrado;
    if(CompararABB(Raiz->Codigo,num1)== 1 || CompararABB(Raiz->Codigo,num2)== 1)
        return NodoEncontrado;
    busca_primer_ancestro_comun(Raiz->izquierda,num1,num2);
    
    

}
bool EsArbolBB (struct NodoArbol *arboltoken){
    if (esNodoVacio(arboltoken)) return 1;
    NodoArbol* hijoIzq = arboltoken->izquierda; 
    NodoArbol* hijoDer = arboltoken->derecha;
    return hijoIzq->Codigo<hijoDer->Codigo and EsArbolBB(arboltoken->izquierda)
                                           and EsArbolBB(arboltoken->derecha);
}
bool suma_parcial_arboles_Nodos(struct NodoArbol *Arbol_token,
                        struct NodoArbol *Arbol_SIS, NodoArbol* PrimerAncestroC){
    if(esNodoVacio(Arbol_token) || esNodoVacio(Arbol_SIS)) return false;
    //Lo que quiero es recorrer hasta encontrar el primer ancestro 
    //Luego ir sumando lo de arbol sistemas al arbol token
    //luego verificar si es arbol binario de busqueda
    bool EncontrarPosPAncestro=false;
    struct Cola cola;
    construir(cola);
    encolar(cola,Arbol_token);
    while(not esColaVacia(cola)){
        struct NodoArbol* nodo = desencolar(cola);
        if(nodo == PrimerAncestroC )EncontrarPosPAncestro =true;
        if(EncontrarPosPAncestro)nodo->Codigo += Arbol_SIS->Codigo;
        
        if(not esNodoVacio(nodo->izquierda)){
            encolar(cola,nodo->izquierda);
            Arbol_SIS = Arbol_SIS->izquierda;
        }
        if(not esNodoVacio(nodo->derecha)){
            encolar(cola,nodo->derecha);
            Arbol_SIS = Arbol_SIS->derecha;
        }    
    } 
   if(EsArbolBB(Arbol_token)) return true;
   else return false;
}
bool suma_parcial_arboles(struct ArbolBinario *Arbol_token,
                        struct ArbolBinario *Arbol_SIS, NodoArbol* PrimerAncestroC){
    return suma_parcial_arboles_Nodos(Arbol_token->raiz,Arbol_SIS->raiz,
                                        PrimerAncestroC);  
}


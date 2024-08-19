/* 
 * File:   main.cpp
 * Author: aulab
 * Created on 4 de noviembre de 2023, 10:05 AM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "NodoArbol.h"

NodoArbol* hallarAncestro(NodoArbol* raiz, int a, int b) {
    if (raiz == nullptr) {
        return nullptr;
    }

    if (a < raiz->elemento and b < raiz->elemento) {
        return hallarAncestro(raiz->izquierda, a, b);
    }

    if (a > raiz->elemento and b > raiz->elemento) {
        return hallarAncestro(raiz->derecha, a, b);
    }

    return raiz;
}

int verificaABB(NodoArbol *raiz){
    if(raiz==NULL) return 1;
    
    if((raiz->izquierda and raiz->elemento<=raiz->izquierda->elemento) 
        or (raiz->derecha and raiz->elemento>=raiz->derecha->elemento)) 
        return 0;
    
    int esABBIZQ = verificaABB(raiz->izquierda);
    int esABBDER = verificaABB(raiz->derecha);
    
    return esABBDER and esABBIZQ;   
}

void sumarArbolesRecursivo(NodoArbol* &codigoVerificacion, NodoArbol* arbolAuxiliar){
    if (codigoVerificacion == NULL) {
        // Si el Ã¡rbol de cÃ³digoVerificaciÃ³n estÃ¡ vacÃ­o, copia el Ã¡rbol arbolAuxiliar
        codigoVerificacion = arbolAuxiliar;
    } else if (arbolAuxiliar != NULL) {
        // Suma los valores de los nodos coincidentes
        codigoVerificacion->elemento += arbolAuxiliar->elemento;

        // Luego, realiza la suma para los subÃ¡rboles izquierdo y derecho recursivamente
        sumarArbolesRecursivo(codigoVerificacion->izquierda, arbolAuxiliar->izquierda);
        sumarArbolesRecursivo(codigoVerificacion->derecha, arbolAuxiliar->derecha);
    }
    
}

void inserta_ab_izq(NodoArbol *arbol,int elem){
    NodoArbol * nuevoNodo = crearNuevoNodoArbol(nullptr,elem,nullptr);
    arbol->izquierda = nuevoNodo;
}

void inserta_ab_der(NodoArbol *arbol,int elem){
    NodoArbol * nuevoNodo = crearNuevoNodoArbol(nullptr,elem,nullptr);
    arbol->derecha = nuevoNodo;
}

NodoArbol* hallarNodo(NodoArbol* &p, NodoArbol* &q, int ancestro) {
    if (p == nullptr || q == nullptr) {
        return nullptr;  // Al menos uno de los nodos no existe en el camino.
    }

    if (p->elemento == ancestro) {
        return p;  // Se encontró el nodo en el árbol p.
    }

    if (p->elemento > ancestro && q->elemento > ancestro) {
        p = p->izquierda; q = q->izquierda;
        return hallarNodo(p, q, ancestro);
    } else {
        p = p->derecha; q = q->derecha;
        return hallarNodo(p, q, ancestro);
    }
}


int sumaParcial(ArbolBinario &token,ArbolBinario &sistema,int ancestro){
    NodoArbol *p, *q;
    p = token.raiz; q = sistema.raiz;
    
    NodoArbol *pq = hallarNodo(p, q, ancestro);
    sumarArbolesRecursivo(p, q);
    
    recorridoPorNivel(token);
    
    return verificaABB(token.raiz);
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda token;
    construir(token);
    
    //arbol generado
    insertar(token, 5);
    insertar(token, 2);
    insertar(token, 1);
    insertar(token, 3);
    insertar(token, 12);
    insertar(token, 8);
    insertar(token, 18);
    insertar(token, 4);
    
    //recorridoPorNivel(token);
    //1,4
    NodoArbol*  p = hallarAncestro(token.arbolBinario.raiz, 1, 4);
    
    if(p){
        cout<<"El ancestro es: "<<p->elemento<<endl;
        
        //construcion del arbol sistema
        ArbolBinario sistema;
        construir(sistema);
        
        plantarArbolBinario(sistema, NULL, 3, NULL);
        
        inserta_ab_izq(sistema.raiz, 1);
        inserta_ab_der(sistema.raiz->izquierda, 2);
        
        inserta_ab_der(sistema.raiz, 5);
        inserta_ab_izq(sistema.raiz->derecha, 4);
        inserta_ab_der(sistema.raiz->derecha, 6);
        
//        plantarArbolBinario(sistema, NULL, 4, NULL);
//        
//        inserta_ab_izq(sistema.raiz, -2);
//        inserta_ab_der(sistema.raiz->izquierda, -1);
//        inserta_ab_izq(sistema.raiz->izquierda, -3);
//        
//        inserta_ab_der(sistema.raiz, 6);
//        inserta_ab_izq(sistema.raiz->derecha, 5);
//        inserta_ab_der(sistema.raiz->derecha, 7);
        
        recorridoPorNivel(sistema);
        
        //suma parcial
        if(sumaParcial(token.arbolBinario, sistema, p->elemento) == 1){
            cout<<"Acceso autorizado"<<endl;
        }else{
            cout<<"Acceso denegado"<<endl;
        }
    }
       
      
    return 0;
}


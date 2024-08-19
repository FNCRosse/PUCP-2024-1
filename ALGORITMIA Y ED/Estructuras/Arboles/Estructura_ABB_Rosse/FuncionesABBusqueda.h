/* 
 * File:   FuncionesABBusqueda.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de octubre de 2023, 11:14
 */

#ifndef FUNCIONESABBUSQUEDA_H
#define FUNCIONESABBUSQUEDA_H

void InsertarRecursivo (struct ArbolBinario &arbol,struct NodoArbol *& raiz, int elemento);
void Insertar (struct ArbolBinario &arbol, int elemento);
void plantarArbolBB(struct NodoArbol *&arbol,
                                struct NodoArbol *arbolIzq, int elemento, struct NodoArbol *arbolDer);
int MinimoRecursivoABB(struct NodoArbol *nodo);
int MinimoABB(struct ArbolBinario arbol);
int MaximoRecursivoABB(struct NodoArbol *nodo);
int MaximoABB(struct ArbolBinario arbol);
struct NodoArbol *borrarNodoRecursivo(struct NodoArbol *nodo,int dato);
void borrarNodo(struct ArbolBinario arbol,int dato);
struct NodoArbol *  minimoArbol(struct NodoArbol * nodo);
int ComprararABB(int elementoA, int elementoB);
int SumarNodosRecursivo(struct NodoArbol *nodo);
int SumarNodos(struct ArbolBinario arbol);
void FusionarRecursivo(struct NodoArbol *nodo1, struct NodoArbol* nodo2);
void Fusionar(struct ArbolBinario *arbol1, struct ArbolBinario *arbol2);
bool buscarArbolRecursivo(struct NodoArbol* nodo,int dato);
bool buscarArbol(struct ArbolBinario arbol,int dato);
#endif /* FUNCIONESABBUSQUEDA_H */


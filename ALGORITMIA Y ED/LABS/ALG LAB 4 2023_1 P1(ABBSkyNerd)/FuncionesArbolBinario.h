/* 
 * File:   FuncionesArbolBinario.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de octubre de 2023, 19:49
 */

#ifndef FUNCIONESARBOLBINARIO_H
#define FUNCIONESARBOLBINARIO_H


void contruir(struct ArbolBinario &arbol);
bool esArbolVacio(struct ArbolBinario arbol);
bool esNodoVacio (struct NodoArbol * nodo);
void PlantarArbolBinario(struct ArbolBinario &arbol,
                                          struct NodoArbol * HijoIzq, Servidor elemento, struct NodoArbol * HijoDer);
void PlantarArbolBinario(struct ArbolBinario &arbol,
                                          struct ArbolBinario arbolIzq,Servidor elemento,struct ArbolBinario arbolDer); 
void PlantarArbolBinario(struct ArbolBinario &arbol,
                                          struct ArbolBinario arbolIzq,Servidor elemento,struct ArbolBinario arbolDer);
void recorrerEnOrden(struct ArbolBinario arbol);
void RecorrerEnOrdenRecursivo(struct NodoArbol * nodo);
void ImprimirRaiz(struct ArbolBinario arbol);
void ImprimirNodo(struct NodoArbol *nodo);
void RecorrerEnPreOrdenRecursivo(struct NodoArbol * nodo);
void recorrerEnPreOrden(struct ArbolBinario arbol);
void RecorrerEnPostOrdenRecursivo(struct NodoArbol * nodo);
void recorrerEnPostOrden(struct ArbolBinario arbol);
void recorrerPorNivel(struct ArbolBinario arbol);
void recorreriIterativoEnOrden(struct ArbolBinario arbol);
void recorreriIterativoEnPreOrden(struct ArbolBinario arbol);
void recorrerMayorAMenor(struct ArbolBinario arbol);
int maximo (int a, int b);
int AlturaRecursiva (struct NodoArbol *nodo);
int Altura (struct ArbolBinario arbol);
int numeroNodosRecursivo(struct NodoArbol * nodo);
int numeroNodos(struct ArbolBinario arbol);
int numeroHojasRecursivo(struct NodoArbol * nodo);
int numeroHojas(struct ArbolBinario arbol);
int esEquilibradoRecursivo(struct NodoArbol * nodo);
int esEquilibrado(struct ArbolBinario arbol );
int esHoja(struct ArbolBinario arbol);
void destruirRecursivo(struct NodoArbol * nodo);
void destruirArbolBinario(struct ArbolBinario &arbol);



#endif /* FUNCIONESARBOLBINARIO_H */


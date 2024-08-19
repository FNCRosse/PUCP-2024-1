/* 
 * File:   funcionesArboles.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 06:00 PM
 */

#ifndef FUNCIONESARBOLES_H
#define FUNCIONESARBOLES_H

void construir(struct ArbolBinario & );

bool esArbolVacio(struct ArbolBinario arbol);
bool esNodoVacio(struct NodoArbol * nodo);

struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol *, int, 
                                                          struct NodoArbol *);
void plantarArbolBinario(struct ArbolBinario &, struct NodoArbol *, int,
                                                       struct NodoArbol * );
void plantarArbolBinario(struct ArbolBinario &, struct ArbolBinario, int,
                                                       struct ArbolBinario );
int raiz(struct NodoArbol * nodo);
void imprimeRaiz(struct ArbolBinario arbol);
void imprimeNodo(struct NodoArbol * nodo);

struct  NodoArbol * hijoDerecho(struct ArbolBinario );
struct  NodoArbol * hijoIzquierdo(struct ArbolBinario );

void recorrerEnPreOrdenRecursivo(struct NodoArbol * nodo);
void recorrerEnOrdenRecursivo(struct NodoArbol * nodo);
void recorrerEnPostOrdenRecursivo(struct NodoArbol * nodo);

void recorrerEnOrden(struct ArbolBinario );
void recorrerPreOrden(struct ArbolBinario );
void recorrerPostOrden(struct ArbolBinario );

int altura(struct ArbolBinario);
int alturaRecursivo(struct NodoArbol * nodo);

int numeroNodos(struct ArbolBinario );
int numeroNodosRecursivo(struct NodoArbol * nodo);

int numeroHojas(struct ArbolBinario );

int sumarNodosRecursivo(struct NodoArbol * nodo);
int sumarNodos(struct ArbolBinario arbol);

int esEquilibrado(struct ArbolBinario );
int esEquilibradoRecursivo(struct NodoArbol * nodo);

int esHoja(struct ArbolBinario );

void destruirArbolBinario(struct ArbolBinario );
void destruirRecursivo(struct NodoArbol *);

void recorridoPorNivel(struct ArbolBinario arbol);
void enOrdenIterativo(struct ArbolBinario arbol);
void preOrdenIterativo(struct ArbolBinario arbol);


#endif /* FUNCIONESARBOLES_H */


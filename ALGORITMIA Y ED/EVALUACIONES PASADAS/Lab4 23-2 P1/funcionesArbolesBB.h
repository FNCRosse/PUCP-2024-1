/* 
 * File:   funcionesArbolesBB.h
 * Author: ANA RONCAL
 * Created on 24 de septiembre de 2023, 10:34 PM
 */

#ifndef FUNCIONESARBOLESBB_H
#define FUNCIONESARBOLESBB_H

void construir(struct ArbolBinarioBusqueda & arbol);
bool esArbolVacio(struct ArbolBinarioBusqueda  arbol);
void plantarArbolBB(struct NodoArbol *& arbol, 
                    struct NodoArbol * arbolIzquierdo, int elemento, 
                    struct NodoArbol * arbolDerecho);
void preOrden(struct ArbolBinarioBusqueda arbol);
void enOrden(struct ArbolBinarioBusqueda arbol);
void postOrden(struct ArbolBinarioBusqueda arbol);
void destruirArbolBB(struct ArbolBinarioBusqueda arbol);
void recorridoPorNivel(struct ArbolBinarioBusqueda );

void insertar(struct ArbolBinarioBusqueda & arbol, int elemento);
int minimoABB(struct ArbolBinarioBusqueda );
int maximoABB(struct ArbolBinarioBusqueda );
struct NodoArbol *  minimoArbol(struct NodoArbol * nodo);
bool buscaArbol(struct ArbolBinarioBusqueda arbol ,int dato);
void borraNodo(struct ArbolBinarioBusqueda,int );
int comparaABB(int , int ); 
int sumarNodos(struct ArbolBinarioBusqueda arbol);

void insertarRecursivo(struct NodoArbol *& raiz, int elemento);
int minimoABBRecursivo(struct NodoArbol * nodo);
int maximoABBRecursivo(struct NodoArbol * nodo);
bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato);
struct NodoArbol * borraNodoRecursivo(struct NodoArbol * nodo, int elemento);

#endif /* FUNCIONESARBOLESBB_H */


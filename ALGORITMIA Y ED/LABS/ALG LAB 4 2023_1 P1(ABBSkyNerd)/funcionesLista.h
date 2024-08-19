/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
bool esListaVacia( struct Lista  lista);
int longitud(struct Lista tad );
struct Nodo * crearNodo(struct NodoArbol *, struct Nodo * siguiente);
void insertarAlFinal(struct Lista & lista, struct NodoArbol *);
void imprime( struct Lista  lista);
void eliminaCabeza(struct Lista  & lista);
struct NodoArbol * retornaCabeza( struct Lista  lista);
void destruirLista(struct Lista &);

#endif /* FUNCIONESLISTA_H */


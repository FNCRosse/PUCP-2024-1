/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:32 AM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H


void construirP(struct Lista &);
void insertarAlInicio(struct Lista &, struct NodoArbol *);
struct Nodo * crearNodoP(struct NodoArbol *, struct Nodo *);
struct NodoArbol * retornaCabezaP( struct Lista );
bool esListaVaciaP( struct Lista );
int longitudP( struct Lista );
void eliminaCabezaP(struct Lista  &);

void destruir(struct Lista &);
void imprimeP( struct Lista );                                  

#endif /* FUNCIONESLISTA_H */


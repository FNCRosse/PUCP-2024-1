/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:32 AM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H


void construir(struct Lista &);
void insertarAlInicio(struct Lista &, ciudad);
struct Nodo * crearNodo(ciudad elemento, struct Nodo *);
ciudad retornaCabeza( struct Lista );
bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);
void eliminaCabeza(struct Lista  &);

void destruir(struct Lista &);
void imprime(const struct Lista &);                                  

#endif /* FUNCIONESLISTA_H */


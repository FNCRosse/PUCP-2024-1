/* 
 * File:   funcionesPilas.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H

#include "Grafo.h"


void construir(struct Pila & );
int longitud(const struct Pila & );
bool esPilaVacia(const struct Pila &);
void apilar(struct Pila &, ciudad ); 
ciudad desapilar(struct Pila &);
ciudad cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprimir(const struct Pila &);

#endif /* FUNCIONESPILAS_H */


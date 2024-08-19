/* 
 * File:   funcionesPilas.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H

void construir(struct Pila & );
int longitud(struct Pila  );
bool esPilaVacia( struct Pila );
void apilar(struct Pila &, struct NodoArbol * ); 
struct NodoArbol * desapilar(struct Pila &);
struct NodoArbol * cima( struct Pila );
void destruirPila(struct Pila );
void imprimir( struct Pila );

#endif /* FUNCIONESPILAS_H */


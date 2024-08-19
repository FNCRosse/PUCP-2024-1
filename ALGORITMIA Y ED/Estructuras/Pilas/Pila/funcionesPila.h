/* 
 * File:   funcionesPilas.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H

void construir(struct Pila & );
int longitud(const struct Pila & );
bool esPilaVacia(const struct Pila &);
void apilar(struct Pila &, int ); 
int desapilar(struct Pila &);
int cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprimir(const struct Pila &);

#endif /* FUNCIONESPILAS_H */


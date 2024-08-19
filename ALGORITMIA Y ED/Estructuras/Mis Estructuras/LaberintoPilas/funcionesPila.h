/* 
 * File:   funcionesPilas.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H

void construir(struct Pila & );
int longitud(struct Pila );
bool esPilaVacia(struct Pila);
void apilar(struct Pila &, struct Posicion ); 
struct Posicion desapilar(struct Pila &);
struct Posicion cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprime(struct Pila );

#endif /* FUNCIONESPILAS_H */


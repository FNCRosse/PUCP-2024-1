/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & cola);
bool esColaVacia( struct Cola  cola);
void encolar(struct Cola & cola, struct NodoArbol *);
struct NodoArbol * desencolar(struct Cola & cola);
int longitud(struct Cola cola);
void imprime( struct Cola  cola);
void simularFilaEspera(struct Cola & cola);
void destruirCola(struct Cola & cola);

#endif /* FUNCIONESCOLA_H */


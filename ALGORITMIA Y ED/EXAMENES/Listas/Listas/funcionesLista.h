/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
bool esListaVacia(const struct Lista & lista);
int longitud(struct Lista tad );
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente);
void insertarAlFinal(struct Lista & lista, int elemento);
void imprime(const struct Lista & lista);
void eliminaCabeza(struct Lista  & lista);
int retornaCabeza(const struct Lista & lista);
void destruirLista(struct Lista & lista);
#endif /* FUNCIONESLISTA_H */


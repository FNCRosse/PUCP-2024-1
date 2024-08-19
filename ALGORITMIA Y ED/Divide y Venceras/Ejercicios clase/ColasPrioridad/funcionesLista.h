/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

void insertarConPrioridad(struct Lista & lista, const struct Cliente & cliente);
struct Nodo * crearNodo(const struct Cliente & cliente, struct Nodo * siguiente);

struct Cliente retornaCabeza(const struct Lista &);

const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaCabeza(struct Lista &);

void destruir(struct Lista &);
void imprimir(const struct Lista &);

#endif /* FUNCIONESLISTA_H */


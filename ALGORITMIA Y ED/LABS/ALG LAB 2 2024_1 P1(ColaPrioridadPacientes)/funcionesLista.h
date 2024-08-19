/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

struct Nodo * crearNodo(struct Paciente elemento, struct Nodo *);
int retornaCabeza(const struct Lista &);
void insertarencola(struct Lista & tad, struct Paciente elemento);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprime(const struct Lista &);
void ImprimirFecha(struct Nodo *recorrido);

void InsetarConPrioridad(struct Lista &tad,struct Paciente paciente);
int obtenerEdad(struct Nodo* paciente);
#endif /* FUNCIONESLISTA_H */


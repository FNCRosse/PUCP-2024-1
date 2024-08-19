/* 
 * File:   FuncionesListas.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 15:31
 */

#ifndef FUNCIONESLISTAS_H
#define FUNCIONESLISTAS_H

void construir(struct Lista &);
bool esListaVacia(const struct Lista & lista);
int longitud(struct Lista tad );
struct Nodo * crearNodo(struct Cliente cliente, struct Nodo * siguiente);
void insertarAlFinal(struct Lista & lista, struct Cliente cliente);
void imprime(const struct Lista & lista);
void eliminaCabeza(struct Lista  & lista);
int retornaCabeza(const struct Lista & lista);
void destruirLista(struct Lista & lista);
void InsertarConPrioridad(struct Lista &lista, const struct Cliente cliente);

#endif /* FUNCIONESLISTAS_H */


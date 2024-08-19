/* 
 * File:   FuncionesLista.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 19:48
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir (struct Lista &tad);
void insertarEnOrden(struct Lista &tad, struct Pedido pedido);
void InsertarFinal(struct Lista &tad, struct Pedido pedido);
struct Nodo* ObtenerUltimoNodo(struct Lista &tad);
struct Nodo* ObtenerNodoAnterior(struct Lista &tad,struct Pedido pedido);
struct Nodo* CrearNodo(struct Pedido pedido,struct Nodo* sig);
void Imprimir (const struct Lista &tad);

#endif /* FUNCIONESLISTA_H */


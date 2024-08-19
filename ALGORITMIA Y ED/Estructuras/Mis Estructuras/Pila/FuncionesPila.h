/* 
 * File:   FuncionesPila.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 15:03
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct Pila &pila);
bool PilaEstaVacia(const struct Pila &pila);
int LongitudPila(const struct Pila &pila);

//////////////////////////////////////////////////////////////////   OPERACIONES DE PILA  ///////////////////////////////////////////////////////////////////////
void Apilar (struct Pila &pila, int elem);
int Desapilar (struct Pila &pila);
int cima (const struct Pila & pila);
void DestruirPila(struct Pila &pila);
void MostrarPila(const struct Pila &pila);

#endif /* FUNCIONESPILA_H */


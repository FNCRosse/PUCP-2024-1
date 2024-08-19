/* 
 * File:   funcionesListaC.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 12:53
 */

#ifndef FUNCIONESLISTAC_H
#define FUNCIONESLISTAC_H

#include "ListaCircular.h"

///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct ListaC &tad);
bool ListaEstaVacia(const struct ListaC &tad);
int LongitudLista(const struct ListaC &tad);

/////////////////////////////////////////////////////////////////////// INSERTAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void InsertarInicio(struct ListaC &tad,int elem);
void InsertarFinal(struct ListaC &tad,int elem);
void InsertarEnOrden(struct ListaC &tad,int elem);

struct Nodo* ObtenerUltimoNodo(const ListaC &tad);
struct Nodo* CrearNodo(int elem,struct Nodo *sig);
struct Nodo* ObtenerNodoAnterior(int elem,struct ListaC &tad);
struct Nodo* EncontrarNodo(const struct ListaC &tad, int  elem);
/////////////////////////////////////////////////////////////////////// ELIMINAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void EliminarNodo(struct ListaC &tad,int elem);
void EliminarCabeza(struct ListaC&tad);//falta
//Eleminar el ultimo dato de la lista
void EliminarCola(struct ListaC&tad);//falta
void EliminarRepetidos(struct ListaC &tad);//falta
/////////////////////////////////////////////////////////////////////// DESTRUIR LISTA S ///////////////////////////////////////////////////////////////////////
void Destruir(struct ListaC &tad);

/////////////////////////////////////////////////////////////////////// MOSTRAR LISTA S ///////////////////////////////////////////////////////////////////////
void mostrar(const struct ListaC &tad);

/////////////////////////////////////////////////////////////////////// INVERTIR  LISTA S ///////////////////////////////////////////////////////////////////////
void InvertirIterativo(struct ListaC &ptrLista);//falta
void InvertirRecursivo(struct ListaC &ptrLista);//falta
struct Nodo* RecorrerEInvertirRec(Nodo *ptrAntCambio);//falta

#endif /* FUNCIONESLISTAC_H */


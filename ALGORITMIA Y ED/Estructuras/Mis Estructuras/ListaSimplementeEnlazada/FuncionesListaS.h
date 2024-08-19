/* 
 * File:   FuncionesListaS.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 19 de abril de 2024, 10:49
 */

#ifndef FUNCIONESLISTAS_H
#define FUNCIONESLISTAS_H
#include "ListaSimplementeEnlazada.h"

///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct Lista &tad);
bool ListaEstaVacia(const struct Lista &tad);
int LongitudLista(const struct Lista &tad);

/////////////////////////////////////////////////////////////////////// INSERTAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void InsertarInicio(struct Lista &tad,struct Personaje elem);
void InsertarFinal(struct Lista &tad,struct Personaje elem);
void InsertarEnOrden(struct Lista &tad,struct Personaje elem);
void InsertarPorArchivo(struct Lista &tad,const char *namefile);

struct Nodo* ObtenerUltimoNodo(const Lista &tad);
struct Nodo* CrearNodo(struct Personaje elem,struct Nodo *sig);
struct Nodo* ObtenerNodoAnterior(struct Personaje elem,struct Lista &tad);
struct Nodo* EncontrarNodo(const struct Lista &tad, struct Personaje elem);
char * leerNombre(ifstream &arch);
/////////////////////////////////////////////////////////////////////// ELIMINAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void EliminarNodo(struct Lista &tad,struct Personaje elem);
void EliminarCabeza(struct Lista&tad);
//Eleminar el ultimo dato de la lista
void EliminarCola(struct Lista&tad);
void EliminarRepetidos(struct Lista &tad);
/////////////////////////////////////////////////////////////////////// DESTRUIR LISTA S ///////////////////////////////////////////////////////////////////////
void Destruir(struct Lista &tad);

/////////////////////////////////////////////////////////////////////// MOSTRAR LISTA S ///////////////////////////////////////////////////////////////////////
void mostrar(const struct Lista &tad);

/////////////////////////////////////////////////////////////////////// INVERTIR  LISTA S ///////////////////////////////////////////////////////////////////////
void InvertirIterativo(struct Lista &ptrLista);
void InvertirRecursivo(struct Lista &ptrLista);
struct Nodo* RecorrerEInvertirRec(Nodo *ptrAntCambio);
#endif /* FUNCIONESLISTAS_H */


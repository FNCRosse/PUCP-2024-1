// -*- C++ -*-

/* 
 * File:   funcionesVertice.h
 * Author: ANA RONCAL
 *
 * Created on 20 de junio de 2024, 13:02
 */

#ifndef FUNCIONESVERTICE_H
#define FUNCIONESVERTICE_H

void construirListaVertice(struct Vertice & listaVertice);
bool seEncuentraVerticeLista(struct Vertice listaVertice, char llave);
void insertarVerticeAlFinal(struct Vertice & listaVertice, char elemento);
struct NodoVertice * obtenerUltimoNodoV( struct Vertice  listaVertice);
struct NodoVertice * crearNodoV(char ciudad, struct NodoVertice * siguiente);
struct NodoVertice * obtenerNodoVertice(struct Vertice listaVertice, char clave);
void insertarListaAristas(struct Vertice & listaVertice, char verticeOrigen, char verticeDestino);
bool seEncuentraAristaLista(struct Vertice listaVertice, char verticeOrigen, char verticeDestino);

void eliminarVerticeEnLista(struct Vertice & listaVertice, char vertice);
void eliminarDeListaDeAristas(struct Vertice & listaVertice, char verticeOrigen, char verticeDestino);
void destruirListaVertice(struct Vertice & listaVertice);

#endif /* FUNCIONESVERTICE_H */
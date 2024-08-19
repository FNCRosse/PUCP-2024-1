// -*- C++ -*-

/* 
 * File:   funcionesGrafo.h
 * Author: ANA RONCAL
 *
 * Created on 20 de junio de 2024, 12:56
 */

#ifndef FUNCIONESGRAFO_H
#define FUNCIONESGRAFO_H

void construirGrafo(struct Grafo & grafo);
bool seEncuentraVertice(const struct Grafo & grafo, int elemento);
void agregarVertice(struct Grafo & grafo, char elemento);
void agregarArista(struct Grafo & grafo, char vertice1, char vertice2);
void mostrarVerticeYAristas(const struct Grafo & grafo);

void eliminarVertice(struct Grafo & grafo, char vertice);
void eliminarArista(struct Grafo & grafo, char verticeOrigen, char verticeDestino);
void destruirGrafo(struct Grafo & grafo);
#endif /* FUNCIONESGRAFO_H */
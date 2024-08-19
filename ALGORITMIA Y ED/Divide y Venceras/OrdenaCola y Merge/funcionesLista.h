/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 26 de septiembre de 2023, 04:52 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, int);
void insertarAlFinal(struct Lista &, int);
void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(int elemento, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int);
int retornaCabeza(const struct Lista &);

const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaCabeza(struct Lista &);
void eliminaCola(struct Lista);

void destruir(struct Lista &);
void imprimir(const struct Lista &);

void merge(int * arreglo, int iniIzq, int iniDer);
void mergeSort(int * arreglo, int inicio, int fin);

//void merge(int arreglo[], int posicion_inicial, int posicion_medio, int posicion_final);
//void mergeSort(int arreglo[], int posicion_inicial, int posicion_final);

void merge(int * izquierda, int * derecha, int * solucion);
void mergeSort(int arreglo[], int longitud);

int busquedaBinaria(int arreglo[], int k, int posicion_inicial, int posicion_final);
#endif /* FUNCIONESLISTA_H */


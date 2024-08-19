/* 
 * File:   Funciones.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de marzo de 2024, 09:30
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Contenedor.h"
#define NMAX 4

void LeerContenedores(Contenedor (&contenedor)[NMAX][NMAX]);
void MostrarContenedores(Contenedor contenedor[][NMAX]);
void SolucionMaxValor(Contenedor contenedor[][NMAX]);
void ArmarMatriz(int (&Matriz)[NMAX][NMAX], int arreglo[]);
void CargarCombinaciones(int num,int *Combinaciones);

#endif /* FUNCIONES_H */


/* 
 * File:   Funciones.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 21 de marzo de 2024, 16:12
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "Paquete.h"

void mostrarArreglo(int * Arr, int n);
void  OrdenarSeleccion(int *Arr,int n);
void  OrdenarBurbuja(int *Arr,int n);
int BusquedaSecuencial(int numBuscar,int *arreglo,int n);
void SolucionMochilaPesoExacto(struct Paquete *paquete);
void SolucionMochilaPesoMAX(struct Paquete *paquete);
void SolucionMochilaGananciaMAX(struct Paquete *paquete);
void CargarBinario(int num, int *Arreglo);

#endif /* FUNCIONES_H */


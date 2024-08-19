/* 
 * File:   Funciones.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 27 de marzo de 2024, 11:27
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void LeerDatos(int *ArrCamiones,int *ArrPaquetes,int &CantCamiones,int &CantPaquetes);
void multiplesCamiones(int CantCamiones,int CantPaquetes,int *ArrCamiones,int *ArrPaquetes);
void CargarCromosoma(int *Cromosoma,int i);
bool EsValido(int CantCamiones,int CantPaquetes,int *ArrCamiones,int *ArrPaquetes,int *Cromosoma,int tamano,
                int *CargarCamiones);
int CalcularMaximo(int *ArrCamiones,int CantCamiones,int *CargarCamiones);
int CalcularMinimo(int *ArrCamiones,int CantCamiones,int *CargarCamiones);

#endif /* FUNCIONES_H */


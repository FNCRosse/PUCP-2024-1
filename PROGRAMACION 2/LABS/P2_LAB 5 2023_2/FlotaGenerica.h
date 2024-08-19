/* 
 * File:   FlotaGenerica.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de mayo de 2024, 19:59
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

void CargaCamiones(void *&Flota,int numCamiones,double PesoMaximo,void*(*Lee)(ifstream &),
        double (*Calcular)(void*),const char* namefile);
void MuestraCamiones(void* flota,int numCamiones,void (*imprime)(void*,ofstream&),const char* namefile);
bool EsListaVacia(void *Lista);

void InicializarLista(void *&Camion);
double ObtenerPesoActualCamion(void *Camion);
void  insertar(void* Dato,void *Camion);
void  ActualizarPesoCamion(double pesoIngresado, void *Camion);

#endif /* FLOTAGENERICA_H */


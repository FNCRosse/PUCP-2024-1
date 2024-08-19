/* 
 * File:   FuncionesAux.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 26 de marzo de 2024, 16:54
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

#include "Controles.h"
void LeerDatos(Controles *controles,int CantControles);
void CargaCombinaciones(int num,int *Combinaciones);
void Soluciones(struct Controles *controles,int CantControles,int Presupuesto);
void ImprimirResultados(int *Combinaciones,Controles *controles,int CantControles,int Beneficio,int solucion);
bool CumpleRequisitos(int *Combinaciones, Controles *controles,int CantControles,int pos);

#endif /* FUNCIONESAUX_H */


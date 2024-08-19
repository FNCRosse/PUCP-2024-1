/* 
 * File:   ListaConEntero.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de mayo de 2024, 19:58
 */

#ifndef LISTACONENTERO_H
#define LISTACONENTERO_H

void *LeeNumero(ifstream &);
double CalcularNumero(void*Dato);
int cmpNumero(const void *a, const void*b);
void imprimeNumero(void *arrFlota,ofstream &arch);

#endif /* LISTACONENTERO_H */


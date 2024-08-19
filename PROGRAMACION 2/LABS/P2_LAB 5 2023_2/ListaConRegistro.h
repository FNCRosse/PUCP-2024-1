/* 
 * File:   ListaConRegistro.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de mayo de 2024, 19:58
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H

void *LeeRegistro(ifstream &);
char* LeerCadena(ifstream &arch,char c);
double CalcularRegistro(void*Dato);
int cmpRegistro(const void *a, const void*b);
void imprimeRegistro(void *arrFlota,ofstream &arch);

#endif /* LISTACONREGISTRO_H */


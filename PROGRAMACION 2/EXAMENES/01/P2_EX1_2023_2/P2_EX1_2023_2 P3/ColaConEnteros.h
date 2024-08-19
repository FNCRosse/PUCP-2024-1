/* 
 * File:   ColaConEnteros.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 14:41
 */

#ifndef COLACONENTEROS_H
#define COLACONENTEROS_H

void CargaEnteros(void *&Cola,void *(*Lee)(ifstream &),const char* namefile);
void * leeNumero (ifstream &arch);
void mostrarEnteros(void *cola,void (*imprime)(ofstream &,void *),const char* namefile);
void imprimeNumero(ofstream &arch,void *dato);
#endif /* COLACONENTEROS_H */


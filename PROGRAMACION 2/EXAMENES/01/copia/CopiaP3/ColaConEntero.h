/* 
 * File:   ColaConEntero.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 07:42
 */

#ifndef COLACONENTERO_H
#define COLACONENTERO_H

void CargaEntero(void *&Cola,void *(*lee)(ifstream &),const char *namefile);
void MostrarEnteros(void *&Cola,void (*Imprime)(ofstream &,void*),const char *namefile);

void *leeNumero(ifstream &arch);
void ImprimeNumero(ofstream &,void*nodo);
#endif /* COLACONENTERO_H */


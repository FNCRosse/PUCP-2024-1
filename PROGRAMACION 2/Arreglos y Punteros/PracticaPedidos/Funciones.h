/* 
 * File:   Funciones.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 11 de abril de 2024, 22:40
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void LeerDatos(int *&NumPed,int *&DniPed,char ***&CodLibrosPedido);
void mostrar(int *&NumPed,int *&DniPed,char ***& CodLibrosPedido);
char ** LeerCodigos(ifstream &arch);
void imprimirLibros(char **CodLibrosPedido,ofstream &arch);
char * LeerCadenas(ifstream &arch);
#endif /* FUNCIONES_H */


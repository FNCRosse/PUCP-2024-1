/* 
 * File:   Pregunta02Examen01PunteroGenerico.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 05:36
 */

#ifndef PREGUNTA02EXAMEN01PUNTEROGENERICO_H
#define PREGUNTA02EXAMEN01PUNTEROGENERICO_H

void cargaProductos(void *&Productos,const char* namefile);
void PruebaDeCargaProductos(void *Productos,const char* namefile);
char * LeerCadena(ifstream &arch,char c);
void * LeerRegistro(ifstream &arch);
void ImprimirProducto(ofstream &arch,void *Producto);
void OrdenarProductos(void *Productos);
int cmpCodProd(const void *a, const void*b);
#endif /* PREGUNTA02EXAMEN01PUNTEROGENERICO_H */


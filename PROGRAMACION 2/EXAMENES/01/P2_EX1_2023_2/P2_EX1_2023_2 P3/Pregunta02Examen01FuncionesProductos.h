/* 
 * File:   Pregunta02Examen01FuncionesProductos.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 14:34
 */

#ifndef PREGUNTA02EXAMEN01FUNCIONESPRODUCTOS_H
#define PREGUNTA02EXAMEN01FUNCIONESPRODUCTOS_H

void cargarProductos(void *&Productos,const char* namefile);
void * LeerRegistro(ifstream &arch);
char * LeerCadena(ifstream &arch, char c);
void IncrementarEspacios(void **&ArrProductos,int &nDatos,int &cap);

void pruebaDeCargaDeProductos(void *Productos);
void imprimirRegistro(ofstream &arch,void *Producto);
int cmpCodProd(const void *a,const void *b);
void OrdenarProductos(void *Productos);


#endif /* PREGUNTA02EXAMEN01FUNCIONESPRODUCTOS_H */


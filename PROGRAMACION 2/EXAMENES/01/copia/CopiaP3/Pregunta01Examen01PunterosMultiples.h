/* 
 * Proyecto: Pregunta01
 * Archivo:  Pregunta01Examen01PunterosMultiples.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 6 de octubre de 2023, 09:31 PM
 */

#ifndef PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H
#define PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H

void cargarPedidos (int **&, char **&, const char *);
void pruebaDeCargaDePedidos (int **, char **, const char *);
int * leeRegistro(ifstream &arch);
void aumentarEspacios(int **&, char **&, int &, int &);
void imprimePedido(ofstream &,int *,char *); 

char* LeerCadena(ifstream &arch,char c);
void OrdenarPedidos(int **FechaClienteCantidad,char **CodigoDelProducto);
void  mergeSort(int **FechaClienteCantidad,char **CodigoDelProducto,int inicio,int fin);
void merge (int **FechaClienteCantidad,char **CodigoDelProducto,int inicio,int medio,int fin);
void Asignar(int *&P1,int *&Q1);
bool EsMayor(int* P1,int *Q1);

#endif /* PREGUNTA01EXAMEN01PUNTEROSMULTIPLES_H */


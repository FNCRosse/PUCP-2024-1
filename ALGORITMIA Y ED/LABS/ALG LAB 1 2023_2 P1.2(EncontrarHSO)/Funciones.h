/* 
 * File:   Funciones.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de marzo de 2024, 10:35
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#define XMAX 4
#define YMAX 10
void LeerDatos(char (&Tablero)[XMAX][YMAX],char *Palabra);
void EncontrarHSO(const char Tablero[XMAX][YMAX],const char *Palabra );
bool EncontrarLetra(const char *Palabra, const char Letra, int tamano);

#endif /* FUNCIONES_H */


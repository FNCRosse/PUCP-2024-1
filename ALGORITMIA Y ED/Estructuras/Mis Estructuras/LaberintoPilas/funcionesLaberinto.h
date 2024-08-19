/* 
 * File:   funcionesLaberinto.h
 * Author: ANA RONCAL
 * Created on 5 de septiembre de 2023, 08:47 AM
 */

#ifndef FUNCIONESLABERINTO_H
#define FUNCIONESLABERINTO_H

bool valida(int tablero[3][5], int fil, int col);
bool laberinto(struct Pila & pila, int tablero[3][5], int, int);
void mostrar(int tablero[3][5]);

#endif /* FUNCIONESLABERINTO_H */


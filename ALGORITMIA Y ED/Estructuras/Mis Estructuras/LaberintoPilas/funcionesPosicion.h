/* 
 * File:   funcionesPosicion.h
 * Author: ANA RONCAL
 * Created on 5 de septiembre de 2023, 09:10 AM
 */

#ifndef FUNCIONESPOSICION_H
#define FUNCIONESPOSICION_H

void constructor(struct Posicion & posicion, int x, int y);
int getX(struct Posicion posicion);
int getY(struct Posicion posicion);
void setX(struct Posicion posicion, int x);
void setY(struct Posicion posicion, int y);

#endif /* FUNCIONESPOSICION_H */


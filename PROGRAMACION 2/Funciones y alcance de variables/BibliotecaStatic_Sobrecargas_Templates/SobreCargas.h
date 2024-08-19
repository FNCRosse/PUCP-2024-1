/* 
 * File:   SobreCargas.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de marzo de 2024, 11:19
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <fstream>
using namespace std;
#include "Punto2D.h"

Punto2D operator+(const Punto2D &p1, const Punto2D &p2);
ostream& operator<<(ostream &os,const Punto2D &p);
istream& operator>>(istream &in, Punto2D &p);
bool operator>(const Punto2D &p1, const Punto2D &p2);
Punto2D operator+=( Punto2D &pr, const Punto2D &p2);
Punto2D& operator++(Punto2D& punto);
Punto2D operator++(Punto2D& punto,int);
Punto2D& operator--(Punto2D& punto);
Punto2D operator--(Punto2D& punto,int);

#endif /* SOBRECARGAS_H */


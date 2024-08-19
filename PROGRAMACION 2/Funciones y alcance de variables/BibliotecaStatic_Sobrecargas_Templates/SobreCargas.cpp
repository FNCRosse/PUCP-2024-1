/* 
 * File:   SobreCargas.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de marzo de 2024, 11:19
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "Punto2D.h"
// para sobrecargar el operador +
//Lo pasamos por referencia pq utilizacion, para utilizar el mismo espacio
//const para evitar que se modifique los atributos de struct
Punto2D operator+(const Punto2D &p1, const Punto2D &p2){
    Punto2D pr;
    pr.x = p1.x + p2.x;
    pr.y = p1.y + p2.y;
    return pr;
}

// para sobrecargar el operador <<
ostream& operator<<(ostream &os,const Punto2D &p){
    os<<p.x<<","<<p.y;
    return os;
}

// para sobrecargar el operador <<
istream& operator>>(istream &in, Punto2D &p){
    in>>p.x>>p.y;
    return in;
}

// para sobrecargar el operador >
bool operator>(const Punto2D &p1, const Punto2D &p2){
    return (p1.x > p2.x) && (p1.y > p2.y);
}

//Para sobrecargar el operador +=
//para += si no utlizas const por que lo vas cambiar
Punto2D operator+=( Punto2D &pr, const Punto2D &p2){
    pr.x += p2.x;
    pr.y += p2.y;
    return pr;
}

//Para sobrecarhar el operador ++
Punto2D& operator++(Punto2D& punto) {
        ++punto.x;
        ++punto.y;
        return punto;
    }

// Sobrecarga del operador de postincremento (obj++)
 Punto2D operator++(Punto2D& punto,int) {
      Punto2D copia = punto;
      ++punto.x;
        ++punto.y;
     return copia;
}
 
 //Para sobrecarhar el operador --
Punto2D& operator--(Punto2D& punto) {
        --punto.x;
        --punto.y;
        return punto;
    }

// Sobrecarga del operador de postincremento (obj++)
 Punto2D operator--(Punto2D& punto,int) {
      Punto2D copia = punto;
      --punto.x;
      --punto.y;
     return copia;
}
/* 
 * File:   OperadoresSobrecargados.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de marzo de 2024, 09:58
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Personas.h"
#include "OperadoresSobreCargados.h"
#include "Templates.h"

//PRE
Persona operator ++(Persona &p){
    ++p.sueldo;
}
//POST
Persona operator ++(Persona &p,int){
    Persona copia = p;
    ++p.sueldo;
}
//PRE
Persona operator --(Persona &p){
    --p.sueldo;
}
//POST
Persona operator --(Persona &p,int){
    Persona copia = p;
    --p.sueldo;
}
Persona operator +(const Persona &p1, const Persona &p2){
    Persona nueva;
    nueva.dni = p1.dni + p2.dni;
    strcat(nueva.nombre,"SUMA");
    nueva.sueldo = p1.sueldo+p2.sueldo;
    return nueva;
}
Persona operator -(const Persona &p1, const Persona &p2){
    Persona nueva;
    nueva.dni = p1.dni - p2.dni;
    strcat(nueva.nombre,"RESTA");
    nueva.sueldo = p1.sueldo-p2.sueldo;
    return nueva;
}
Persona operator *(const Persona &p1, const Persona &p2){
    Persona nueva;
    nueva.dni = p1.dni * p2.dni;
    strcat(nueva.nombre,"MULTIPLICACION");
    nueva.sueldo = p1.sueldo*p2.sueldo;
    return nueva;
}
Persona operator /(const Persona &p1, const Persona &p2){
    Persona nueva;
    nueva.dni = p1.dni / p2.dni;
    strcat(nueva.nombre,"DIVICION");
    nueva.sueldo = p1.sueldo/p2.sueldo;
    return nueva;
}
Persona operator %(const Persona &p1, const int Porcentaje){
    Persona nueva;
    nueva.dni = p1.dni %Porcentaje;
    strcat(nueva.nombre,"PORCENTAJE");
    nueva.sueldo = (int) p1.sueldo % Porcentaje;
    return nueva;
}
void operator >>(ifstream &arch, struct Persona &p){
    arch>>p.dni;
    if(arch.eof()) return;
    arch.get();
    arch.getline(p.nombre,60,',');
    arch>>p.sueldo;
}
ostream& operator <<(ostream &out, const struct Persona &p){
    out.precision(2); //Muestre solo 2 decimales
    out<<fixed;
    out<<setw(10)<<p.dni<<"   "<<left<<setw(45)<<p.nombre<<right<<setw(10)<<p.sueldo<<endl;   
    return out;
}
bool operator ==(int dni,const struct Persona &p){
    return dni == p.dni;
}
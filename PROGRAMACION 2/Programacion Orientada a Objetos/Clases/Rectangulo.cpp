/* 
 * File:   Rectangulo.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 10:58
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Rectangulo.h"

Rectangulo::Rectangulo(){//constructor
    Nombre=nullptr;
}
Rectangulo::Rectangulo(double b,double h,char* nom){
    Rectangulo();
    base = b;
    altura = h;
    SetNombre(nom);
}
Rectangulo::Rectangulo(const Rectangulo &org){
    
}
Rectangulo::~Rectangulo(){
    
}
void Rectangulo::SetAltura(double Alt){
    altura = Alt;
}
double Rectangulo::GetAltura()const{
    return altura;
}
void Rectangulo::SetBase(double b){
    base = b;
}
double Rectangulo::GetBase()const{
    return base;
}
double Rectangulo::area(){
    return base*this->altura;
}
void Rectangulo::SetNombre(const char* cad){
    if(Nombre != nullptr ) delete Nombre;
    Nombre = new char [strlen(cad)+1];
    strcpy(Nombre,cad);
}
void Rectangulo::GetNombre(char* cad)const{
    if(Nombre == nullptr ) cad[0]=0;
    strcpy(cad,Nombre);
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 10:48
 */

#include <iostream>
using namespace std;
#include "Rectangulo.h"

int main(int argc, char** argv) {
    class Rectangulo r1;
    char *name;
    name = new char[50];
    r1.SetAltura(4);
    r1.SetBase(12);
    r1.SetNombre("Mikyx");
    r1.GetNombre(name);
    
    cout<<name<<endl;
    cout<<r1.GetAltura()<<endl;
    cout<<r1.GetBase()<<endl;
    cout<<r1.area()<<endl;

    return 0;
}


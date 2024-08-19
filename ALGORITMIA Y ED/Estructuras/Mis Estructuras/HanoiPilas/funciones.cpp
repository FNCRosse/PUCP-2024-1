/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 30 de enero de 2024, 12:36 AM
 */

#include <iostream>

using namespace std;
#include "funcionesPila.h"

void hanoi(int n, char desde, char hacia, char auxiliar){
    
    //caso base
    if (n == 1){
        cout<<"Mover disco 1 desde la torre "<< desde << " hacia la torre "
            << hacia << endl;
        return;
    }
    //llevo los n-1 discos de A a C
    hanoi(n-1, desde, auxiliar, hacia);
    cout<<"Mover disco "<< n << " desde la torre " << desde << " hacia la torre " 
        << hacia << endl;
    //llevo los n-1 discos de C a B
    hanoi(n-1, auxiliar, hacia, desde);
}

void hanoi(int n, struct Pila & desde, struct Pila & hacia, struct Pila & auxiliar){
    
    //caso base
    if (n == 1){
        apilar(hacia, desapilar(desde));
//        cout<<"Mover disco "<< n << " desde la torre " << "A" << " hacia la torre " 
//            << "B" << endl;
        return;
    }
        //llevo los n-1 discos de A a C
        hanoi(n-1, desde, auxiliar, hacia);
        apilar(hacia, desapilar(desde));
//        cout<<"Mover disco "<< n << " desde la torre " << "A"<< " hacia la torre " 
//            << "C" << endl;
        //llevo los n-1 discos de C a B
        hanoi(n-1, auxiliar, hacia, desde);
}
/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de marzo de 2024, 11:28
 */

#include <iostream>
using namespace std;
#include "Punto2D.h"
#include "SobreCargas.h"

int main(int argc, char** argv) {
    Punto2D p1{5,3};
    Punto2D p2{2,1};
    cout<<endl<<"SobreCargar de operadores"<<endl;
    cout<<"Punto 1: "<<p1<<endl;
    cout<<"Punto 2: "<<p2<<endl;
    Punto2D p3 = p1 +p2;
    cout<<"Suma(+)"<<endl<<"Punto 3: "<<p3<<endl;
    
    cout<<"Mayor (>)"<<endl;
    if(p1 > p2)  cout<<"P1 es mayor"<<endl;
    else cout<<"P2 es mayor"<<endl;
    
    p3 += p2;
    cout<<"Suma Simplificada(+=)"<<endl<<"Punto 3: "<<p3<<endl;
    
    ++p3;
    cout<<"PreIncremento(++obj)"<<endl<<"Punto 3: "<<p3<<endl;
      p3++;
    cout<<"PostIncremento(obj++)"<<endl<<"Punto 3: "<<p3<<endl;
    --p3;
    cout<<"PreDisminucion(--obj)"<<endl<<"Punto 3: "<<p3<<endl;
      p3--;
    cout<<"PostDisminucion(obj--)"<<endl<<"Punto 3: "<<p3<<endl;
    

    return 0;
}


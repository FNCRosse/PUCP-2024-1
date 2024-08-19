/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 30 de enero de 2024, 12:30 AM
 */

#include <iostream>
#include <cstdlib>
#include "funciones.h"
#include "Lista.h"
#include "Pila.h"
using namespace std;
#include "funcionesPila.h"

/*
 * Usando la técnica de Divide y vencerás
 * Acertijo de Hanoi
 */
int main(int argc, char** argv) {
    
    int numDiscos = 4; //cambiar el número de discos según sea necesario
   
    /*A es la torre inicial, B es la torre final y C es la torre auxiliar*/
    //cout <<"RESULTADO DE HANOI: "<<endl;
   // hanoi(numDiscos, 'A', 'B', 'C'); 

    struct Pila torreA, torreB, torreC;
    construir(torreA);
    construir(torreB);
    construir(torreC);
    
    for(int i = numDiscos; i >= 1; i--)
        apilar(torreA, i);
    cout <<endl<<endl;
    cout <<" Usando (PILAS): "<<endl;
    cout <<" ESTADO INICIAL DE LAS TORRES: "<<endl;
    cout <<" TORRE ORIGEN: ";
    imprimir(torreA);
    cout <<" TORRE DESTINO: ";
    imprimir(torreB);
    cout <<" TORRE AUXILIAR: ";
    imprimir(torreC);
      
   /*Resolviendo el problema de las torres de Hanoi*/
    hanoi(numDiscos, torreA, torreB, torreC);
    
    cout <<endl<<" ESTADO FINAL DE LAS TORRES: "<<endl;
    cout <<" TORRE ORIGEN: ";
    imprimir(torreA);
    cout <<" TORRE DESTINO: ";
    imprimir(torreB);
    cout <<" TORRE AUXILIAR: ";
    imprimir(torreC);
    return 0;
}


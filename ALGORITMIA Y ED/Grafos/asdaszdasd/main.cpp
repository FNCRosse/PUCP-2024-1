/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de junio de 2024, 15:57
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    
    
    int puntoMedio;
    int arreglo[2];
    if(puntoMedio%2==0){
        if(arreglo[puntoMedio]==arreglo[puntoMedio+1]){
            // Se tiene pareja
            hallarSolito(arreglo,puntoMedio+2,fin);
        }else{
                        hallarSolito(arreglo,inicio,puntoMedio);

        }
    }else{
        if(arreglo[puntoMedio-1]==arreglo[puntoMedio]){
            // Se tiene pareja
            hallarSolito(arreglo,puntoMedio+1,fin);
        }else{
                        hallarSolito(arreglo,inicio,puntoMedio-1);

        }
        
    }
    return 0;
}


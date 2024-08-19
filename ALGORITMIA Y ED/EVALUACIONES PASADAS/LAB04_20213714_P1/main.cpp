/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cstdlib>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "Funciones.h"
#include "NodoArbol.h"

int main(int argc, char** argv) {
    //Declarar estructuras y variables
    struct ArbolBinario Arbol_token,Arbol_Sistema;
    construir(Arbol_token);
    construir(Arbol_Sistema);
    //los puse en un arreglo para agilizar el insertado en duro
    int Elementos [8]= {5,2,12,1,3,8,18,4}; 
    //No nos pide balancear, asi que insertamos en duro
    //Insertar el codigo en el arbol token
    for(int i=0; i<8;i++){
        Insertar(Arbol_token,Elementos[i]);
    }
    
    //numeros generados por el sistema
    int num1= 1, num2 = 4;
    NodoArbol* PrimerAncestroComun,*raizAToken;
    raizAToken = Arbol_token.raiz;
    //PARTE B
    //DEVUELVE EL NODO PRIMER ANCESTRO
    PrimerAncestroComun = busca_primer_ancestro_comun(raizAToken,num1,num2);
    if(PrimerAncestroComun!=nullptr){
        //Genero el arbol binario sistemas 
        int ElementosSis [7]= {3,1,2,5,4,6,7}; 
        for(int i=0; i<7;i++){
            Insertar(Arbol_Sistema,ElementosSis[i]);
        }
        recorridoPorNivel(Arbol_Sistema);
       //PARTE C
        bool Bandera = suma_parcial_arboles(&Arbol_token,&Arbol_Sistema,
                                              PrimerAncestroComun);
        if(Bandera)
            cout<<"Acceso Otorgado"<<endl;
        else
            cout<<"Acceso Denegado"<<endl;
    }

    
    
      
    return 0;
}


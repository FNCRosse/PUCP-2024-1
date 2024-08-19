/* 
 * File:   Funciones.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de marzo de 2024, 09:32
 */
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include "Contenedor.h"
#include "Funciones.h"
#define PESOMAX 100
#define NMAX 4

void LeerContenedores(Contenedor (&contenedor)[NMAX][NMAX]){
    ifstream arch("Datos.txt",ios::in);
    for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX;j++){
            arch>>contenedor[i][j].Peso>>contenedor[i][j].Valor;
        }
    }
}
void MostrarContenedores(Contenedor contenedor[][NMAX]){
    for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX;j++){
            cout<<contenedor[i][j].Peso<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX;j++){
            cout<<contenedor[i][j].Valor<<" ";
        }
        cout<<endl;
    }
}
void CargarCombinaciones(int num,int *Combinaciones){
    int i=0;
    while(num>0){
        Combinaciones[i++]=num%2;
        num = num/2;
    }
}
void ArmarMatriz(int (&Matriz)[NMAX][NMAX], int arreglo[]){
    int m=0;
     for(int j=0;j<NMAX;j++){
        for(int z=0;z<NMAX;z++){
            Matriz[j][z] = arreglo[m];
            m++;
        }
    }  
}
void SolucionMaxValor(Contenedor contenedor[][NMAX]){
    int MatrizCombinaciones[NMAX][NMAX];
    int Combinaciones[NMAX*NMAX]={};
    int opciones = (int)pow(2,NMAX*NMAX);
    int MaxValor=0,MaxCombinacion=0;
    
    for(int i=0;i<opciones;i++){
        int PesoParcial=0,ValorParcial=0;
        CargarCombinaciones(i,Combinaciones);
        ArmarMatriz(MatrizCombinaciones,Combinaciones);
        for(int j=0;j<NMAX;j++){
            for(int z=0;z<NMAX;z++){
                PesoParcial += MatrizCombinaciones[j][z] * contenedor[j][z].Peso;
                ValorParcial += MatrizCombinaciones[j][z] * contenedor[j][z].Valor;
            }
        }  
        if(MaxValor < ValorParcial && PesoParcial<=PESOMAX){
            MaxValor =ValorParcial;
            MaxCombinacion=i;
        }
    }
    
    cout<<"Solucion: "<<endl;
    cout<<"Valor Maximo: "<<MaxValor<<" (en miles de $)"<<endl;
    CargarCombinaciones(MaxCombinacion,Combinaciones);
    ArmarMatriz(MatrizCombinaciones,Combinaciones);
    for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX;j++){
            cout<<contenedor[i][j].Peso*MatrizCombinaciones[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<NMAX;i++){
        for(int j=0;j<NMAX;j++){
            cout<<contenedor[i][j].Valor*MatrizCombinaciones[i][j] <<" ";
        }
        cout<<endl;
    }
}
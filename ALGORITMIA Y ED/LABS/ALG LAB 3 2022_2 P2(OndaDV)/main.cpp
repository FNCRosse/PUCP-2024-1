/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 10 de mayo de 2024, 11:50
 */

#include <iostream>
using namespace std;
#define MAX 10
int MaximoPotencia = -1;

int CalcularPotenciaMaxima(int Matriz[MAX][MAX],int &Columna,int inicioFila,int FinFila,int inicioCol,
        int FinCol){
    //Caso base
    if(inicioCol == FinCol && inicioFila == FinFila){
        if(Matriz[inicioFila][inicioCol] > MaximoPotencia) {
            Columna = FinCol;
            MaximoPotencia = Matriz[inicioFila][inicioCol];
        }
        return Matriz[inicioFila][inicioCol];
    }
    int medFila = (inicioFila+FinFila)/2;
    int medCol = (inicioCol+FinCol)/2;
    int izq1 = 0, der1 =0, izq2=0,der2=0;
    int cuad1 = 0, cuad2 =0, cuad3=0,cuad4=0;
    if(inicioFila == FinFila){
        izq1 = CalcularPotenciaMaxima(Matriz,Columna,inicioFila,FinFila,inicioCol,medCol);
        der1 = CalcularPotenciaMaxima(Matriz,Columna,inicioFila,FinFila,medCol+1,FinCol);
        return max(izq1,der1);
    }
    if(inicioCol == FinCol){
        izq2 = CalcularPotenciaMaxima(Matriz,Columna,inicioFila,medFila,inicioCol,FinCol);
        der2 = CalcularPotenciaMaxima(Matriz,Columna,medFila+1,FinFila,inicioCol,FinCol);
        return max(izq2,der2);
    }
    cuad1 = CalcularPotenciaMaxima(Matriz,Columna,inicioFila,medFila,inicioCol,medCol);
    cuad2 = CalcularPotenciaMaxima(Matriz,Columna,inicioFila,medFila,medCol+1,FinCol);
    cuad3 = CalcularPotenciaMaxima(Matriz,Columna,medFila+1,FinFila,inicioCol,medCol);
    cuad4 = CalcularPotenciaMaxima(Matriz,Columna,medFila+1,FinFila,medCol+1,FinCol);
    return max(cuad1,max(cuad2,max(cuad3,cuad4)));
}
int BuscarFilaMayorImpacto(int Matriz[MAX][MAX],int Columna,int PotenciaMax,int inicio,int fin){
    if(inicio > fin) return -1 ;
    int med = (inicio+fin)/2;
    if(Matriz[med][Columna] == PotenciaMax){
        return med ;
    } 
    int izquierda = BuscarFilaMayorImpacto(Matriz,Columna,PotenciaMax,inicio,med-1);
    int derecha = BuscarFilaMayorImpacto(Matriz,Columna,PotenciaMax,med+1,fin);
    if(izquierda != -1) return izquierda;
    if(derecha != -1) return derecha;
    return -1;
}
int main(int argc, char** argv) {
    int n=7,m=8;
    int Matriz[MAX][MAX] = {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,1,1,1,0,0,0},
        {0,1,2,1,0,0,0},
        {0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0},
    };
    int Columna=0; //Aqui guardare para ver en que columna esta
    int PotenciaMax = CalcularPotenciaMaxima(Matriz,Columna,0,m-1,0,n-1);
    int FilaImpacto = BuscarFilaMayorImpacto(Matriz,Columna,PotenciaMax,0,m-1);
    cout<<"Para este juego de datos la potencia mas alta de bomba es de "<<PotenciaMax<<
            ", y la columna donde se ubica es "<<Columna<<". La fila con el mayor impacto es la de "<<FilaImpacto;

    return 0;
}


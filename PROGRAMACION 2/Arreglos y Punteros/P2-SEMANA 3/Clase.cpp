/* 
 * File:   Clase.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 5 de abril de 2024, 15:45
 */
#include <iostream>
using namespace std;

void ClasePunteroDoble() {
    int **a=nullptr; // Declarar un puntero doble;
    a=new int*;//reservo un espacio a un puntero
    *a = new int;//en el segundo puntero recien le asigno el int
    **a=53;
    cout<<**a<<endl;
    
    //Asignacion de matriz dinamica
    //aqui una columna puede tener diferentes tamaños
    int **ptr = nullptr;//Una matriz en puntero
    ptr =new int* [4]; //Filas
    for(int i=0;i<4;i++){
        ptr[i] = new int [5];//Columna
    }
    //Se puede cambiar el orden de filas
    //de forma estatica
    int matriz[4][5];
    int i=0,j=3,aux;
    for(int k=0;k<5;k++){
        aux= matriz[i][k];
        matriz[i][k] = matriz[j][k];
        matriz[j][k] = aux;
    }
    //de forma dinamica
    int **matrix; //4x5
    int x=0,y=3;// filas a intercambiar
    int *aux2;
    aux2 = matrix[x];
    matrix[x] =matrix[y];
    matrix[y] = aux2;
    
}


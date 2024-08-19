/* 
 * File:   Funciones.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de marzo de 2024, 10:35
 */
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include "Funciones.h"
#define XMAX 4
#define YMAX 10
#define MAXP 3

void LeerDatos(char (&Tablero)[XMAX][YMAX],char *Palabra){
    ifstream arch("Datos.txt");
    for(int i=0;i<MAXP;i++) arch>>Palabra[i];
    for(int i=0;i<XMAX;i++){
        for(int j=0;j<YMAX;j++){
            arch>>Tablero[i][j];
        }
    }
}
bool EncontrarLetra(const char *Palabra, const char Letra, int tamano){
    for(int i=0;i<tamano;i++){
        if(Palabra[i]==Letra) return true;
    }
    return false;
}
void EncontrarHSO(const char Tablero[XMAX][YMAX],const char *Palabra){
     int tamano = sizeof(Palabra) / sizeof(Palabra[0])-1;
     char PalabraAux[tamano];
    for(int i=0; i<XMAX;i++){
        for(int j=0;j<YMAX;j++){
            char p= Tablero[i][j];
            if(EncontrarLetra(Palabra,Tablero[i][j],tamano)){
                PalabraAux[0]=Tablero[i][j];
                for(int dir=0;dir<4;dir++){
                    int dirFila = (dir==3) - (dir==2);
                    int dirCol = (dir==0) - (dir==1);
                     //posicion de la sig letra
                    int i2 = i+dirFila;
                    int j2 = j+dirCol;
                    int k=1;
                    char a=Tablero[i2][j2];
                    while((i2>=0 && i2<XMAX) && (j2>=0 && j2<YMAX)/*Condicion q no se pase del tablero*/
                                       && (k<tamano) /*Condicion q la sig letra coincida*/
                                       && (!EncontrarLetra(PalabraAux,Tablero[i2][j2],k)) 
                                        && (EncontrarLetra(Palabra,Tablero[i2][j2],tamano))) /*condicion que k no se pase del tamano de la palabra a buscar*/{
                        PalabraAux[k]=Tablero[i2][j2];
                        i2 += dirFila;
                        j2 += dirCol;
                        k++;
                    }
                    if(k==tamano){// una vez k finalise el arreglo de palabra, guardar en respuesta
                        cout << i << "," << j << " "<<endl;
                        break;
                    }
                }
            }
        }
    }
}
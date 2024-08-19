/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 9 de mayo de 2024, 08:57
 */

#include <iostream>
using namespace std;
#define MAXP 8
#define MAXB 11
char BuscarBocaditoExtra(char Bocaditos[MAXP][MAXB],int fila,int inicio,int fin){
    // Caso base
    if(inicio>fin) return ' ';
    if(inicio == fin) return Bocaditos[fila][inicio];
    int med = (inicio+fin)/2;
    if(med % 2 == 0){
        if(Bocaditos[fila][med] == Bocaditos[fila][med+1]){
            BuscarBocaditoExtra(Bocaditos,fila,med+2,fin);
        } else {
            BuscarBocaditoExtra(Bocaditos,fila,inicio,med);
        }
    } else {
        if(Bocaditos[fila][med] == Bocaditos[fila][med-1]){
            BuscarBocaditoExtra(Bocaditos,fila,med+1,fin);
        } else {
            BuscarBocaditoExtra(Bocaditos,fila,inicio,med-1);
        }
    }
}
int BuscarBocaditoMasCaro(int Precios[MAXP][MAXB],int fila,int inicio,int fin){
    //Caso Base
    if(inicio>fin) return -1;
    //Caso Recursivo
    int med = (inicio+fin)/2;
    int factor;
    if(med%2 == 1) factor = 1;
    else factor = -1;
    //lo que tiene que cumplir para que me devuelva el resultado
    //Es decir que donde estamos , med, sea mayor que sus vecinos
    if(Precios[fila][med] >= Precios[fila][med+factor] && Precios[fila][med] >= Precios[fila][med-factor]){
        return med+1;
    }
    if(Precios[fila][med] < Precios[fila][med+factor]){
        return BuscarBocaditoMasCaro(Precios,fila, inicio,med);
    }
    if(Precios[fila][med] < Precios[fila][med-factor]){
        return BuscarBocaditoMasCaro(Precios,fila, med+1,fin);
    }
    
    
}
int main(int argc, char** argv) {
    //PARTE A
    char Bocaditos[MAXP][MAXB] = {
        {'O','O','C','C','A','A','E','E','R','R','R'},
        {'C','C','A','A','R','R','E','E','B','B',' '},
        {'R','R','E','E','C','C','F','F','A','A',' '},
        {'E','E','F','F','A','A','A','B','B','R','R'},
        {'C','C','C','A','A','R','R','O','O','E','E'},
        {'O','O','C','C','A','A','R','R','E','E',' '},
        {'A','A','F','F','R','R','E','E','O','O',' '},
        {'E','E','A','A','O','O','B','B','F','F',' '},
    };
    
    for(int i=0;i<MAXP;i++){
        char BocaditoExtra = BuscarBocaditoExtra(Bocaditos,i,0,MAXB-1);
        if (BocaditoExtra != ' '){
            cout<<"La fila "<<i+1<<" tiene un "<<BocaditoExtra<<" adicional"<<endl;
        }
    }
    
     //PARTE B
    int cantBocaditos=5;
    int Precios[MAXP][MAXB]={
        {1,2,3,2,1},
        {2,3,2,2,1},
        {1,2,2,5,3},
        {2,5,3,3,1},
        {2,2,3,2,1},
        {1,2,3,2,1},
        {3,5,2,1,1},
        {2,3,2,1,1},
    };
    for(int i=0;i<MAXP;i++){
        int Asiento = BuscarBocaditoMasCaro(Precios,i,0,cantBocaditos-1);
        if(Asiento != -1){
            cout<<"En la fila "<<i+1<<", el pasajero del asiento "<<Asiento
                    <<" tiene el bocadito mas casro que sus vecinos"<<endl;
        }
    }
    return 0;
}


/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 11 de abril de 2024, 09:00
 */

#include <iostream>
#include <fstream>
#include "Tortugas.h"
using namespace std;
#define MAXT 4
#define MAXF 10
#define MAXC 10

void LeerTortugasYMatriz(Tortugas *tortugasNinja,int matriz[MAXF][MAXC],const char* namafile,const char* namafileM){
    ifstream arch (namafile,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namafile<<" no se abrio"<<endl;
        exit(1);
    }
    ifstream archM (namafileM,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namafileM<<" no se abrio"<<endl;
        exit(1);
    }
    int n=0;
    while(true){
        arch>>tortugasNinja[n].NomTort;
        if(arch.eof()) break;
        arch>>tortugasNinja[n].poder>>tortugasNinja[n].Direccion;
        n++;
    }
    for(int i=0;i<MAXC;i++){
        for(int j=0;j<MAXF;j++){
            archM>>matriz[i][j]; 
        }
    }
}
bool CombateTablero(int x,int y,int matriz[MAXF][MAXC],Tortugas *tortugasNinja,int PosT){
    //Caso base
    if((x>=MAXF && x<0 && y>=MAXC && y<0) || PosT == 4  ) return false;
    int a = matriz[x][y];
    //Casos Recursivos
    //Caso Derecha
    if(tortugasNinja[PosT].Direccion == 'D'){
        if(matriz[x][y] == 0) CombateTablero(x,y+1,matriz,tortugasNinja,PosT);
        else if (tortugasNinja[PosT].poder >= matriz[x][y]){ // Pelea y gana
            if(matriz[x][y] == 50 )return true;
            tortugasNinja[PosT].poder -= matriz[x][y];
            CombateTablero(x,y+1,matriz,tortugasNinja,PosT);
        }
        else{ //Pelio y perdio
            //Retrocedo por que no le pude ganar y le sumo al siguiente tortuga
            CombateTablero(x,y-1,matriz,tortugasNinja,PosT+1);
        }
    }
    //Caso abajo
    if(tortugasNinja[PosT].Direccion == 'A'){
        if(matriz[x][y] == 0) CombateTablero(x+1,y,matriz,tortugasNinja,PosT);
        else if (tortugasNinja[PosT].poder > matriz[x][y]){ // Pelea y gana
            return true;
            tortugasNinja[PosT].poder -= matriz[x][y];
            CombateTablero(x+1,y,matriz,tortugasNinja,PosT);
        }
        else{ //Pelio y perdio
            //Retrocedo por que no le pude ganar y le sumo al siguiente tortuga
            CombateTablero(x-1,y,matriz,tortugasNinja,PosT++);
        }
    }
}
int main(int argc, char** argv) {
    Tortugas tortugasNinja[MAXT];
    int Matriz[MAXF][MAXC]{},PosT=0,x=0,y=0;
    bool ResultadoTN;
    
    LeerTortugasYMatriz(tortugasNinja,Matriz,"DatosTortugas.txt","DatosMatriz.txt");
    ResultadoTN = CombateTablero(x,y,Matriz,tortugasNinja,PosT);
    
    if(ResultadoTN){
        cout<<"Las tortunijas lograron vencer a SuperFly";
    }
    else{
        cout<<"Las tortunijas no lograron vencer a SuperFly";
    }
    return 0;
}


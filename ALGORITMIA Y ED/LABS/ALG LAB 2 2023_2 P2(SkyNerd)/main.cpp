/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 11 de abril de 2024, 15:48
 */

#include <iostream>
#include <fstream>
using namespace std;
#define MAXS 7

void LeerMatriz(int Servidores[MAXS][MAXS]){
    ifstream arch ("Dato.txt",ios::in);
    for(int i=0;i<MAXS;i++){
        for(int j=0;j<MAXS;j++){
            arch>>Servidores[i][j];
        }
    }
}
int SkyNerdDetector(int Servidores[MAXS][MAXS],int x,int y,int PosS){
    bool EnvianPaq=false, NoRecibePaq=true;
    //Caso base
    if((x>=MAXS || x<0 || y>=MAXS || y<0) || PosS == 8) return -1;
    
    if(Servidores[x][y] == 0){
        //Revisar arriba y derecha
        for(int i=x-1;i>=0;i--){
            if(Servidores[i][y] != 0){
                EnvianPaq = true;
                break;
            }
            if(Servidores[x][i] == 0){
                NoRecibePaq = false;
                break;
            }
        }
        //Revisar abajo y izquierda
        for(int i=x+1;i<MAXS;i++){
             if(Servidores[i][y] != 0){
                 EnvianPaq = true;
                 break;
             }
            if(Servidores[x][i] == 0){
                NoRecibePaq = false;
                break;
            }
        }
        if(EnvianPaq == false && NoRecibePaq == true) return PosS;
        else SkyNerdDetector(Servidores,x+1,y+1,PosS+1);
    }
}

int main(int argc, char** argv) {
    int Servidores[MAXS][MAXS]{}, n =7,ServDectectado;
    int x=0,y=0,PosS=1;
    
    LeerMatriz(Servidores);
    
    ServDectectado = SkyNerdDetector(Servidores,x,y,PosS);
    
    if(ServDectectado != -1){
            cout<<"SkyNerd ha sido detectado en el servidor: "<<ServDectectado<<endl;
    }
    else
        cout<<"SkyNerd no esta en la red"<<endl;
    
    return 0;
}


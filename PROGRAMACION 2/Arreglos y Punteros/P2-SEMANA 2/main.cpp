/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 26 de marzo de 2024, 15:25
 */

#include <iostream>
using namespace std;
void LeerDatos(int *&parray, int &n){
    int buffer[100];//Se almacena temporalmente en el stack
    //ESte metodo depende del tamño del buffer
    //Lo usas cuando sabes cuanto es el maximo de ese contexto
    n=0;
    while(true){
        cin>>buffer[n];
        if(cin.eof()) break;
        ++n;
    }
    parray = new int [n]; // Asignacion dinamica exacta
    for(int i;i<n;i++) parray[i] = buffer[i];
}

int main(int argc, char** argv) {
    //Metodo de asignacion exacta de memoria
    int * parray = nullptr;
    int n;
    LeerDatos(parray,n);
    for(int i;i<n;i++) cout<<"\t"<<parray[i]<<endl;
    
    
    return 0;
}


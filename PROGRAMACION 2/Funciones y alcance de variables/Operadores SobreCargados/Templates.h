/* 
 * File:   Templates.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de marzo de 2024, 09:59
 */

#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <fstream>
#include <iostream>
using namespace std;

template <typename T>
void LeerDatos(T *a, int &n, const char* nombArch){
    ifstream arch (nombArch,ios::in);
    if(!arch.is_open()){
        cout<<"No se encontro el archivo"<<endl;
        exit(1);
    }
    n=0;
    while(true){
        arch>>a[n];
        if(arch.eof()) break;
        n++;
    }
    arch.close();
}
template <typename T>
void MostrarDatos(T *a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}
template <typename T>
int Buscar(int valor, T *a,int n){
    for(int i=0;i<n;i++){
        if(valor == a[i]) return i;
    }
    return -1;
}

#endif /* TEMPLATES_H */


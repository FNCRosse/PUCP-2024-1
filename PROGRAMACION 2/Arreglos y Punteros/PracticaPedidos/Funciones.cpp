/* 
 * File:   Funciones.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 11 de abril de 2024, 22:40
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include  "Funciones.h"

void LeerDatos(int *&NumPed,int *&DniPed,char ***&CodLibrosPedido){
    ifstream arch ("Pedidos.txt");
    int nd =0, num;
    int BuffNumP[130]{},BuffDNI[130]{};
    char **BuffCodLib[130]{};
    while(true){
        arch>>num;
        if(arch.eof()) break;
        arch.get();
        arch>>BuffDNI[nd];
        arch.get();
        BuffCodLib[nd] = LeerCodigos(arch);
        BuffNumP[nd] = num;
        nd++;
    }
    NumPed = new int [nd+1]{};
    DniPed = new int [nd+1]{};
    CodLibrosPedido = new char **[nd+1]{};
    for(int i=0;i<nd;i++){
        NumPed[i] = BuffNumP[i];
        DniPed[i] = BuffDNI[i];
        CodLibrosPedido[i] = BuffCodLib[i];
    }
}
char ** LeerCodigos(ifstream &arch){
    char **Aux,*buff[100]{};
    int cant=0;
    while(true){
        buff[cant] = LeerCadenas(arch);
        cant++;
        if(arch.get() == '\n')break;
    }
    Aux = new char *[cant+1]{};
    for(int i=0;i<cant;i++){
        Aux[i] = buff[i];
    }
    return Aux;
}
char * LeerCadenas(ifstream &arch){
    char cadena[8],*PtrCadena;
    arch>>cadena;
    PtrCadena = new char [strlen(cadena)+1];
    strcpy(PtrCadena,cadena);
    return PtrCadena;
}
void mostrar(int *&NumPed,int *&DniPed,char ***& CodLibrosPedido){
    ofstream arch ("Reporte.txt");
    for(int i=0; NumPed[i];i++){
        arch<<left<<setw(6)<<NumPed[i]<<DniPed[i]<<endl;
        imprimirLibros(CodLibrosPedido[i],arch);
        arch<<endl;
    }
}
void imprimirLibros(char **CodLibrosPedido,ofstream &arch){
    for(int i=0; CodLibrosPedido[i] ;i++){
        arch<<right<<setw(10)<<CodLibrosPedido[i]<<endl;
    }
}
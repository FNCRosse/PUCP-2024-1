/* 
 * File:   ListaConRegistro.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de mayo de 2024, 19:58
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ListaConRegistro.h"
enum RegLista {SIG, DATO};
enum Registro {CODIGO,DNI,CANT,PESO};
void *LeeRegistro(ifstream &arch){
    void **Registro = new void*[4]{};
    char* codigo, *Dni,extra;
    int* cant = new int;
    double *peso = new double;
    codigo = LeerCadena(arch,',');
    if(arch.eof()) return nullptr;
    Dni = LeerCadena(arch,',');
    arch>>*cant>>extra>>*peso;
    arch.get();
    Registro[CODIGO]= codigo;
    Registro[DNI]= Dni;
    Registro[CANT]= cant;
    Registro[PESO]= peso;
    return Registro;
}
char* LeerCadena(ifstream &arch,char c){
    char cadena[60],*PtrCadena;
    arch.getline(cadena,60,c);
    PtrCadena = new char [strlen(cadena)+1];
    strcpy(PtrCadena,cadena);
    return PtrCadena;
}
double CalcularRegistro(void*Dato){
    void**DatosReg = (void**)Dato;
     double *peso = (double*)DatosReg[PESO];
    return *peso;
}
int cmpRegistro(const void *a, const void*b){
    void **AuxA = (void**)a, **AuxB = (void**)b;
    void **ListaA = (void**)(*AuxA), **ListaB = (void**)(*AuxB);
    double* PesoA = (double*)(ListaA[DATO]), *PesoB = (double*)(ListaB[DATO]);
    return *PesoB - *PesoA;
}
void imprimeRegistro(void *arrFlota,ofstream &arch){
    void **Lista  = (void**)arrFlota;
    while(Lista){
        void**DatosLista = (void**)(Lista[DATO]);
        char*codigo = (char*)(DatosLista[CODIGO]);
        int*cantidad = (int*)(DatosLista[CANT]);
        double*Peso = (double*)(DatosLista[PESO]);
        arch<<right<<setw(15)<<codigo<<setw(8)<<*cantidad<<setw(10)<<*Peso<<endl;
        Lista = (void**)(Lista[SIG]);
    }
}
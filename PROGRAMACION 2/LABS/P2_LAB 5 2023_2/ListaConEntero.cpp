/* 
 * File:   ListaConEntero.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de mayo de 2024, 19:58
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "ListaConEntero.h"
enum RegLista {SIG, DATO};
enum RegPedido {INICIO, PESO};

void *LeeNumero(ifstream &arch){
    double * peso = new double;
    arch >> *peso;
    if(arch.eof()) return nullptr;
    return peso;
}
double CalcularNumero(void*Dato){
    double *peso = (double*)Dato;
    return *peso;
}
int cmpNumero(const void *a, const void*b){
    void **AuxA = (void**)a, **AuxB = (void**)b;
    void **ListaA = (void**)(*AuxA), **ListaB = (void**)(*AuxB);
    double* PesoA = (double*)(ListaA[PESO]), *PesoB = (double*)(ListaB[PESO]);
    return *PesoB - *PesoA;
}
void imprimeNumero(void *arrFlota,ofstream &arch){
    void **Lista  = (void**)arrFlota;
    while(Lista){
        double*Peso = (double*)(Lista[DATO]);
        arch<<*Peso<<endl;
        Lista = (void**)(Lista[SIG]);
    }
}
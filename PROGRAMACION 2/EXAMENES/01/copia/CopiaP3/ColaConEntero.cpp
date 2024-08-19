/* 
 * File:   ColaConEntero.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 07:43
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "ColaConEnteros.h"
#include "ColaGenerica.h"
enum RegCola {CABEZA,COLA,TOTAL};
enum RegNodo {DATO,SIG};

void CargaEntero(void *&Cola,void *(*lee)(ifstream &),const char *namefile){
    ifstream arch (namefile);
    void *Registro;
    GeneraCola(Cola);
    while(true){
        Registro = lee(arch);
        if(arch.eof()) break;
        Encola(Cola,Registro);
    }
}
void MostrarEnteros(void *&Cola,void (*Imprime)(ofstream &,void*),const char *namefile){
    ofstream arch (namefile);
    void **AuxCola = (void **)Cola;
    while(!ColaVacia(AuxCola[CABEZA])){
        void *Nodo = Desencola(AuxCola);
        Imprime(arch,Nodo);
    }
}
void *leeNumero(ifstream &arch){
    int *numero = new int;
    arch>>*numero;
    if(arch.eof()) return nullptr;
    return numero;
}
void ImprimeNumero(ofstream &arch,void*nodo){
    void **AuxNodo = (void **)nodo;
    int *Numero = (int*) AuxNodo[DATO];
    arch<<right<<setw(5)<<*Numero<<endl;
}
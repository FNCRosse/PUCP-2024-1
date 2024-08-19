/* 
 * File:   ColaConEnteros.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 14:44
 */
#include <iostream>
#include <fstream>
using namespace std;
#include "ColaConEnteros.h"
#include "ColaGenerica.h"
enum RegCola {CABEZA,COLA,TAMN};
enum RegNodo {DATO,SIG};

void CargaEnteros(void *&Cola,void *(*Lee)(ifstream &),const char* namefile){
    ifstream arch (namefile);
    void *Dato;
    GeneraCola(Cola);
    while(true){
        Dato = Lee(arch);
        if(arch.eof()) break;
        Encola(Cola,Dato);
    }
}
void * leeNumero (ifstream &arch){
    int *numero = new int;
    arch>>*numero;
    if(arch.eof()) return nullptr;
    return numero;
}
void mostrarEnteros(void *cola,void (*imprime)(ofstream &,void *),const char* namefile){
    void **ColaAux = (void **)cola;
    ofstream arch (namefile);
    while(!ColaVacia(ColaAux[CABEZA])){
        void *nodo = Desencola(ColaAux);
        imprimeNumero(arch,nodo);
    }
}
void imprimeNumero(ofstream &arch,void *dato){
    void **Nodo = (void **)dato;
    int* numero = (int*)Nodo[DATO];
    arch<<*numero<<endl;
}
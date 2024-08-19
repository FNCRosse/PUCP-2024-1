/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 11:57 AM
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"
using namespace std;
#include "funcionesCola.h"
#include "funcionesPila.h"
#define N 13

void ImprimirFases(const Cola &cola,const Pila &pila1,const Pila pila2){
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila 1: ";
    imprimir(pila1);
    cout<<"Pila 2: ";
    imprimir(pila2);
}
void reclasificarAPilas( Cola &regIncidentes,Pila &pila1,Pila &pila2){
    while(!esColaVacia(regIncidentes)){
        int num = desencolar(regIncidentes);
        int prioridad = num/100;
        if(prioridad == 1) apilar(pila1,num);
        else if (prioridad ==2) apilar(pila2,num);
        int longPila1 = longitud(pila1);
        int longPila2 = longitud(pila2);
        if(longPila1 == 3 or longPila2 == 3) break;
    }
}
void ObtenerDatos(Pila &pila, int &numInc, int &codigo){
    codigo = desapilar(pila);
    numInc = codigo%100;
}
void OrdenarPila(Pila &pila,Pila pilaAux){
    int numIncPila,codigoPila, numIncAux,codigoAux;
    if(esPilaVacia(pilaAux)) apilar(pilaAux,desapilar(pila));
    while(!esPilaVacia(pila)){
        ObtenerDatos(pila,numIncPila,codigoPila);
        ObtenerDatos(pilaAux,numIncAux,codigoAux);
        if(numIncAux<numIncPila){
            apilar(pilaAux,codigoAux);
            apilar(pilaAux,codigoPila);
        } else {
            if(!esPilaVacia(pilaAux)){
                apilar(pilaAux,codigoPila);
                apilar(pilaAux,codigoAux);
            } else {
                int n=0;
                apilar(pila,codigoAux);
                while(!esPilaVacia(pilaAux)){
                    apilar(pila,desapilar(pilaAux));
                    n++;
                }
                apilar(pilaAux,codigoPila);
                for(int i=0;i<n+1;i++) apilar(pilaAux,desapilar(pila));
            }
        }
    }
    while(!esPilaVacia(pilaAux))apilar(pila,desapilar(pilaAux));
}
void ReiniciarCola(Cola &cola,Pila &pila1,Pila &pila2){
    //PASO 1
    while(!esPilaVacia(pila2)) apilar(pila1,desapilar(pila2));
    //PASO 2
    OrdenarPila(pila1,pila2);
    //PASO 3
    int distancia = longitud(cola)-longitud(pila1);
    // parte Azul
    for(int i=0;i<distancia;i++) encolar(cola,desencolar(cola));
    for(int i=0;i<longitud(pila1);i++) apilar(pila2,desencolar(cola)); 
    //Parte Verde 
    while(!esPilaVacia(pila1)) encolar(cola, desapilar(pila1));
    //Parte Anaranjado
    for(int i=0;i<distancia;i++) encolar(cola,desencolar(cola));
}
void ReclasificarPilas(Pila &pila1,Pila &pila2){
    Cola colaAux;
    construir(colaAux);
    while(!esPilaVacia(pila2)){
        int codigo = desapilar(pila2);
        int prioridad = codigo/100;
        if(prioridad == 2) apilar(pila1,codigo);
        else  encolar(colaAux,codigo);
    }
    while(!esColaVacia(colaAux)) apilar(pila2,desencolar(colaAux));
}
int main(int argc, char** argv) {
    int ArrDatos[N] = {101,102,203,204,105,206,107,208,109,210,211,112,113};
    Cola regIncidentes;
    construir(regIncidentes);
    for(int i=0;i<N;i++){
        encolar(regIncidentes,ArrDatos[i]);
    }
    //Colocarlo en las pilas por niveles
    Pila pila1,pila2;
    construir(pila1);
    construir(pila2);
    
    reclasificarAPilas(regIncidentes,pila1,pila2);
    cout<<"INICIAL:"<<endl;
    ImprimirFases(regIncidentes,pila1,pila2);
    
    ReiniciarCola(regIncidentes,pila1,pila2);
    cout<<endl<<"REINICIAR COLA:"<<endl;
    ImprimirFases(regIncidentes,pila1,pila2);
    
    ReclasificarPilas(pila1,pila2);
    cout<<endl<<"RECLASIFICA COLA:"<<endl;
    ImprimirFases(regIncidentes,pila1,pila2);
    

    return 0;
}


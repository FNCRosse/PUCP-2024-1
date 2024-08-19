/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 15 de mayo de 2024, 17:23
 */

#include <iostream>
using namespace std;
#include "Lista.h"
#include "Pila.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
#include "Nodo.h"

void hanoi(int n, Pila &desde, Pila &hasta, Pila Aux){
    if(n == 1){
        apilar(hasta,desapilar(desde));
        return;
    }
    hanoi(n-1,desde,Aux,hasta);
    apilar(hasta,desapilar(desde));
    hanoi(n-1,Aux,hasta,desde);
}
void hanoi2PA(int n, Pila &desde, Pila &hasta, Pila &Aux1,Pila &Aux2){
    if(n ==0) return;
    if(n == 1){
        apilar(hasta,desapilar(desde));
        return;
    }
    hanoi2PA(n-2,desde,Aux1,Aux2,hasta);
    apilar(Aux2,desapilar(desde));
    apilar(hasta,desapilar(desde));
    apilar(hasta,desapilar(Aux2));
    hanoi2PA(n-2,Aux1,hasta,desde,Aux2);
}
void hanoi3PA(int n, Pila &desde, Pila &hasta, Pila &Aux1,Pila &Aux2,Pila &Aux3){
    if(!n) return;
    if(n == 1){
        apilar(hasta,desapilar(desde));
        return;
    }
    hanoi3PA(n-3,desde,Aux1,Aux2,Aux3,hasta);
    apilar(Aux3,desapilar(desde));
    apilar(Aux2,desapilar(desde));
    apilar(hasta,desapilar(desde));
    apilar(hasta,desapilar(Aux2));
    apilar(hasta,desapilar(Aux3));
    hanoi3PA(n-3,Aux1,hasta,desde,Aux3,Aux2);
}

int ObtenerUltimoNodo(Lista &faja){
    Nodo * ultimo = nullptr;
    Nodo * Penultimo = nullptr;
    Nodo *recorrer =faja.cabeza;
    while (recorrer!=nullptr) {
        if(ultimo != nullptr) Penultimo = ultimo;
        ultimo = recorrer;
        recorrer = recorrer->siguiente;
    }
    if(ultimo != nullptr){
        if(Penultimo == nullptr) faja.cabeza = nullptr; //en caso solo quede uno
        else Penultimo->siguiente =nullptr;
        faja.longitud--;
    }
    return ultimo->elemento;
}
void HEX1(Lista &faja,Pila &pila){
    Pila aux1,aux2;
    construir(aux1);
    construir(aux2);
    while(!esListaVacia(faja)){
        int cont=0;
        int Mano = ObtenerUltimoNodo(faja);
        if(esPilaVacia(pila) || Mano<=cima(pila)){
            apilar(pila,Mano);
        } else {
            while(!esPilaVacia(pila) && Mano > cima(pila)){
                int aux = desapilar(pila);
                apilar(aux1,aux);
                if(cont >0){
                    hanoi(cont,aux2,aux1,pila);
                }
                cont++;
                hanoi(cont,aux1,aux2,pila);
            }
            apilar(pila,Mano);
            hanoi(cont,aux2,pila,aux1);
        }
    }
}
void HEX2(Lista &faja,Pila &pila){
    Pila aux1,aux2,aux3;
    construir(aux1);
    construir(aux2);
    construir(aux3);
    while(!esListaVacia(faja)){
        int cont=0;
        int Mano = ObtenerUltimoNodo(faja);
        if(esPilaVacia(pila) || Mano<=cima(pila)){
            apilar(pila,Mano);
        } else {
            while(!esPilaVacia(pila) && Mano > cima(pila)){
                int aux = desapilar(pila);
                apilar(aux1,aux);
                if(cont >0){
                    hanoi2PA(cont,aux2,aux1,pila,aux3);
                }
                cont++;
                hanoi2PA(cont,aux1,aux2,pila,aux3);
            }
            apilar(pila,Mano);
            hanoi2PA(cont,aux2,pila,aux1,aux3);
        }
    }
}

int main(int argc, char** argv) {
    int Datos[6] = {2,8,10,8,5,3};
    Lista faja;
    Pila pila;
    construir(faja);
    construir(pila);
    for(int i=0;i<6;i++){
        insertarAlInicio(faja,Datos[i]);
    }
    imprime(faja);
    //HEX1(faja,pila);
    HEX2(faja,pila);
    imprimir(pila);
    
    return 0;
}


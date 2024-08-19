/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 15 de mayo de 2024, 20:53
 */

#include <iostream>
#include "Lista.h"
using namespace std;
#include "Nodo.h"
#include "funcionesLista.h"
#include "Pila.h"
#include "funcionesPila.h"
void Hanoi (int n,Pila & Desde,Pila & hasta,Pila &Aux1,Pila &Aux2){
    if(n == 0) return;
    if(n==1) {
        apilar(hasta,desapilar(Desde));
        return;
    }
    Hanoi(n-2,Desde,Aux1,Aux2,hasta);
    apilar(Aux2,desapilar(Desde));
    apilar(hasta,desapilar(Desde));
    apilar(hasta,desapilar(Aux2));
    Hanoi(n-2,Aux1,hasta,Desde,Aux2);
}
struct Producto ObtenerUltimoProd(Lista &Faja){
    Nodo *Penultimo = nullptr;
    Nodo *Ultimo = nullptr;
    Nodo *Recorrido = Faja.cabeza;
    while(Recorrido != nullptr){
        if(Ultimo != nullptr) Penultimo = Ultimo;
        Ultimo = Recorrido;
        Recorrido = Recorrido->siguiente;
    }
    if(Ultimo != nullptr){
        if(Penultimo == nullptr) Faja.cabeza =nullptr;
        else Penultimo->siguiente = nullptr;
        Faja.longitud--;
    } 
    return Ultimo->elemento;
}
bool CumpleRequisitos(Producto mano, Producto top){
    if(mano.peso > top.peso){
        return true; 
    } else if (mano.peso == top.peso && mano.calidad > top.calidad){
        return true;
    } else {
        return false;
    }
}
void Hanoi3(Lista &Faja,Pila &pila){
    struct Producto top ;    Pila Aux1,Aux2,Aux3;
    construir(Aux1);
    construir(Aux2);
    construir(Aux3);
    while (!esListaVacia(Faja)) {
        struct Producto mano = ObtenerUltimoProd(Faja);
        int cont =0;
        if(esPilaVacia(pila)){
            apilar(pila,mano);
        } else if((mano.peso == cima(pila).peso && mano.calidad<=cima(pila).calidad) || (mano.peso < cima(pila).peso)){
             apilar(pila,mano);
        } else {
            while(!esPilaVacia(pila) && CumpleRequisitos(mano,cima(pila))){
                struct Producto aux = desapilar(pila);
                apilar(Aux1,aux);
                if(cont >0){
                    Hanoi(cont,Aux2,Aux1,pila,Aux3);
                }
                cont++;
                Hanoi(cont,Aux1,Aux2,pila,Aux3);
            }
             apilar(pila,mano);
             Hanoi(cont,Aux2,pila,Aux1,Aux3);
        }
    }

}
int main(int argc, char** argv) {
    struct Producto Datos[7] = {{1,50},{2,100},{1,200},{1,150},{2,50},{2,200},{1,100}};
    Lista Faja;
    Pila pila;
    construir(Faja);
    construir(pila);
    for(int i=0;i<7;i++) insertarAlInicio(Faja,Datos[i]);
    Hanoi3(Faja,pila);
    imprimir(pila);
    return 0;
}


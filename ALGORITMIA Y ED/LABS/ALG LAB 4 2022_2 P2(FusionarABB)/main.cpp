/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
void plantarArbolBinario(struct NodoArbol *& arbol, struct NodoArbol * izquierdo,
                         Lote elemento, struct NodoArbol * derecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(izquierdo, elemento, derecho);
    arbol = nuevoNodo;
}
void InsertarDatoRecursivo(NodoArbol *&nodo,Lote Datos){
    if(esNodoVacio(nodo)){
        plantarArbolBinario(nodo,nullptr,Datos,nullptr);
    } else if (nodo->elemento.fecha > Datos.fecha){
        InsertarDatoRecursivo(nodo->izquierda,Datos);
    } else if (nodo->elemento.fecha < Datos.fecha){
        InsertarDatoRecursivo(nodo->derecha,Datos);
    }
}
void InsertarDatos(ArbolBinario &Destino,Lote Datos){
    InsertarDatoRecursivo(Destino.raiz,Datos);
}
int ComparacionABB(Lote A,Lote B){
    if(A.fecha == B.fecha) return 0;
    else if (A.fecha < B.fecha) return -1;
    else if (A.fecha > B.fecha) return  1;
}
bool BuscarElemento(NodoArbol *&Destino,Lote valor){
    if(esNodoVacio(Destino)) return false;
    if((ComparacionABB(Destino->elemento,valor))==0){
        Destino->elemento.cantidad += valor.cantidad;
        return true;
    }
    else if((ComparacionABB(Destino->elemento,valor)) ==-1) return BuscarElemento(Destino->derecha,valor);
    else if((ComparacionABB(Destino->elemento,valor)) == 1) return BuscarElemento(Destino->izquierda,valor);
}
void FusionarArbolesRecursivo(NodoArbol *&Destino,NodoArbol *&Emisor){
    Lote valor;
    struct NodoArbol *Aux;
    Aux = Emisor;
    if(Emisor){
        FusionarArbolesRecursivo(Destino,Emisor->izquierda);
        FusionarArbolesRecursivo(Destino,Emisor->derecha);
        valor = Aux->elemento;
        if(!BuscarElemento(Destino,valor)){
            InsertarDatoRecursivo(Destino,valor);
        }
    }
}
void FusionarArboles(ArbolBinario &Destino,ArbolBinario &Emisor){
    FusionarArbolesRecursivo(Destino.raiz,Emisor.raiz);
}
int main(int argc, char** argv) {
    struct ArbolBinario Destino,Emisor;
    construir(Destino);
    construir(Emisor);
    //Parte A
    Lote DatosDes[4]={{20180211,20},{20170810,20},{20180409,10},{20170620,20}};
    for(int i=0;i<4;i++) InsertarDatos(Destino,DatosDes[i]);
    recorrerEnOrden(Destino);
    cout<<endl;
    Lote DatosEmi[3]={{20170811,5},{20180211,10},{20180410,15}};
    for(int i=0;i<4;i++) InsertarDatos(Emisor,DatosEmi[i]);
    recorrerEnOrden(Emisor);
    cout<<endl<<endl;
    FusionarArboles(Destino,Emisor);
    recorrerEnOrden(Destino);
    
    return 0;
}


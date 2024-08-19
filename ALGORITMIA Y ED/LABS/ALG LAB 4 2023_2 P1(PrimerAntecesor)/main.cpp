/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"

int ObtenerMayor(NodoArbol *nodo) {
    if (esNodoVacio(nodo)) return 0;
    if (esNodoVacio(nodo->derecha)) return nodo->elemento;
    ObtenerMayor(nodo->derecha);
}

void plantarArbolBinario(struct NodoArbol *& arbol, struct NodoArbol * izquierdo,
        int elemento, struct NodoArbol * derecho) {

    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(izquierdo, elemento, derecho);
    arbol = nuevoNodo;
}

void insetarRecursivo(NodoArbol *&nodo, int Codigo) {
    if (esNodoVacio(nodo)) {
        plantarArbolBinario(nodo, nullptr, Codigo, nullptr);
    }  else if (nodo->elemento > Codigo) insetarRecursivo(nodo->izquierda, Codigo);
    else insetarRecursivo(nodo->derecha, Codigo);
}

void InsertarArbol(ArbolBinario &Token, int Codigo) {
    insetarRecursivo(Token.raiz, Codigo);
}
NodoArbol * ObtenerRaiz(ArbolBinario arbol){
    return arbol.raiz;
}
NodoArbol * Busca_primer_ancestro_comun(NodoArbol *RaizToken,int num1,int num2){
    if(esNodoVacio(RaizToken)) return nullptr;
    if(num1 < RaizToken->elemento and num2 <RaizToken->elemento){
        return Busca_primer_ancestro_comun(RaizToken->izquierda,num1,num2);
    } else if (num1> RaizToken->elemento and num2> RaizToken->elemento){
        return Busca_primer_ancestro_comun(RaizToken->derecha,num1,num2);
    }
    return RaizToken;
}
void SumaParcialRecursivo(NodoArbol *&Token,NodoArbol *&Sistema){
    if(esNodoVacio(Sistema)) return;
    if(!esNodoVacio(Token)) Token->elemento+=Sistema->elemento;
    if(esNodoVacio(Token) and !esNodoVacio(Sistema)){
        plantarArbolBinario(Token,nullptr,Sistema->elemento,nullptr);
    }
    SumaParcialRecursivo(Token->izquierda,Sistema->izquierda);
    SumaParcialRecursivo(Token->derecha,Sistema->derecha);
}
void ObtenerArbolesParciales(NodoArbol *&Token,NodoArbol *&Sistema,int ancestro){
    if(esNodoVacio(Token)) return;
    if(Token->elemento == ancestro){
        SumaParcialRecursivo(Token,Sistema);
        return;
    }
    else if(Token->elemento > ancestro) ObtenerArbolesParciales(Token->izquierda,Sistema->izquierda,ancestro);
    else  ObtenerArbolesParciales(Token->derecha,Sistema->derecha,ancestro);
}
bool VerificarABB(NodoArbol *Token,NodoArbol *Prev){
    if(esNodoVacio(Token)) return true;
    if(!VerificarABB(Token->izquierda,Prev)) return false;
    if(!esNodoVacio(Prev) and Token->elemento <= Prev->elemento) return false;
    Prev = Token;
    return VerificarABB(Token->derecha,Prev);
}
bool suma_parcial_arboles(ArbolBinario &Token,ArbolBinario &Sistema,NodoArbol *PrAntComun){
    ObtenerArbolesParciales(Token.raiz,Sistema.raiz,PrAntComun->elemento);
    NodoArbol *prev =nullptr;
    return VerificarABB(Token.raiz,prev);
}
int main(int argc, char** argv) {
    struct ArbolBinario Token;
    construir(Token);
    int Codigos[8] = {5, 2, 12, 1, 3, 8, 18, 4};
    for (int i = 0; i < 8; i++) InsertarArbol(Token, Codigos[i]);
    recorrerEnOrden(Token);
    cout << endl;
    NodoArbol * RaizToken = ObtenerRaiz(Token);
    NodoArbol * PrAncComun =  Busca_primer_ancestro_comun(RaizToken,1,4);
    if(PrAncComun){
        ArbolBinario Sistema;
        construir(Sistema);
        int codSistema[8]={4,-2,6,-3,-1,5,7,0};
        for (int i = 0; i < 8; i++) InsertarArbol(Sistema, codSistema[i]);
        if(suma_parcial_arboles(Token,Sistema,PrAncComun)){
            cout<<"Acceso Otorgado"<<endl;
        } else {
            cout<<"Acceso Denegado"<<endl;
        }
    } else {
        cout<<"Acceso Denegado"<<endl;
    }


    return 0;
}


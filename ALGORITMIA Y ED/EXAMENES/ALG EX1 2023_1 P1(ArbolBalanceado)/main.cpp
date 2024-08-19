/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
int ObtenerMayorNodo(NodoArbol *nodo){
    if(esNodoVacio(nodo)) return 0;
    if(esNodoVacio(nodo->derecha)) return nodo->elemento;
    ObtenerMayorNodo(nodo->derecha);
}
void plantarArbolBinario(struct NodoArbol *& arbol, struct NodoArbol * izquierdo,
                         int elemento, struct NodoArbol * derecho){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol(izquierdo, elemento, derecho);
    arbol = nuevoNodo;
}
void Inserta_nodo(NodoArbol *&nodo,int Codigo){
    if(esNodoVacio(nodo)){
        plantarArbolBinario(nodo,nullptr,Codigo,nullptr);
    } else if (nodo->elemento == Codigo){
        int mayor = ObtenerMayorNodo(nodo);
        Codigo+=mayor;
        if(nodo->elemento > Codigo) Inserta_nodo(nodo->izquierda,Codigo);
        else if(nodo->elemento < Codigo) Inserta_nodo(nodo->derecha,Codigo);
    } else if(nodo->elemento > Codigo){
        Inserta_nodo(nodo->izquierda,Codigo);
    } else {
        Inserta_nodo(nodo->derecha,Codigo);
    }
}
void InsertarArbol(ArbolBinario &arbol,int Codigo){
    Inserta_nodo(arbol.raiz,Codigo);
}
void  RotarIzquierda(NodoArbol *&nodo){
    NodoArbol *nodoDer = nodo->derecha;
    nodo->derecha = nodoDer->izquierda;
    nodoDer->izquierda = nodo;
    nodo = nodoDer;
}
void  RotarDerecha(NodoArbol *&nodo){
    NodoArbol *nodoIzq = nodo->izquierda;
    nodo->izquierda = nodoIzq->derecha;
    nodoIzq->derecha = nodo;
    nodo = nodoIzq;
}
void RotaDobleDerecha(NodoArbol *&nodo){
    RotarIzquierda(nodo->izquierda);
     RotarDerecha(nodo);
}
void RotaDobleIzquierda(NodoArbol *&nodo){
    RotarDerecha(nodo->derecha);
    RotarIzquierda(nodo);
}
int calcularAltura(NodoArbol* nodo) {
    if (nodo == NULL)
        return 0;
    else {
        int alturaIzq = calcularAltura(nodo->izquierda);
        int alturaDer = calcularAltura(nodo->derecha);
        return max(alturaIzq, alturaDer) + 1;
    }
}
void BalancearNodo(NodoArbol *&nodo){
    int alturaIzq = alturaRecursivo(nodo->izquierda);
    int alturaDer = alturaRecursivo(nodo->derecha);
    int diferencia = alturaIzq-alturaDer;
    if(diferencia > 1){ 
        // es decir Alt Izq es mayor que la Derecha es decir hay un desequilibrio a la izquierda
        //Entonces tengo que rotar a la derecha
        if(alturaRecursivo(nodo->izquierda->izquierda) >= alturaRecursivo(nodo->izquierda->derecha)){
            RotarDerecha(nodo);
        } else {
            RotaDobleDerecha(nodo);
        }
    } else if( diferencia < -1){
        // es decir Alt Der es mayor que la izquierda es decir hay un desequilibrio a la derecha
        // Entonces tengo que rotar a la izquierda
        if(alturaRecursivo(nodo->derecha->derecha) >= alturaRecursivo(nodo->derecha->izquierda)){
            RotarIzquierda(nodo);
        } else {
            RotaDobleIzquierda(nodo);
        }
    }
}
void BalancearArbolRecursivo(NodoArbol *&raiz){
    if(esNodoVacio(raiz)) return;
    BalancearArbolRecursivo(raiz->izquierda);
    BalancearArbolRecursivo(raiz->derecha);
    BalancearNodo(raiz);
}
void BalancearArbol(ArbolBinario &Token){
    BalancearArbolRecursivo(Token.raiz);
}
void SumarArbolesRecursivo(NodoArbol *&Token,NodoArbol *&Sistema){
    if (esNodoVacio(Sistema)) return;
    if(!esNodoVacio(Token)) Token->elemento += Sistema->elemento;
    if (esNodoVacio(Token) && !esNodoVacio(Sistema)){
        plantarArbolBinario(Token,nullptr, Sistema->elemento,nullptr);
    }
    SumarArbolesRecursivo(Token->izquierda,Sistema->izquierda);
    SumarArbolesRecursivo(Token->derecha,Sistema->derecha);
}
bool VerificarABB(NodoArbol *Token,NodoArbol*&prev){
    if(Token == nullptr) return true;
    if(!VerificarABB(Token->izquierda,prev)) return false;
    if(!esNodoVacio(prev) && Token->elemento<= prev->elemento) return false;
    prev = Token;
    return VerificarABB(Token->derecha,prev);
}
bool Suma_Arboles(ArbolBinario &Token,ArbolBinario &Sistema){
    SumarArbolesRecursivo(Token.raiz,Sistema.raiz);
    NodoArbol *prev = nullptr;
    if(VerificarABB(Token.raiz,prev)) return true;
    else return false;
}
int main(int argc, char** argv) {
    struct ArbolBinario Token,Sistema1,Sistema2;
    construir(Token);
    construir(Sistema1);
    construir(Sistema2);
    //Parte A:
    int Codigo[8]={2,5,2,1,5,6,3,4};
    int CodSistma1[7]={3,1,5,2,4,6,7};
    int CodSistma2[7]={4,1,6,2,5,7,3};
    for(int i=0;i<7;i++){
        InsertarArbol(Sistema1,CodSistma1[i]);
        InsertarArbol(Sistema2,CodSistma2[i]);
    }
    for(int i=0;i<8;i++){
        InsertarArbol(Token,Codigo[i]);
    }
    cout<<"Token: ";
    recorrerEnOrden(Token);
    cout<<endl<<"Sistema 1: ";
    recorrerEnOrden(Sistema1);
    cout<<endl<<"Sistema 2: ";
    recorrerEnOrden(Sistema2);
    cout<<endl;
    //Parte B
    cout<<endl<<"Arbol Balanceado: ";
    BalancearArbol(Token);
    recorrerEnOrden(Token);
    cout<<endl;
    //Parte C
    cout<<"Acceso de Sistema 1: ";
    if(Suma_Arboles(Token,Sistema1)){
        cout<<"Ese le permite acceso al usuario"<<endl;
    } else {
        cout<<"NO se le da acceso al usuario"<<endl;
    }
    cout<<"Acceso de Sistema 2: ";
//    if(Suma_Arboles(Token,Sistema2)){
//        cout<<"Se le permite acceso al usuario"<<endl;
//    } else {
//        cout<<"NO se le da acceso al usuario"<<endl;
//    }
    
    return 0;
}


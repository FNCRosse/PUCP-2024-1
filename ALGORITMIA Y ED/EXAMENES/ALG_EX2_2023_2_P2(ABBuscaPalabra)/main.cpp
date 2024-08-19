/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cstring>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
#include "Lista.h"
#include "funcionesLista.h"

char* TranformarPtr(char elem){
    char* ptr = new char[2];
    ptr[0] = elem;
    ptr[1] = '\0';
    return ptr;
}

bool buscarPalabraEnArbol(struct NodoArbol * nodo,struct Lista &letras) {
    char* elemento = TranformarPtr(raiz(nodo));
    bool EsElimnadoDeLaLista = EliminarLetra(letras, elemento);
    
    if(esListaVacia(letras)){
        EsElimnadoDeLaLista = false;
        return true;
    }
    
    if(EsElimnadoDeLaLista){
        if(nodo->izquierda != nullptr and BuscaLetra(letras,TranformarPtr(raiz(nodo->izquierda))))
            return buscarPalabraEnArbol(nodo->izquierda,letras);
        if(nodo->derecha != nullptr and BuscaLetra(letras, TranformarPtr(raiz(nodo->derecha))))
            return buscarPalabraEnArbol(nodo->derecha,letras);  
    }
}
bool ExistePalabra(const char *palabra, struct ArbolBinario arbol){
    Lista letras;
    construir(letras);
    for(int i=0;i<strlen(palabra);i++){
        char *letra = TranformarPtr(palabra[i]);
        insertarAlFinal(letras,letra);
    }
    return buscarPalabraEnArbol(arbol.raiz,letras);
}
int main(int argc, char** argv) {

    struct ArbolBinario arbol;
    construir(arbol);
    struct ArbolBinario aux1,aux2,aux3,aux4,aux5,aux6,aux7,aux8,aux9,aux10,aux11,aux12,aux13,aux14;
    plantarArbolBinario(aux1,nullptr,'T',nullptr);
    plantarArbolBinario(aux2,aux1.raiz,'G',nullptr);
    plantarArbolBinario(aux3,nullptr,'R',nullptr);
    plantarArbolBinario(aux4,aux3,'E',aux2);
    plantarArbolBinario(aux5,nullptr,'E',nullptr);
    plantarArbolBinario(aux6,aux5,'D',aux4);
    
    plantarArbolBinario(aux7,nullptr,'F',nullptr);
    plantarArbolBinario(aux8,nullptr,'T',nullptr);
    plantarArbolBinario(aux9,aux7,'A',aux8);
    plantarArbolBinario(aux10,aux9.raiz,'N',nullptr);
    
    plantarArbolBinario(aux11,nullptr,'O',nullptr);
    plantarArbolBinario(aux12,aux11.raiz,'C',nullptr);
    plantarArbolBinario(aux13,aux12.raiz,'C',nullptr);
    plantarArbolBinario(aux14,aux13,'I',aux10);
    plantarArbolBinario(arbol, aux6, 'L',aux14);
    
    char palabras [10][10] ={{"HIJO"},{"FINAL"},{"MUNDO"},{"DEL"},{"DIA"},{"CICLO"}};
    Lista mensajeOculto;
    construir(mensajeOculto);
    for(int i=0;i<6;i++){
        if(ExistePalabra(palabras[i],arbol)){
            insertarAlFinal(mensajeOculto,palabras[i]);
        }
    }
    if(esListaVacia(mensajeOculto)){
        cout<<"No se pudo encontrar el mensaje oculto";
    } else {
        cout<<"Si se pudo encontrar el mensaje oculto: ";
        imprime(mensajeOculto);
    }
    return 0;
}


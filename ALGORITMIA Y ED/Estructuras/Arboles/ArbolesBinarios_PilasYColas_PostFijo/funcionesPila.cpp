/* 
 * File:   funcionesPilas.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "Nodo.h"
#include "ListaP.h"
#include "Pila.h"
using namespace std;
#include "funcionesListaP.h"
#include "funcionesPila.h"

/*constructor de Pila*/
void construir(struct Pila & pila){
    construirP(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia( struct Pila  pila){
    return esListaVaciaP(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud( struct Pila   pila){
    return longitudP(pila.lista);
}

/*push, añade un elemento a la parte superior de la pila*/
void apilar(struct Pila & pila, struct NodoArbol * nodo){
    insertarAlInicio(pila.lista, nodo);
}

/*pop, elimina un elemento de la parte superior de la pila*/
struct NodoArbol * desapilar(struct Pila & pila){
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
	exit(11);
    }	
    struct NodoArbol * nodo = cima(pila);
    eliminaCabezaP(pila.lista);
    return nodo;
}

/*examina un elemento situado en la parte superior de la pila*/
struct NodoArbol * cima(struct Pila pila){
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
	exit(12);
    }		
    return retornaCabezaP(pila.lista);
}


/*destruye la pila*/
void destruirPila(struct Pila pila){
    destruir(pila.lista);
}

/*Recordar que las Pilas no se recorren en forma secuencial*/
/*Se va utilizar solo para mostrar los valores*/
void imprimir(const struct Pila & pila){
    imprimeP(pila.lista);
}

///*imprime desapilando*/
//void imprime(struct Pila & pila){
//    
//    while(not esPilaVacia(pila)){
//        cout<<cima(pila)<<"-";
//        desapilar(pila);
//    }
//}


/* 
 * File:   funcionesPilas.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Posicion.h"
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
using namespace std;
#include "funcionesPosicion.h"
#include "funcionesLista.h"
#include "funcionesPila.h"

/*constructor de Pila*/
void construir(struct Pila & pila){
    construir(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia(struct Pila pila){
    return esListaVacia(pila.lista);
}

/*Determina el número de elementos de la pila*/
int longitud(struct Pila pila){
    return longitud(pila.lista);
}

/*push, añade un elemento a la parte superior de la pila*/
void apilar(struct Pila & pila, struct Posicion posicion){
    insertarAlInicio(pila.lista, posicion);
}

/*pop, elimina un elemento de la parte superior de la pila*/
struct Posicion desapilar(struct Pila & pila){
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
	exit(1);
    }	
    struct Posicion posicion = cima(pila);
    eliminaCabeza(pila.lista);
    return posicion;
}

/*examina un elemento situado en la parte superior de la pila*/
struct Posicion cima(const struct Pila & pila){
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
	exit(1);
    }		
    return retornaCabeza(pila.lista);
}

/*destruye la pila*/
void destruirPila(struct Pila & pila){
    destruir(pila.lista);
}
//
//void imprime(struct Pila pila){
//    
//    while(not esPilaVacia(pila)){
//        cout<<cima(pila)<<"-";
//        desapilar(pila);
//    }
//}
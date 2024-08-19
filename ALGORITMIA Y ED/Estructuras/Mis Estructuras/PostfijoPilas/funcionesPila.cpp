/* 
 * File:   funcionesPilas.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Nodo.h"
#include "Lista.h"
#include "Pila.h"
using namespace std;
#include "funcionesLista.h"
#include "funcionesPila.h"
#define MAX 10

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
void apilar(struct Pila & pila, int elemento){
    insertarAlInicio(pila.lista, elemento);
}

/*pop, elimina un elemento de la parte superior de la pila*/
int desapilar(struct Pila & pila){
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
	exit(11);
    }	
    int elemento = cima(pila);
    eliminaCabeza(pila.lista);
    return elemento;
}

/*examina un elemento situado en la parte superior de la pila*/
int cima(const struct Pila & pila){
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
	exit(12);
    }		
    return retornaCabeza(pila.lista);
}

/*destruye la pila*/
void destruirPila(struct Pila & pila){
    destruir(pila.lista);
}

void imprime(struct Pila pila){
    imprime(pila.lista);
}

int esOperador(char * c){
    return (strcmp(c,"+") == 0) or (strcmp(c,"-") == 0) or 
           (strcmp(c,"*") == 0) or (strcmp(c,"/") == 0);
}

int opera(char * c, int operando1, int operando2){
    int resultado = 0;
   
    if (strcmp(c, "+") == 0) 
        resultado = operando1 + operando2;
    else if (strcmp(c, "-") == 0) 
        resultado = operando1 - operando2;
    else if (strcmp(c, "*") == 0) 
        resultado = operando1 * operando2;
    else if(strcmp(c, "/") == 0) 
        resultado = operando1 / operando2;
    
    return resultado;
}

void notacionPostfija(struct Pila & pila){
    
    int operando2;
    int operando1;
    int resultado ;
  
    char elemento[MAX];
    
    cout<<"Ingrese expresi�n en postfijo: "<<endl;
   
    while (!cin.eof()){
        cin>>elemento; //lee un elemento de la expresión
        if (cin.eof()) break;
        /*si no hay dos elementos al desapilar debería dar un error*/
        if (esOperador(elemento)){ 
            operando2 = desapilar(pila);
            operando1 = desapilar(pila);
            resultado = opera(elemento, operando1, operando2);
            apilar(pila, resultado);
        }
        else{
            apilar(pila, atoi(elemento)); // atoi sirve para char * 
            
        }
        imprime(pila);   /*OBSERVAR LOS CAMBIOS EN LA PILA*/
    }
    
}

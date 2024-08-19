/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:28 AM
 */

#include <cstdlib>
#include <iostream>
#include "Lista.h" /*necesitamos incluir a la lista*/
#include "Pila.h"
using namespace std;
#include "funcionesPila.h"
#include "funcionesLaberinto.h"
/*
 *Laberinto usando PILAS 
 */
int main(int argc, char** argv) {
    
    struct Pila pila;
    
    construir(pila);
    int tablero[3][5] = {{1, 0, 1, 1, 1},
                         {1, 1, 1, 0, 1},
                         {0, 0, 1, 0, 1}};
    bool terminado;
    
    mostrar(tablero);
    terminado = laberinto(pila, tablero, 0, 0);
    if(terminado)
        mostrar(tablero);
    else
        cout<<"No fue posible terminar el laberinto";
    destruirPila(pila);
    return 0;
}

/* 
 * File:   Posicion.h
 * Author: ANA RONCAL
 * Created on 4 de septiembre de 2023, 11:24 PM
 */

#ifndef POSICION_H
#define POSICION_H

struct Posicion{
    int x;
    int y;
};

#endif /* POSICION_H */

/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:28 AM
 */

#ifndef NODO_H
#define NODO_H

struct Nodo{
    struct Posicion posicion; //Elemento de la lista
    struct Nodo * siguiente;
};

#endif /* NODO_H */

/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:28 AM
 */

#ifndef LISTA_H
#define LISTA_H

struct Lista{
    struct Nodo * cabeza;
    int longitud;
};

#endif /* LISTA_H */

/* 
 * File:   Pilas.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:33 AM
 */

#ifndef PILAS_H
#define PILAS_H

struct Pila{
    struct Lista lista;
};

#endif /* PILAS_H */

/* 
 * File:   funcionesPosicion.h
 * Author: ANA RONCAL
 * Created on 5 de septiembre de 2023, 09:10 AM
 */

#ifndef FUNCIONESPOSICION_H
#define FUNCIONESPOSICION_H

void constructor(struct Posicion & posicion, int x, int y);
int getX(struct Posicion posicion);
int getY(struct Posicion posicion);
void setX(struct Posicion posicion, int x);
void setY(struct Posicion posicion, int y);

#endif /* FUNCIONESPOSICION_H */

/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:32 AM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H


void construir(struct Lista &);

void insertarAlInicioArchivo(const char *, struct Lista &);

void insertarAlInicio(struct Lista &, struct Posicion);
void insertarAlFinal(struct Lista  &, int);
void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(struct Posicion, struct Nodo *);
struct Nodo * obtenerUltimoNodo(const struct Lista &);
struct Nodo * obtenerNodoAnterior(const struct Lista &, int);
struct Nodo * seEncuentra(const struct Lista &, int);

struct Posicion retornaCabeza(const struct Lista &);

bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

void eliminaNodo(struct Lista &, struct Posicion);
void eliminaCabeza(struct Lista  &);
void eliminaCola(struct Lista &);

void destruir(struct Lista &);
void imprime(const struct Lista &);                                  


#endif /* FUNCIONESLISTA_H */

/* 
 * File:   funcionesPilas.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:29 AM
 */

#ifndef FUNCIONESPILAS_H
#define FUNCIONESPILAS_H

void construir(struct Pila & );
int longitud(struct Pila );
bool esPilaVacia(struct Pila);
void apilar(struct Pila &, struct Posicion ); 
struct Posicion desapilar(struct Pila &);
struct Posicion cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprime(struct Pila );

#endif /* FUNCIONESPILAS_H */

/* 
 * File:   funcionesLaberinto.h
 * Author: ANA RONCAL
 * Created on 5 de septiembre de 2023, 08:47 AM
 */

#ifndef FUNCIONESLABERINTO_H
#define FUNCIONESLABERINTO_H

bool valida(int tablero[3][5], int fil, int col);
bool laberinto(struct Pila & pila, int tablero[3][5], int, int);
void mostrar(int tablero[3][5]);

#endif /* FUNCIONESLABERINTO_H */


#include "funcionesPosicion.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
#include "funcionesLaberinto.h"

void constructor(struct Posicion & posicion, int x, int y){
    
    posicion.x = x;
    posicion.y = y;
            
}

int getX(struct Posicion posicion){
    return posicion.x;
}

int getY(struct Posicion posicion){
    return posicion.y;
}

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

/* 
 * File:   funcionesLaberinto.cpp
 * Author: ANA RONCAL
 * Created on 5 de septiembre de 2023, 08:47 AM
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
#include "funcionesPila.h"
#include "funcionesLaberinto.h"


#define PROBADA 3
#define RUTA 7

bool valida(int tablero[3][5], int fil, int col){
    bool resultado = false;
    /*dentro de los límites de la matriz*/
    if(fil >= 0 and fil < 3 and col >= 0 and col < 5)
        if(tablero[fil][col] == 1) /* no es pared y no ha sido probada*/
            resultado = true;
    return resultado;
}

bool laberinto(struct Pila & pila, int tablero[3][5], int fil, int col){
    
    struct Posicion pos;
    constructor(pos, fil, col);
    bool terminado = false;
   struct Posicion posAux;
    apilar(pila, pos); //Guardamos la primera posicion
    
    while(not terminado){
        
        pos = desapilar(pila);
      
        tablero[getX(pos)][getY(pos)] = PROBADA; /* ya ha sido probada*/
        mostrar(tablero);
        if(getX(pos) == 2 and getY(pos) == 4) //verifica fin
            terminado = true;
        else{
            if(valida(tablero, getX(pos), getY(pos) + 1)){// arriba
               constructor(posAux, getX(pos), getY(pos) + 1);
               apilar(pila, posAux);
               tablero[getX(pos)][getY(pos)] = RUTA;
            }
            if(valida(tablero, getX(pos) -1 , getY(pos) )){ //izquierda
               constructor(posAux, getX(pos) -1 , getY(pos));
               apilar(pila, posAux);
               tablero[getX(pos)][getY(pos)] = RUTA;
            }
            if(valida(tablero, getX(pos), getY(pos) - 1)){//abajo
               constructor(posAux, getX(pos), getY(pos) - 1);
               apilar(pila, posAux);
               tablero[getX(pos)][getY(pos)] = RUTA;
            }
            if(valida(tablero, getX(pos) + 1, getY(pos))){//derecha
               constructor(posAux, getX(pos) + 1, getY(pos));
               apilar(pila, posAux);
               tablero[getX(pos)][getY(pos)] = RUTA;
            }
            
        }
        if(terminado)
            tablero[getX(pos)][getY(pos)] = RUTA;
    }
    return terminado;
}

void mostrar(int tablero[3][5]){
 
    for(int i = 0; i< 3; i++){
        for(int j = 0; j < 5; j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
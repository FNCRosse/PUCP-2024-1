/* 
 * File:   funcionesLista.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:11 PM
 */

#include <iostream>
#include <iomanip> /*formato de números*/
#include <fstream>
#include "Lista.h"
#include "funcionesLista.h"
#include "Cola.h"
using namespace std;
#define NOENCONTRADO -1
#define MAXDATOS 9

/*Valores iniciales de la lista*/
void construir(struct Lista & lista) {
    lista.cabeza = nullptr;
    lista.cola = nullptr; //puntero cola a null
    lista.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & lista) {
    return lista.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista & lista) {
    return lista.longitud;
}

/*inserta un nodo siempre al inicio de la lista*/
void insertarAlInicio(struct Lista & lista, int elemento) {

    /*Se va cambiar por la función crear nodo*/
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = lista.cabeza;

    lista.cabeza = nuevoNodo;
    lista.longitud++;
}

/*inserta un nodo siempre al final de la lista*/
void insertarAlFinal(struct Lista & lista, int elemento) {

    //struct Nodo * ultimoNodo = obtenerUltimoNodo(lista);
    struct Nodo * ultimoNodo = lista.cola; /*obtiene el último nodo*/
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr) {/*Si la lista está vacia*/
        lista.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        lista.cola = nuevoNodo;
    } else {//La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
        lista.cola = nuevoNodo;

    }
    lista.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(int elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

//Notar que esta función retorna nulo cuando la lista es vacía

/*Obtiene el último nodo de la lista*/
struct Nodo * obtenerUltimoNodo(const struct Lista & lista) {
    struct Nodo * ultimo = nullptr;
    struct Nodo* recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

/*inserta nodos al inicio de la lista desde un archivo*/
void insertarAlInicioArchivo(const char * nombArchText, struct Lista & lista) {
    ifstream archText(nombArchText, ios::in);
    if (not archText.is_open()) {
        cout << "ERROR: No se puede abrir el archivo";
        exit(1);
    }

    int elemento;
    while (true) {
        archText>>elemento; //lee el elemento del archivo
        if (archText.eof()) break;
        insertarAlInicio(lista, elemento);
    }
}

/*inserta un nodo en orden*/
void insertarEnOrden(struct Lista & lista, int elemento) {

    struct Nodo * nodoAnterior = obtenerNodoAnterior(lista, elemento);
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);
    /*Si nodoAnterior es igual a nulo, la lista está vacia, se debe
     insertar al inicio, no hay nodos menores que elemento*/
    if (nodoAnterior == nullptr) { /*la lista está vacia*/
        nuevoNodo->siguiente = lista.cabeza;
        lista.cabeza = nuevoNodo;
    } else {
        nuevoNodo->siguiente = nodoAnterior->siguiente;
        nodoAnterior->siguiente = nuevoNodo;
    }
    lista.longitud++;
}

/*retorna el anterior al que tiene el elemento*/
struct Nodo * obtenerNodoAnterior(const struct Lista & lista, int elemento) {
    struct Nodo * anterior = nullptr;
    struct Nodo * recorrido = lista.cabeza;
    while ((recorrido != nullptr) and (recorrido->elemento < elemento)) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    return anterior;
}

struct Nodo * seEncuentra(const struct Lista & lista, int elemento) {
    struct Nodo * recorrido = lista.cabeza;

    /*retorna el nodo correspondiente al elemento buscado*/
    while ((recorrido != nullptr) and (recorrido->elemento != elemento)) {
        recorrido = recorrido->siguiente;
    }
    return recorrido;
}

int retornaCabeza(const struct Lista & lista) {
    return lista.cabeza->elemento;
}

void eliminaCabeza(struct Lista & lista) {
    struct Nodo * nodoAEliminar = lista.cabeza;
    if (nodoAEliminar != nullptr) {
        lista.cabeza = lista.cabeza->siguiente;
        if (lista.cabeza == nullptr) /*falta añadir para que coloque*/
            lista.cola = nullptr; /*cola en null*/
        delete nodoAEliminar;
        lista.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista lista) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            lista.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        lista.longitud--;
    }
}

void destruir(struct Lista & lista) {
    /*recorrido apunta al inicio del lista*/
    struct Nodo * recorrido = lista.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    lista.cabeza = nullptr;
    lista.cola = nullptr;
    lista.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo lista.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & lista) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(lista)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = lista.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

//void merge(int arreglo[], int inicio, int centro, int fin) {
//    int i, p, q; //índices para los 3 arreglos
//    //i es para arreglo[]
//    //p es para arreglo[], mitad de la izquierda
//    //q es para arreglo[], mitad de la derecha
//
//    int longitud1, longitud2;
//    longitud1 = (centro + 1) - inicio;
//    longitud2 = fin - centro;
//
//    //establecemos 2 arreglos auxiliares para reordenar el arreglo[]
//    int P[longitud1 + 1]; //Un elemento más en el subarreglo con valor muuuuuy grande
//    int Q[longitud2 + 1]; //Un elemento más en el subarreglo con valor muuuuuy grande
//
//    P[longitud1] = 999999;
//    Q[longitud2] = 999999;
//
//    for (i = inicio; i < centro + 1; i++)
//        P[i - inicio] = arreglo[i]; //restamos inicio al índice para que comience desde 0 para P[]
//
//    for (i = centro + 1; i <= fin; i++)
//        Q[i - (centro + 1)] = arreglo[i]; //restamos centro+1 al índice para que comience desde 0 para Q[]
//
//    p = q = 0;
//
//    for (i = inicio; i <= fin; i++)
//        if (P[p] < Q[q])//Si el elemento de P[] es el menor, insertamos en arreglo[]
//            arreglo[i] = P[p++];
//        else//Si el elemento de Q[] es el menor, insertamos en arreglo[]
//            arreglo[i] = Q[q++];
//}
//
//void mergeSort(int arreglo[], int inicio, int fin) {
//    //CASO BASE
//    if (inicio == fin)//porque cuando tenemos sólo un elemento, ese elemento ya está ordenado.
//        return;
//
//    //identificamos la posición del medio
//    int centro = (inicio + fin) / 2;
//
//    mergeSort(arreglo, inicio, centro); //la mitad del arreglo de la IZQUIERDA
//    mergeSort(arreglo, centro + 1, fin); //la mitad del arreglo de la DERECHA
//    //hasta aqui el arreglo viene "ordenado por partes", necesitamos ordenarlo POR COMPLETO
//
//    merge(arreglo, inicio, centro, fin); //enviamos la posicion del medio pues es la que nos indica dónde están los 2 subarreglos ordenados por separado
//}

void merge(int * izquierda, int * derecha, int * solucion) {
    int izq = 0, der = 0, sol = 0;

    while (izquierda[izq] != 0 and derecha[der] != 0) {
        if (izquierda[izq] < derecha[der]) {
            solucion[sol] = izquierda[izq];
            izq++;
        } else {
            solucion[sol] = derecha[der];
            der++;
        }
        sol++;
    }

    while (izquierda[izq] != 0) {
        solucion[sol] = izquierda[izq];
        izq++;
        sol++;
    }

    while (derecha[der] != 0) {
        solucion[sol] = derecha[der];
        der++;
        sol++;
    }
    solucion[sol] = 0;
}

void mergeSort(int arreglo[], int longitud) {
    
    if (longitud <= 1) return;
    int i, centro = longitud / 2;
    
    int * izquierda = new int[centro];
    int * derecha = new int[longitud - centro];
      
    for (i = 0; i < centro; i++)    izquierda[i] = arreglo[i]; 
    izquierda[i] = 0;
    for (i = centro; i < longitud; i++)  derecha[i - centro] = arreglo[i];
    derecha[i - centro] = 0;
    
    mergeSort(izquierda, centro);
    mergeSort(derecha, longitud - centro);
    merge(izquierda, derecha, arreglo);

    delete [] izquierda;
    delete [] derecha; 
}

int busquedaBinaria(int arreglo[], int clave, int inicio, int fin) {
    //CASO BASE
    //cuando SE CRUZAN la inicial con la final
    if (inicio > fin)
        return NOENCONTRADO;
    int centro = (inicio + fin) / 2;
    if (arreglo[centro] == clave)
        return centro;
    else
        if (arreglo[centro] < clave)
        return busquedaBinaria(arreglo, clave, centro + 1, fin);
    else
        return busquedaBinaria(arreglo, clave, inicio, centro - 1);
}


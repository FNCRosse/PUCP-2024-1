/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de octubre de 2023, 19:45
 */

#include <iostream>
using namespace std;
#include "NodoArbol.h"
#include "ArbolBinario.h"
#include "FuncionesArbolBinario.h"
#include "FuncionesABBusqueda.h"

int main(int argc, char** argv) {
//------------------------------------------------------------------------------------------------------------//
//---------------------------------TEORIA ARBOLES BINARIOS--------------------------------------//
//------------------------------------------------------------------------------------------------------------//
    //Definir el arbol 
    struct ArbolBinario arbol;
    struct ArbolBinario arbol1,arbol2,arbol3,arbol4;
    contruir(arbol);
    cout<<"Es arbol vacio: "<<esArbolVacio(arbol)<<endl;
    // plantar el primer elemento (raiz)
    PlantarArbolBinario(arbol,nullptr,100,nullptr);
    //El hijo izquiedo de la raiz
    PlantarArbolBinario(arbol1,nullptr,25,nullptr); // hoja
    PlantarArbolBinario(arbol2,nullptr,75,nullptr); // hoja
    PlantarArbolBinario(arbol3,arbol1,50,arbol2); // 25 < 50 < 75
    //El hijo derecho de la raiz
    PlantarArbolBinario(arbol4,nullptr,150,nullptr); // hoja
    //unificar en el arbol, los 2 arbloles creados
    PlantarArbolBinario(arbol,arbol3,100,arbol4);
    
    cout<<"Es arbol vacio: "<<esArbolVacio(arbol)<<endl;
    //Tipo de Recorridos
    cout<<"Recorrer en Orden: "<<endl;
    recorrerEnOrden(arbol);
    cout<<"Recorrer en Pre-Orden: "<<endl;
    recorrerEnPreOrden(arbol);
    cout<<"Recorrer en Post-Orden: "<<endl;
    recorrerEnPostOrden(arbol); 
    cout<<"Recorrer por Niveles: "<<endl;
    recorrerPorNivel(arbol);
    cout<<endl<<"RECORRER ITERTIVOS"<<endl;
    cout<<"Recorrer Iterativo en Orden: "<<endl;
    recorreriIterativoEnOrden(arbol);
    cout<<"Recorrer Iterativo en Pre-Orden: "<<endl;
    recorreriIterativoEnPreOrden(arbol);
    cout<<"Recorrer MAYOR A MENOR: "<<endl;
    recorrerMayorAMenor(arbol);
    //Caracteristicas del arbol
    cout<<"La altura del arbol es :"<<Altura(arbol)<<endl;
    cout<<"Numero de nodo :"<<numeroNodos(arbol)<<endl;
    cout<<"Numero de hojas :"<<numeroHojas(arbol)<<endl;
    cout<<"Es el arbol equilibrado? :"<<esEquilibrado(arbol)<<endl;
    //Destruir arbol
    destruirArbolBinario(arbol);
    cout<<"Es arbol vacio: "<<esArbolVacio(arbol)<<endl;
//------------------------------------------------------------------------------------------------------------//
//---------------------------------ARBOLES BINARIOS BUSQUEDA---------------------------------//
//------------------------------------------------------------------------------------------------------------//   
    cout<<endl<<"ARBOLES BINARIOS BUSQUEDAD"<<endl;
    struct ArbolBinario ArbolBusqueda1,ArbolBusqueda2;
    contruir(ArbolBusqueda1);
    contruir(ArbolBusqueda2);
    
    Insertar(ArbolBusqueda1,100);
    Insertar(ArbolBusqueda1,80);
    Insertar(ArbolBusqueda1,30);
    Insertar(ArbolBusqueda1,130);
    Insertar(ArbolBusqueda1,50);
    cout<<"Arbol 1: "<<endl;
    recorrerEnPreOrden(ArbolBusqueda1);
    recorrerEnOrden(ArbolBusqueda1);
    recorrerEnPostOrden(ArbolBusqueda1);
    
    Insertar(ArbolBusqueda2,10);
    Insertar(ArbolBusqueda2,8);
    Insertar(ArbolBusqueda2,3);
    Insertar(ArbolBusqueda2,13);
    Insertar(ArbolBusqueda2,5);
    cout<<"Arbol 2: "<<endl;
    recorrerEnPreOrden(ArbolBusqueda2);
    recorrerEnOrden(ArbolBusqueda2);
    recorrerEnPostOrden(ArbolBusqueda2);
    
    //Fucionar arbol 1 y arbol 2
    Fusionar(&ArbolBusqueda1,&ArbolBusqueda2);
    cout<<"Arbol Fusionados"<<endl;
    recorrerEnOrden(ArbolBusqueda1);
    //Elemento maximo y minimo
    cout<<"Minimo ABB: "<<MinimoABB(ArbolBusqueda1)<<endl;
    cout<<"Maximo ABB: "<<MaximoABB(ArbolBusqueda1)<<endl;
    cout<<"sumar nodos: "<<SumarNodos(ArbolBusqueda1)<<endl;
    //Borrar un nodo recursivo
    borrarNodo(ArbolBusqueda1,100);
    recorrerEnPostOrden(ArbolBusqueda1);
    recorreriIterativoEnPostOrden(ArbolBusqueda1);
    return 0;
}


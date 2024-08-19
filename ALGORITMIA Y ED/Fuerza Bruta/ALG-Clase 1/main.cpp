/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 21 de marzo de 2024, 16:02
 */

#include <iostream>
#include <valarray>
using namespace std;
#include "Funciones.h"
#include "Paquete.h"
#define MAX_D 7
#define CANT_PAQ 6


int main(int argc, char** argv) {
    //METODO DE SELECCCION
    int arreglo[MAX_D]={89,45,68,90,29,34,17};
    cout<<"Arreglo Inicial: ";
    mostrarArreglo(arreglo,MAX_D);
    OrdenarSeleccion(arreglo,MAX_D);
    cout<<"Arreglo Ordenado: ";
    mostrarArreglo(arreglo,MAX_D);
    
    //METODO BURBUJA
    int arreglo2[MAX_D]={89,45,68,90,29,34,17};
    cout<<endl<<"Ordenamiento Burbuja"<<endl<<"Arreglo Inicial: ";
    mostrarArreglo(arreglo2,MAX_D);
    OrdenarBurbuja(arreglo2,MAX_D);
    cout<<"Arreglo Ordenado: ";
    mostrarArreglo(arreglo2,MAX_D);
    
    //BUSQUEDA SECUENCIAL
    int numBuscar=17, indice;
    cout<<endl<<"Busqueda secuencial"<<endl<<"Numero a buscar: "<<numBuscar<<endl;
    indice=BusquedaSecuencial(numBuscar,arreglo,MAX_D);
    if(indice== -1) cout <<"No se encontro el numero "<<numBuscar<<endl<<endl;
    else cout<<"Se encontro el numero "<<numBuscar<<endl<<endl;
    
    //PROBLEMA DE LA MOCHILA CON ESTRUCUTURA
    struct Paquete paquetes[CANT_PAQ] = {{'A',   8, 15}, 
                                                                    {'B',   2, 20}, 
                                                                    {'C', 10,   5}, 
                                                                    {'D', 10, 10}, 
                                                                    {'E',   5,   8},
                                                                    {'F',   5,   5}};
      SolucionMochilaPesoExacto(paquetes);
      SolucionMochilaPesoMAX(paquetes);
      SolucionMochilaGananciaMAX(paquetes);
    return 0;
}


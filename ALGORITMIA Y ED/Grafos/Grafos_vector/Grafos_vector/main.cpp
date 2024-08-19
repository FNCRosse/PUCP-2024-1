/* 
 * File:   main.cpp
 * Author: Ana Roncal
 *
 * Created on 18 de junio de 2024, 14:25
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include "Grafo.h"
#include "Pila.h"
#include "funcionesPila.h"

int main(int argc, char** argv) {
    Grafo grafoMap;
    
    grafoMap.agregarVerticeMap('A');
    grafoMap.agregarVerticeMap('B');
    grafoMap.agregarVerticeMap('C');
    grafoMap.agregarVerticeMap('D');
    grafoMap.agregarVerticeMap('E');
    grafoMap.agregarVerticeMap('F');
    grafoMap.agregarVerticeMap('G');
    grafoMap.agregarAristaMap('A', 'F',310.25);
    grafoMap.agregarAristaMap('F', 'G',250.5);
    grafoMap.agregarAristaMap('G', 'E',402);
    grafoMap.agregarAristaMap('D', 'E',175.50);
    grafoMap.agregarAristaMap('C', 'D',244.47);
    grafoMap.agregarAristaMap('B', 'D',150.1);
    grafoMap.agregarAristaMap('A', 'C',145.7);
    grafoMap.agregarAristaMap('A', 'B',275.3);
    // Mostrar el grafo
    grafoMap.imprimirGrafoMap();
    cout<<endl<<"Recorrido DFS:"<<endl;
    struct ciudad inicio;
    inicio.SetDestino('A');
    inicio.SetDistancia(0);
    grafoMap.RecorridoDFS(inicio);
    //Guardar en una pila todos los vecinos de un vertice
//    Pila pila;
//    construir(pila);
//    grafoMap.dameVecinosDeUnVertice('A',pila);
//    imprimir(pila);
//    
//    //Distancia minima
//    double minDistancia=9999999;
//    char LetraCiudadMinDistancia;
//    grafoMap.DistanciaMinimaEntreUnVerticeYVecinos(pila,'A',minDistancia,LetraCiudadMinDistancia);
//    cout<<LetraCiudadMinDistancia<<" "<<minDistancia<<endl;
//    
//    //Todos los recorridos de un vertice
//    grafoMap.mostrarTodosRecorridosDesdeUnaCiudad('A');
    
//    cout<<"Distrack:"<<endl;
//    grafoMap.dijkstra('A');
//    cout<<"Distrack Especifico:"<<endl;
//    grafoMap.dijkstraEspecifico('A','E');
//    cout<<endl;
//    cout<<"Distrack Mayor:"<<endl;
//    grafoMap.dijkstraMayor('A');
//    cout<<"Distrack Especifico Mayor:"<<endl;
//    grafoMap.dijkstraEspecificoMayor('A','E');
//    cout<<endl;
   
    
    return 0;
}
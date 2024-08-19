// -*- C++ -*-

/* 
 * File:   Grafo.h
 * Author: ANA RONCAL
 *
 * Created on 18 de junio de 2024, 14:52
 */

#ifndef GRAFO_H
#define GRAFO_H
#include <map>
#include <vector>
using namespace std;
#include "Pila.h"
class ciudad{
private:
    double distancia;
    char Destino;
public:
    ciudad();
    void SetDestino(char Destino);
    char GetDestino() const;
    void SetDistancia(double distancia);
    double GetDistancia() const;
    
};
class Grafo {
    private:
        map <char, vector<class ciudad> > listaMap;
    public:
        //Constructor
        Grafo();
        void agregarVerticeMap(char ver);
        void agregarAristaMap(char u, char v, double dist);

        // Mostrar el grafo
        void imprimirGrafoMap();
        
        //Otros
        void dameVecinosDeUnVertice(char vertice,struct Pila &pila);
        void DistanciaMinimaEntreUnVerticeYVecinos(struct Pila &pila,char vertice,double &minDistancia,
        char &LetraCiudadMinDistancia);
        void mostrarTodosRecorridosDesdeUnaCiudad(char ciudad);
        bool SeEncuentraArista(char ciudadOrigen,char CiudadDestino);
        
        void dijkstra(char inicio);
        void dijkstraEspecifico(char inicio,char fin);
        void dijkstraMayor(char inicio);
        void dijkstraEspecificoMayor(char inicio,char fin);
        char getMinDist(vector<char> &Q, map<char, double> &dist);
        char getMaxDist(vector<char> &Q, map<char, double> &dist);
        
        //Recorrido
        void RecorridoDFS(struct ciudad &inicio);
        bool EsVisitada(vector<char> &visitados,char ciudadActual);
};

#endif /* GRAFO_H */
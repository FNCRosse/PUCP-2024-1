/* 
 * File:   funcionesGrafo.cpp
 * Author: Ana Roncal
 * 
 * Created on 18 de junio de 2024, 16:03
 */
#include <iostream>
#include <vector>
#include <map>
#include <valarray>
#include "Grafo.h"
#include "funcionesPila.h"
using namespace std;

ciudad::ciudad() {

}

void ciudad::SetDestino(char Destino) {
    this->Destino = Destino;
}

char ciudad::GetDestino() const {
    return Destino;
}

void ciudad::SetDistancia(double distancia) {
    this->distancia = distancia;
}

double ciudad::GetDistancia() const {
    return distancia;
}

Grafo::Grafo() {
}

void Grafo::agregarVerticeMap(char ver) {
    if (listaMap.find(ver) == listaMap.end()) { //añade el vector si no se encuentra
        listaMap[ver] = vector<class ciudad>();
    }
}

void Grafo::agregarAristaMap(char u, char v, double dist) {
    agregarVerticeMap(u);
    agregarVerticeMap(v);
    class ciudad dato;
    dato.SetDestino(v);
    dato.SetDistancia(dist);
    //OJOO///
    //tener en cuenta que si ya existe la arista no la debe añadir
    listaMap[u].push_back(dato);
    // listaMap[v].push_back(u); // Para grafos no dirigidos
}

void Grafo::imprimirGrafoMap() {
    for (const auto & vertice : listaMap) {
        char cuidad = vertice.first;
        cout << "Ciudad " << cuidad << ": ";
        const vector<class ciudad> & adyacentes = vertice.second;
        for (ciudad arista : adyacentes) {
            cout << arista.GetDestino() << "," << arista.GetDistancia() << " ";
        }
        cout << endl;
    }
}
bool Grafo::EsVisitada(vector<char> &visitados,char ciudadActual){
    for(char ciudad: visitados){
        if(ciudad == ciudadActual) return true;
    }
    return false;
}
void Grafo::RecorridoDFS(struct ciudad &inicio){
    Pila pila;
    construir(pila);
    vector<char> visitados;
    apilar(pila,inicio);
    while(!esPilaVacia(pila)){
        struct ciudad VectorActual = desapilar(pila);
        char ciudadActual = VectorActual.GetDestino();
        if( ! EsVisitada(visitados,ciudadActual)){
            visitados.push_back(ciudadActual);
            cout<<ciudadActual<<" ";
            for(auto & arista : listaMap[ciudadActual]){
                if(! EsVisitada(visitados,arista.GetDestino()))
                    apilar(pila,arista);
            }
        }
    }

}
void Grafo::dameVecinosDeUnVertice(char vertice, struct Pila &pila) {
    for (const auto & ver : listaMap) {
        char ciudad = ver.first;
        if (ciudad == vertice) {
            const vector<class ciudad> & adyacentes = ver.second;
            for (class ciudad arista : adyacentes) {
                apilar(pila, arista);
            }
            break;
        }
    }
}

void Grafo::DistanciaMinimaEntreUnVerticeYVecinos(struct Pila &pila, char vertice, double &minDistancia,
        char &LetraCiudadMinDistancia) {
    class ciudad vecino;
    while (!esPilaVacia(pila)) {
        vecino = desapilar(pila);
        if (vecino.GetDistancia() < minDistancia) {
            minDistancia = vecino.GetDistancia();
            LetraCiudadMinDistancia = vecino.GetDestino();
        }
    }
}

bool Grafo::SeEncuentraArista(char ciudadOrigen, char CiudadDestino) {
    for (const auto & vertice : listaMap) {
        char VerCiudad = vertice.first;
        if (VerCiudad == ciudadOrigen) {
            const vector<class ciudad> & adyacentes = vertice.second;
            for (class ciudad arista : adyacentes) {
                if (CiudadDestino == arista.GetDestino()) return true;
            }
            return false;
        }
    }
    return false;
}

void Grafo::mostrarTodosRecorridosDesdeUnaCiudad(char ciudadOrigen) {
    struct Pila pila;
    class ciudad p, dato;
    construir(pila);
    dameVecinosDeUnVertice(ciudadOrigen, pila);

    while (!esPilaVacia(pila)) {
        p = desapilar(pila);
        //Parte de imprimir
        if (SeEncuentraArista(ciudadOrigen, p.GetDestino())) {
            cout << endl << ciudadOrigen << ":" << p.GetDestino() << " ";
        } else {
            cout << p.GetDestino() << " ";
        }
        //
        for (const auto & vertice : listaMap) {
            char VerCiudad = vertice.first;
            if (VerCiudad == p.GetDestino()) {
                const vector<class ciudad> & adyacentes = vertice.second;
                for (class ciudad arista : adyacentes) {
                    dato = arista;
                    apilar(pila, dato);
                }
            }
        }
    }
}

void Grafo::dijkstra(char inicio) {
    map<char, double> dist; //Guarda la distancia minima del incio a cada nodo
    vector<char> Q; // tiene todo los nodos del grafo
    for (auto const &pair : listaMap) { // Inicializacion
        dist[pair.first] = 1e9; //con un numero muy grande
        Q.push_back(pair.first); // rellenar con los nodos del grafo
    }
    dist[inicio] = 0; //Como es donde inicia, la distancia hacia el inicio es 0
    while (!Q.empty()) {
        char u = getMinDist(Q, dist);
        Q.erase(remove(Q.begin(), Q.end(), u), Q.end());

        for (ciudad const &vecino : listaMap[u]) {
            char v = vecino.GetDestino();
            double alt = dist[u] + vecino.GetDistancia();
            if (alt < dist[v]) {
                dist[v] = alt;
            }
        }
    }
    // Imprimir las distancias más cortas
    for (auto const &pair : dist) {
        cout << "Distancia desde " << inicio << " hasta " << pair.first << " es " << pair.second << endl;
    }
}
void Grafo::dijkstraEspecifico(char inicio,char destino) {
    map<char, double> dist; //Guarda la distancia minima del incio a cada nodo
    map<char,char> prev; //Solo sirve para guardar el camino
    vector<char> Q; // tiene todo los nodos del grafo
    for (auto const &pair : listaMap) { // Inicializacion
        dist[pair.first] = 1e9; //con un numero muy grande
        prev[pair.first] = '\0';
        Q.push_back(pair.first); // rellenar con los nodos del grafo
    }
    dist[inicio] = 0; //Como es donde inicia, la distancia hacia el inicio es 0
    while (!Q.empty()) {
        char u = getMinDist(Q, dist);
        Q.erase(remove(Q.begin(), Q.end(), u), Q.end());
        if(u == destino) break;
        for (ciudad const &vecino : listaMap[u]) {
            char v = vecino.GetDestino();
            double alt = dist[u] + vecino.GetDistancia();
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
            }
        }
    }
    // Imprimir las distancias más cortas
    if(dist[destino] != 1e9){
        cout << "Distancia desde " << inicio << " hasta " << destino << " es " << dist[destino] << endl;
        cout<<"El camino tomado es:";
        vector<char> camino;
        for(char at = destino; at != '\0'; at = prev[at]) {
            camino.push_back(at);
        }
        reverse(camino.begin(),camino.end());
        for(char c: camino) cout<<c<<" ";
        cout<<endl;
    }
}
void Grafo::dijkstraMayor(char inicio) {
    map<char, double> dist; //Guarda la distancia minima del incio a cada nodo
    vector<char> Q; // tiene todo los nodos del grafo
    for (auto const &pair : listaMap) { // Inicializacion
        dist[pair.first] = -1e9; //con un numero muy grande
        Q.push_back(pair.first); // rellenar con los nodos del grafo
    }
    dist[inicio] = 0; //Como es donde inicia, la distancia hacia el inicio es 0
    while (!Q.empty()) {
        char u = getMaxDist(Q, dist);
        Q.erase(remove(Q.begin(), Q.end(), u), Q.end());

        for (ciudad const &vecino : listaMap[u]) {
            char v = vecino.GetDestino();
            double alt = dist[u] + vecino.GetDistancia();
            if (alt > dist[v]) {
                dist[v] = alt;
            }
        }
    }
    // Imprimir las distancias más cortas
    for (auto const &pair : dist) {
        cout << "Distancia desde " << inicio << " hasta " << pair.first << " es " << pair.second << endl;
    }
}
void Grafo::dijkstraEspecificoMayor(char inicio,char destino) {
    map<char, double> dist; //Guarda la distancia minima del incio a cada nodo
    map<char,char> prev; //Solo sirve para guardar el camino
    vector<char> Q; // tiene todo los nodos del grafo
    for (auto const &pair : listaMap) { // Inicializacion
        dist[pair.first] = -1e9; //con un numero muy grande
        prev[pair.first] = '\0';
        Q.push_back(pair.first); // rellenar con los nodos del grafo
    }
    dist[inicio] = 0; //Como es donde inicia, la distancia hacia el inicio es 0
    while (!Q.empty()) {
        char u = getMaxDist(Q, dist);
        Q.erase(remove(Q.begin(), Q.end(), u), Q.end());
        if(u == destino) break;
        for (ciudad const &vecino : listaMap[u]) {
            char v = vecino.GetDestino();
            double alt = dist[u] + vecino.GetDistancia();
            if (alt > dist[v]) {
                dist[v] = alt;
                prev[v] = u;
            }
        }
    }
    // Imprimir las distancias más cortas
    if(dist[destino] != 1e9){
        cout << "Distancia desde " << inicio << " hasta " << destino << " es " << dist[destino] << endl;
        cout<<"El camino tomado es:";
        vector<char> camino;
        for(char at = destino; at != '\0'; at = prev[at]) {
            camino.push_back(at);
        }
        reverse(camino.begin(),camino.end());
        for(char c: camino) cout<<c<<" ";
        cout<<endl;
    }
}

char Grafo::getMinDist(vector<char> &Q, map<char, double> &dist) {
    double minDist = 1e9;
    char minVertex = '\0';

    for (char vertex : Q) {
        double a = dist[vertex] ;
        if (dist[vertex] < minDist) {
            minDist = dist[vertex];
            minVertex = vertex;
        }
    }
    return minVertex;
}
char Grafo::getMaxDist(vector<char> &Q, map<char, double> &dist) {
    double maxDist = -1e9;
    char maxVertex = '\0';

    for (char vertex : Q) {
        double a = dist[vertex] ;
        if (dist[vertex] > maxDist) {
            maxDist = dist[vertex];
            maxVertex = vertex;
        }
    }
    return maxVertex;
}
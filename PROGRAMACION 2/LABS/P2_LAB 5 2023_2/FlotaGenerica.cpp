/* 
 * File:   FlotaGenerica.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de mayo de 2024, 19:59
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include  "FlotaGenerica.h"
#include "ListaConEntero.h"
#include "ListaConRegistro.h"
enum RegLista {SIG, DATO};
enum RegPedido {INICIO, PESO};

void CargaCamiones(void *&Flota,int numCamiones,double PesoMaximo,void*(*Lee)(ifstream &),
        double (*Calcular)(void*),const char* namefile){
    ifstream arch(namefile);
    Flota=nullptr;
    void **ArrCamiones = new void*[numCamiones];
    for(int i=0;i<numCamiones;i++) InicializarLista(ArrCamiones[i]);
    void *Dato;
    double PesoDato, PesoAcumulado;
    int nCam=0;
    while(true){
        Dato = Lee(arch);
        if(arch.eof()) break;
        PesoDato = Calcular(Dato);
        PesoAcumulado = ObtenerPesoActualCamion(ArrCamiones[nCam]);
        if(PesoDato+PesoAcumulado > PesoMaximo){
            nCam++;
            if(nCam >= numCamiones) break;
        }
        insertar(Dato,ArrCamiones[nCam]);
        ActualizarPesoCamion(PesoDato,ArrCamiones[nCam]);
    }
    Flota = ArrCamiones;
}
void MuestraCamiones(void* flota,int numCamiones,void (*imprime)(void*,ofstream&),const char* namefile){
    ofstream arch(namefile);
    arch.precision(2);
    arch<<fixed;
    void **ArrCamiones = (void**)flota;
    for(int i=0;i<numCamiones;i++){
        void **Lista  = (void**)ArrCamiones[i];
        double*PesoTotal = (double*)(Lista[PESO]);
        arch<<left<<"Camion: "<<i+1<<": "<<setw(20)<<" Peso: "<<*PesoTotal<<endl;
        imprime(Lista[INICIO],arch);
    }
}
bool EsListaVacia(void *Lista){
    if(Lista == nullptr) return true;
    return false;
}
void InicializarLista(void *&Camion){
    void **Lista = new void *[2]{};
    double *PesoCamion = new double; //Peso inicial del camion
    *PesoCamion = 0.0;
    Lista[INICIO]= nullptr;
    Lista[PESO]= PesoCamion;
    Camion = Lista;
}
double ObtenerPesoActualCamion(void *Camion){
    void ** DatoLista = (void**)Camion;
    double *PesoCamion=(double*)DatoLista[PESO];
    return *PesoCamion;
}
void  insertar(void* Dato,void *Camion){
    void **Lista = (void**)Camion;
    void **nuevo = new void *[2]{};
    nuevo[DATO]= Dato;
    if(EsListaVacia(Lista[INICIO])){
        Lista[INICIO] = nuevo;
        nuevo[SIG] = nullptr;
    } else {
        void ** ultimo = nullptr;
        while(Lista){
            ultimo = Lista;
            Lista = (void**)Lista[SIG];
        }
        ultimo[SIG] = nuevo;
        nuevo[SIG] = nullptr;
    }
}
void  ActualizarPesoCamion(double pesoIngresado, void *Camion){
    void ** DatoLista = (void**)Camion;
    double *PesoCamion=(double*)DatoLista[PESO];
     *PesoCamion += pesoIngresado;
}

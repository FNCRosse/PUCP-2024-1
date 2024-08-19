/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 15 de mayo de 2024, 15:30
 */

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"
#define MAX 8 // numero maximo de camiones
#define MAXT 4 //El maximo de tortugas
struct Camion{
    struct Lista lista;
};
void CargaComb(int num, int* Cromo){
    int i=0;
    while(num>0){
        Cromo[i++] = num % MAXT;
        num = num / MAXT;
    }
}
void LeerDatos(int &nCamiones,int *MaxCarga,struct Camion *ArrCamiones){
    ifstream arch ("Datos.txt");
    int nPaquetes=0, Paquete,cantCamiones;
    arch>>cantCamiones;
    nCamiones = cantCamiones;
    for(int i=0;i<4;i++)arch>>MaxCarga[i];
    for(int i=0;i<cantCamiones;i++)construir(ArrCamiones[i].lista);
    while(true){
        arch>>Paquete;
        if(arch.eof()) break;
        if(Paquete == 0) nPaquetes++; 
        else insertarAlFinal(ArrCamiones[nPaquetes].lista,Paquete);       
    }
}
int ObtenerPesoCamion(struct Camion camion){
    int PesoTotal=0;
    Nodo * recorrer = camion.lista.cabeza;
    while (recorrer) {
        PesoTotal += recorrer->elemento;
        recorrer = recorrer->siguiente;
    }
    return PesoTotal;
}
bool CumpleMision(int nCamiones,int *MaxCarga,struct Camion *ArrCamiones,int &solucion,int *cantRescatados){
    int Opciones =  pow(MAXT,nCamiones);
    int Cromo[MAX] {}, Rescatados[MAXT]{};
    bool HaySolucion=true;
    for(int i=0;i<Opciones;i++){
        CargaComb(i,Cromo);
        //Resetar lo de arreglo creados
        for(int k=0;k<MAXT;k++) Rescatados[k] =0;
        for(int k=0;k<MAXT;k++) cantRescatados[k] =0;
        for(int k=0;k<nCamiones;k++){
            int a  = Cromo[k];
            int pesoCamion = ObtenerPesoCamion(ArrCamiones[k]);
            Rescatados[a] += pesoCamion;
            cantRescatados[a]++;
        }
        HaySolucion = true;
        for(int k=0;k<MAXT;k++){
            if(Rescatados[k] == 0 || Rescatados[k] > MaxCarga [k] || cantRescatados[k] > 2){
                HaySolucion = false;
                break;
            }
        }
        if(HaySolucion == true){
            solucion = i;
            break;
        }
    }
    return HaySolucion;
}
void OrdenarLista(struct Lista &Camion, int tipo){
    Nodo *Recorrido, *RecorridoSig;
    for(int i=0;i<Camion.longitud-1;i++){
        Recorrido = Camion.cabeza;
        RecorridoSig = Camion.cabeza->siguiente;
        for(int k=0;k<=Camion.longitud-2;k++){
            if(tipo == 2){
                    if(Recorrido->elemento < RecorridoSig->elemento){
                    Recorrido->siguiente = RecorridoSig->siguiente;
                    RecorridoSig->siguiente = Recorrido;
                    if(k == 0){
                        Camion.cabeza = RecorridoSig;
                    }
                    Nodo * Aux = Recorrido->siguiente;
                    Recorrido = RecorridoSig->siguiente;
                    RecorridoSig = Aux;
                } else {
                    Recorrido = RecorridoSig;
                    RecorridoSig = RecorridoSig->siguiente;
                }
            }
            if(tipo == 1){
                if(Recorrido->elemento > RecorridoSig->elemento){
                    Recorrido->siguiente = RecorridoSig->siguiente;
                    RecorridoSig->siguiente = Recorrido;
                    if(k == 0){
                        Camion.cabeza = RecorridoSig;
                    }
                    Nodo * Aux = Recorrido->siguiente;
                    Recorrido = RecorridoSig->siguiente;
                    RecorridoSig = Aux;
                } else {
                    Recorrido = RecorridoSig;
                    RecorridoSig = RecorridoSig->siguiente;
                }
            }
        }
    }
}
void FusionarListasIntercalado(struct Lista &Original,struct Lista &Sec){
    int i=0;
    Nodo *ListaPrincipal = Original.cabeza;
    Nodo *ListaSec = Sec.cabeza;
    Nodo * Aux2 = nullptr;
    while(ListaSec!= nullptr){
        if(ListaPrincipal !=nullptr){
            if(i%2==0){
                Nodo * Aux1 = ListaPrincipal->siguiente;
                ListaPrincipal->siguiente = ListaSec;
                Aux2 = ListaSec->siguiente;
                ListaPrincipal->siguiente->siguiente = Aux1;
                ListaPrincipal = ListaPrincipal->siguiente;
                ListaPrincipal = ListaPrincipal->siguiente;
                Original.longitud++;
            } else{
                ListaSec = Aux2;
                ListaPrincipal = ListaPrincipal->siguiente;
            }
            i++;
        } else{
            insertarAlFinal(Original,ListaSec->elemento);
            ListaSec = ListaSec->siguiente;
        }
    }
}
void ImprimirSolucion(struct Camion *ArrCamiones,int nCamiones, int solucion,int cantRescatados[]){
    int Cromo[MAX]{};
    CargaComb(solucion,Cromo);
    for(int i=0;i<MAXT;i++){
        if(i==0) cout<<"Leonardo: ";
        if(i==1) cout<<"Rafael: ";
        if(i==2) cout<<"Donatelo: ";
        if(i==3) cout<<"Miguel Angel: ";
        if(cantRescatados[i] == 1){
            //Voy a buscar en el cromo en que posicion esta la tortuga q estamos en i
            for(int k=0;k<nCamiones;k++){
                if(Cromo[k] == i) imprime(ArrCamiones[k].lista);
            }
        } else {
            //como solo va haber 2 listas a fusionar
            int lista1,lista2,cont=0;
            for(int k=0;k<nCamiones;k++){
                if(Cromo[k] == i){
                    if(cont == 0){
                        lista1 = k; cont++;
                    }
                    lista2 = k;
                }
            }
            //tipo 1 = menor a mayor , Tipo 2 =mayor a menor
            OrdenarLista(ArrCamiones[lista1].lista,1);
            OrdenarLista(ArrCamiones[lista2].lista,2);
            FusionarListasIntercalado(ArrCamiones[lista1].lista,ArrCamiones[lista2].lista);
            imprime(ArrCamiones[lista1].lista);
        }
    }
}
int main(int argc, char** argv) {
    int nCamiones,solucion=0,cantRescatados[MAXT]{};
    int MaxCarga[MAXT]{};
    struct Camion ArrCamiones[MAX];
    //Parte A
    LeerDatos(nCamiones,MaxCarga,ArrCamiones);
    // Parte B
    if(CumpleMision(nCamiones,MaxCarga,ArrCamiones,solucion,cantRescatados)){
        //Parte C
        cout<<"Las tortugas ninjas completaron su mision"<<endl;
        cout<<"Los Camiones a salvar son: "<<endl;
        ImprimirSolucion(ArrCamiones,nCamiones,solucion,cantRescatados);
    } else {
        cout<<"Las tortugas ninjas NO completaron su mision"<<endl;
    }
    
    

    return 0;
}


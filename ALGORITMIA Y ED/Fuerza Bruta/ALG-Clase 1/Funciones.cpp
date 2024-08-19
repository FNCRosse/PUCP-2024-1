/* 
 * File:   Funciones.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 21 de marzo de 2024, 16:12
 */
#include <iostream>
#include <cmath>
using namespace std;
#include "Funciones.h"
#include "Paquete.h"
#define CANT_PAQ 5
#define CAP_MOCHILA 15

void mostrarArreglo(int * Arr, int n){
    for(int i=0;i<n;i++) cout<<Arr[i]<<" ";
    cout<<endl;
}
void  OrdenarSeleccion(int *Arr,int n){
    for(int i=0;i<=n-2;i++){
        int min = i;
        for(int j=i+1;j<=n-1;j++){
            if(Arr[j]<Arr[min]){
                min =j;
            }
            int aux=Arr[i];
            Arr[i]=Arr[min];
            Arr[min]=aux;
        }
    }
}
void  OrdenarBurbuja(int *Arr,int n){
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2-i;j++){
            if(Arr[j+1]<Arr[j]){
                int aux=Arr[j];
                Arr[j]=Arr[j+1];
                Arr[j+1]=aux;
            }
        }
    }
}
int BusquedaSecuencial(int numBuscar,int *arreglo,int n){
    for(int i=0;i<n;i++){
        if(numBuscar==arreglo[i]) return i;
    }
    return -1;
}
void CargarBinario(int num, int *Arreglo){
    int i=0;
    while(num>0){
        Arreglo[i++] = num%2;
        num = num/2;
    }
}
void SolucionMochilaPesoExacto(struct Paquete *paquetes){
    
    int Combinaciones[CANT_PAQ]={};
    int Opcion = (int) pow(2,CANT_PAQ);
    cout<<"La solucion PesoExacto es: "<<endl;
    
    for(int i=0;i<Opcion;i++){
        int PesoParcial=0;
        CargarBinario(i,Combinaciones);
        for(int j=0;j<CANT_PAQ;j++){
            PesoParcial += Combinaciones[j]*paquetes[j].Peso;
        }
        //Imprimir todas la soluciones que tiene peso exacto
        if(PesoParcial == CAP_MOCHILA){
            cout<<"Opcion: "<<i<<endl;
            for(int j=0;j<CANT_PAQ;j++) {
                if(Combinaciones[j]==1) cout<<paquetes[j].id<<" "<<paquetes[j].Peso<<"; ";
            }
            cout<<endl;
        }
    }
}
void SolucionMochilaPesoMAX(struct Paquete *paquetes){
    //imprime la ultima opcion de todas la opciones
    int Combinaciones[CANT_PAQ]={};
    int Opcion = (int) pow(2,CANT_PAQ);
    cout<<endl<<"La solucion PesoMAX es: "<<endl;
    int MaxPeso=0, MaxCombinacion=0;
    
    for(int i=0;i<Opcion;i++){
        int PesoParcial=0;
        CargarBinario(i,Combinaciones);
        for(int j=0;j<CANT_PAQ;j++){
            PesoParcial += Combinaciones[j]*paquetes[j].Peso;
        }
        //Guardar el peso maximo y su combinacion
        if(MaxPeso<=PesoParcial and PesoParcial <= CAP_MOCHILA){
            MaxPeso = PesoParcial;
            MaxCombinacion = i;
        }
    }
    //Imprimir esa opcion maxima
    CargarBinario(MaxCombinacion,Combinaciones);
    cout<<"Opcion Maxima: "<<MaxCombinacion<<endl;
        for(int j=0;j<CANT_PAQ;j++) {
            if(Combinaciones[j]==1) cout<<paquetes[j].id<<" "<<paquetes[j].Peso<<"; ";
        }
    cout<<endl;
}
void SolucionMochilaGananciaMAX(struct Paquete *paquetes){
    //imprime la ultima opcion de todas la opciones que den mas ganancia
    int Combinaciones[CANT_PAQ]={};
    int Opcion = (int) pow(2,CANT_PAQ);
    cout<<endl<<"La solucion GananciaMAX es: "<<endl;
    int MaxGanancia=0, MaxCombinacion=0;
    
    for(int i=0;i<Opcion;i++){
        int PesoParcial=0,GananciaParcial=0;
        CargarBinario(i,Combinaciones);
        for(int j=0;j<CANT_PAQ;j++){
            PesoParcial += Combinaciones[j]*paquetes[j].Peso;
            GananciaParcial += Combinaciones[j]*paquetes[j].ganancia;
        }
        //Guardar el peso maximo y su combinacion
        if(MaxGanancia < GananciaParcial and PesoParcial <= CAP_MOCHILA){
            MaxGanancia = GananciaParcial;
            MaxCombinacion = i;
        }
    }
    //Imprimir esa opcion maxima
    CargarBinario(MaxCombinacion,Combinaciones);
    cout<<"Opcion Maxima: "<<MaxCombinacion<<endl;
    cout<<"Ganancia Maxima: "<<MaxGanancia<<endl;
        for(int j=0;j<CANT_PAQ;j++) {
            if(Combinaciones[j]==1) cout<<paquetes[j].id<<" "<<paquetes[j].Peso<<" "<<paquetes[j].ganancia<<"; ";
        }
    cout<<endl;
}
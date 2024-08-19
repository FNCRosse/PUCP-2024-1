/* 
 * File:   Funciones.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 27 de marzo de 2024, 11:27
 */
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include "Funciones.h"
#define MAXC 5
#define MAXP 10
#define BASE 3 //La base es igual a la cantidad de camiones


void LeerDatos(int *ArrCamiones,int *ArrPaquetes,int &CantCamiones,int &CantPaquetes){
    ifstream arch ("Datos.txt",ios::in);
    arch>>CantCamiones>>CantPaquetes;
    for(int i=0;i<CantCamiones;i++) arch>>ArrCamiones[i];
    for(int i=0;i<CantPaquetes;i++) arch>>ArrPaquetes[i];
    
}
void CargarCromosoma(int *Cromosoma,int num){
    int i=0;
    while(num>0){
        Cromosoma[i++] = num%2;
        num /=2;
    }
}
void multiplesCamiones(int CantCamiones,int CantPaquetes,int *ArrCamiones,int *ArrPaquetes){
    //LAs combionaciones se hacen apartir de los paquetes
    int tamano,opciones,diferencia = 999999999, solucionOptima;
    tamano = CantCamiones* CantPaquetes; // 0000 0000 0000 = 12
    opciones = (int) pow(2,tamano); 
    int Cromosoma[tamano]{};
    for(int i=0;i<opciones;i++){
        //Cargas la combinaciones 
        CargarCromosoma(Cromosoma,i);
        //Creo un arreglo donde guardare los paquetes guardados en cada camion
        int CargarCamiones[CantCamiones]{};
        // Voy a verificar 
        bool Opcionvalida = EsValido(CantCamiones,CantPaquetes,ArrCamiones,ArrPaquetes,Cromosoma,tamano,
                CargarCamiones);
        if(!Opcionvalida )continue;
        int maximo = CalcularMaximo(ArrCamiones,CantCamiones,CargarCamiones);
        int minimo = CalcularMinimo(ArrCamiones,CantCamiones,CargarCamiones);
        if( maximo - minimo <= diferencia){
            solucionOptima = i;
            diferencia = maximo - minimo;
        }
    }  
    CargarCromosoma(Cromosoma,solucionOptima);
    cout<<solucionOptima<<endl;
    for(int i=0 ;i<tamano;i++){
        if(Cromosoma[i] == 0) continue;
        int paquete = i%CantPaquetes +1;
        int camion = i/CantPaquetes +1;
        cout<<"Paquete: "<<(i%CantPaquetes +1)<<"    Camion: "<<(i/CantPaquetes+1)<<endl;
    }
    cout<<endl<<"Diferencia maxima: "<<diferencia<<endl;
}
bool EsValido(int CantCamiones,int CantPaquetes,int *ArrCamiones,int *ArrPaquetes,int *Cromosoma,int tamano,
                int *CargarCamiones){
    //Creo un arreglo para que si ya use un paquete ya no lo vuelva a usar
    //Ejmplo
    // 0000  0001  0001
    //    2       1        0
    //Al leer el primer uno ya no puede volver a leer el siguiente 1 por que en esa posicion (i%CantPaquete) 
    //ya se asigno uno.
    bool PaquetesUsados[CantPaquetes]{}; //inicializo todo en falso
    int indexCamiones=0; //Este index es para poder guardar en el arreglo CargarCamiones
    //Recorro el cromosoma
    for(int i=0;i<tamano;i++){
        //Si es 0 no es valido, entonces continuo con el recorrido 
        if (!Cromosoma[i]) continue;
        //          2              1             0
        //  0   0   0  0    0 0 0 0    0 1 0 1
        // 11 10  9  8    7 6 5 4    3 2 1 0
        // Si  i= 0 -> 0/4 = 0 , i=1 -> 1/4=0,  i=2 -> 2/4=0,  i=3 -> 3/4=0, pero  i=4 -> 4/4=1
        // Entonces con i=4 ya estaria en el camiion 1 por eso incremento
        if ( i/CantPaquetes != indexCamiones ) indexCamiones = i/CantPaquetes; 
        // si ya el paquete ha sido utilizado, no se puede volver a utilizar entonces si lo hace no es una solucion 
        if(PaquetesUsados[i%CantPaquetes]) return false;
        // como ya validamos que el cromosoma es 1, y el arreglo de paquete usados 
        PaquetesUsados[i%CantPaquetes] = true;
        // Y voy a guardar ese paquete en el arreglo de carga
        CargarCamiones[indexCamiones] += ArrPaquetes[i%CantPaquetes];
        //Si lo que va cargando el camion es mas que la capacidad del camion no es solucion valida
        if(CargarCamiones[indexCamiones] > ArrCamiones[indexCamiones]) return false;
    }
   // si pasa todo el croma, entonces es solucion valida
    return true;
}
int CalcularMaximo(int *ArrCamiones,int CantCamiones,int *CargarCamiones){
    int max =0;
    for(int i=0;i<CantCamiones;i++){
        int a =  CargarCamiones[i] ;
        int b = ArrCamiones[i] - CargarCamiones[i] ;
        max = ArrCamiones[i] - CargarCamiones[i] >= max ? ArrCamiones[i] - CargarCamiones[i] : max;
    }
    return max;
}
int CalcularMinimo(int *ArrCamiones,int CantCamiones,int *CargarCamiones){
    int minimo =9999999;
    for(int i=0;i<CantCamiones;i++){
        int a =  CargarCamiones[i] ;
        int b = ArrCamiones[i] - CargarCamiones[i] ;
        minimo = ArrCamiones[i] - CargarCamiones[i] <= minimo ? ArrCamiones[i] - CargarCamiones[i] : minimo;
    }
    return minimo;
}
/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 07:21 PM
 */

#include <iomanip>
#include <iostream>
#include "Cliente.h"
#include "Cola.h"
using namespace std;
#include "funcionesCola.h"
#include "funcionesCliente.h"
#define PROCESO 120
#define MAX_CAJEROS 10
#define NUM_CLIENTES 100
/*
 * IMPLEMENTACIÓN DE COLA
 */

 /*Añadir más cajeros durante la mayor carga de trabajo*/
    /*Solo hay una fila y la primera persona que llegue será la primera en ser
      atendida
      Los clientes llegan por término medio cada 15 segundos
      Si hay disponible un cajero el proceso empieza después de la llegada
      El proceso total tarda como promedio, dos minutos, desde el momento que el 
      cliente llega hasta el cajero*/
int main(int argc, char** argv) {
    
    struct Cola cola;
    struct Cliente cliente;
    int tiempoTotal, promedioTiempo, salidas;
    int cajerosTiempo[MAX_CAJEROS]{};
    construir(cola);
    
    cout<<setw(32)<<"RESULTADOS DE LA SIMULACIÓN"<<endl;
    cout<<setw(30)<<"DEL DESPACHO DE ENTRADAS"<<endl;
    cout<<"Número de cajeros"<<setw(17)<<"Tiempo promedio"<<endl;
    for(int cajeros = 0; cajeros < MAX_CAJEROS; cajeros++){
        
        /*configurar el tiempo de cada cajero*/
        for(int i = 0; i< cajeros; i++)
            cajerosTiempo[i] = 0;
        
        /*cargar la cola de clientes*/
        for(int cont = 1; cont <= NUM_CLIENTES; cont++){
            cliente.horaLlegada = cont * 15;
            cliente.horaSalida = 0;
            encolar(cola, cliente);
        }
        
        tiempoTotal = 0;
        /*procesar todos los clientes de la cola*/
        while(not esColaVacia(cola)){
            
            for(int i = 0; i <= cajeros; i++){
                if(not esColaVacia(cola)){
                    struct Cliente cliente = desencolar(cola);
                    if(getHoraLlegada(cliente) >  cajerosTiempo[i])
                        salidas = getHoraLlegada(cliente) + PROCESO;
                    else
                        salidas = cajerosTiempo[i] + PROCESO;
                    setHoraSalida(cliente, salidas);
                    cajerosTiempo[i] = salidas;
                    tiempoTotal += totalTiempo(cliente);  
                }
            }
        }
                
        /*Mostrar resultados de la simulación*/
        promedioTiempo = tiempoTotal / NUM_CLIENTES;
        cout<<setw(8)<<cajeros + 1;
        cout<<setw(22)<<promedioTiempo<<endl;
    } 

    return 0;
}


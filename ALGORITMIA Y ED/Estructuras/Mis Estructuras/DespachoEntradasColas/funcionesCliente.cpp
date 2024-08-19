/* 
 * File:   funcionesCLiente.cpp
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 11:38 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "Cliente.h"
using namespace std;
#include "funcionesCliente.h"

/*Devuelve el tiempo de llegada del Cliente*/
int getHoraLlegada(const struct Cliente & cliente){
    return cliente.horaLlegada;
}

/*Devuelve el tiempo de salida del Cliente*/
int getHoraSalida(const struct Cliente & cliente){
    return cliente.horaSalida;
}

int totalTiempo(const struct Cliente & cliente){
    return cliente.horaSalida - cliente.horaLlegada;
}

void setHoraSalida(struct Cliente & cliente, int salida){
    cliente.horaSalida = salida;
}

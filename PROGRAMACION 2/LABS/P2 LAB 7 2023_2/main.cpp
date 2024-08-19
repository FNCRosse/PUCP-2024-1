/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 15:25
 */

#include <iostream>
using namespace std;
#include "Almacen.h"

int main(int argc, char** argv) {
    Almacen almacen;
    almacen.CargarPedidos();
    almacen.Actualizar_Pedidos();
    almacen.ImprimirOrdenesVenta();

    return 0;
}


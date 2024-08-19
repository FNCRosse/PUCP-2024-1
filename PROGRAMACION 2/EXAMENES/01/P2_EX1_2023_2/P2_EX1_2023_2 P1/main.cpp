/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 11:13
 */

#include <iostream>
using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"

int main(int argc, char** argv) {
    char **CodigoDelProducto;
    int **FechaClienteCantidad;
    
    cargarPedidos(FechaClienteCantidad,CodigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(FechaClienteCantidad,CodigoDelProducto,"PruebaPedidos.txt");
    
    OrdenarPedidos(FechaClienteCantidad,CodigoDelProducto);
    pruebaDeCargaDePedidos(FechaClienteCantidad,CodigoDelProducto,"ReportePedidos.txt");

    return 0;
}


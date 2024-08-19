/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 16 de abril de 2024, 11:32
 */

#include <iostream>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

int main(int argc, char** argv) {
    char *** producto, ***codigoPedidos;
    int *stock,*fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    LecturaDeProductos("Productos.csv",producto,stock,precios);
    PruebaDeLecturaDeProductos("ReporteDeProductos.txt",producto,stock,precios);
    
    LecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
    OrdenarPorFechas(fechaPedidos,codigoPedidos,dniCantPedidos);
    PruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,dniCantPedidos);
    
    ReporteDeEnviosDePedidos("ReporteDeEntregaDePedidos.txt",producto,stock,precios,
                                                     fechaPedidos,codigoPedidos,dniCantPedidos);
    PruebaDeLecturaDeProductos("ReporteDeProductosFinal.txt",producto,stock,precios);
    return 0;
}


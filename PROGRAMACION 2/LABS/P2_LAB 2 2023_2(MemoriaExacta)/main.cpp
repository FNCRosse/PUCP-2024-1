/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 10 de abril de 2024, 12:53
 */

#include <iostream>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

int main(int argc, char** argv) {
    char ***Producto, ***CodidoPedido;
    int *Stock, *fechaPedidos, ***dniCantPedido;
    double *precios;
    
    LecturaDeProducto("Productos.csv",Producto,Stock,precios);
    pruebaDeLecturaDeProductos("ReporteDeProductos.txt",Producto,Stock,precios);
    
    LecturaDePedido("Pedidos.csv",fechaPedidos,CodidoPedido,dniCantPedido);
    pruebaDeLecturaDePedidos("ReporteDePedidos.txt",fechaPedidos,CodidoPedido,dniCantPedido);
    
    ReporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",Producto,Stock,precios,fechaPedidos,
            CodidoPedido,dniCantPedido);
    pruebaDeLecturaDeProductos("ReporteDeProductosDinal.txt",Producto,Stock,precios);
    
    
    char** LeerProducto(ifstream &arch);
    char* LeerCadena(ifstream &arch);
    return 0;
}


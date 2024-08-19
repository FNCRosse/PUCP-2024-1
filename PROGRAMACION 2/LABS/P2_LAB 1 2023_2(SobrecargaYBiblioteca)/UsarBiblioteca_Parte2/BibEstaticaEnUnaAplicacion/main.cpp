/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 1 de abril de 2024, 22:30
 */

#include <iostream>
using namespace std;
#include "Estructuras.h"
#include "FuncionesAux.h"
#define MAXC 150
#define MAXPR 170
#define MAXP 570

int main(int argc, char** argv) {
    int CantCli, CantProd,CantPed;
    Cliente ArrClientes[MAXC];
    Producto ArrProductos[MAXPR];
    Pedido ArrPedidos[MAXP];
    
    //LECTURA
    LeerClientes(CantCli,ArrClientes,"Clientes.csv");
    LeerProductos(CantProd,ArrProductos,"Productos.csv");
    LeerPedidos(CantPed,ArrPedidos,"Pedidos.csv");

    //AGREGACION
    AgregacionPedidoAProducto(CantPed,ArrPedidos,ArrProductos);
    AgregacionPedidoACliente(CantPed,ArrPedidos,ArrClientes);
    
    //IMPRESION
    ImprimirReporte(CantCli,ArrClientes,CantProd,ArrProductos,"Reporte.txt");
    

    return 0;
}


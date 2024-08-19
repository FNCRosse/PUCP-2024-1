/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 17 de abril de 2024, 18:35
 */

#include <iostream>
using namespace std;
#include "MetodoIncremento.h"

int main(int argc, char** argv) {
    char ***Libros,***PedidosLibros;
    int **stock,**PedidosClientes;
    bool **PedidoAtendidos;
    //Este arreglo es para luego poder ordenar los pedidos libro y pedidoAtendidos
    //Se llena con los pedidos que vas leyendo
    int *Pedidos;
    
    LecturaDeLibros("Libros.csv",Libros,stock);
    PruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",Libros,stock);
    
    AtencionDePedidos("Pedidos.txt",Libros,stock,PedidosClientes,PedidosLibros,PedidoAtendidos,Pedidos);
    PruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",Libros,stock);

    OrdenarPedidos(Pedidos,PedidosLibros,PedidoAtendidos);
    
    ReporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",PedidosClientes,PedidosLibros,
            PedidoAtendidos);

    return 0;
}


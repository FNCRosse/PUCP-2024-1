/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 17 de abril de 2024, 14:44
 */

#include <iostream>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

int main(int argc, char** argv) {
    char ***Libros, ***PedidosLibros;
    int **stock, **PedidosClientes;
    bool **PedidosAtendidos;
    
    LecturaDeLibros("Libros.csv",Libros,stock);
    PruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",Libros,stock);
    
    AtencionDePedidos("Pedidos.txt",Libros,stock,PedidosClientes,PedidosLibros,PedidosAtendidos);
    PruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",Libros,stock);

    ReporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",PedidosClientes,PedidosLibros,
                                                 PedidosAtendidos);

    return 0;
}


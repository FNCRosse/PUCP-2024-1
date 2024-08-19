/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 18:32
 */

#include <iostream>
using namespace std;
#include "PunteroGenerico.h"

int main(int argc, char** argv) {
    void *Libros, *Clientes,*Pedidos;
    
    LeerLibros(Libros,"Libros.csv");
    ImprimirLibros(Libros,"ReporteDeLibros.txt");
    
    LeerClientes(Clientes,"Cientes.csv");
    ImprimirClientes(Clientes,"ReporteDeClientes.txt");
    
    LeerPedidos(Libros,Clientes,Pedidos,"Pedidos.txt");
    ImprimirPedidos(Pedidos,"ReporteDePedidos.txt");

    return 0;
}


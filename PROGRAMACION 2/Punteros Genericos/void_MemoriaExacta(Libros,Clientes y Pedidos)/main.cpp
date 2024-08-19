/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de abril de 2024, 14:34
 */

#include <iostream>
using namespace std;
#include "PunteroGenericos.h"

int main(int argc, char** argv) {
    void * Libros,*Clientes,*Pedidos;
    
    LeerLibro(Libros,"Libros.csv");
    ImprimirLibros(Libros,"ReporteDeLibros.txt");
    
    LeerCliente(Clientes,"Cientes.csv");
    ImprimirClientes(Clientes,"ReporteDeClientes.txt");
//    
    LeerPedidos(Libros,Clientes,Pedidos,"Pedidos.txt");
    ImprimirPedidos(Pedidos,"ReporteDePedidos.txt");
    return 0;
}


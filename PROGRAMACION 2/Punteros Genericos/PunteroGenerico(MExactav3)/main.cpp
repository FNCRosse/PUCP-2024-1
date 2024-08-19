/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 19:54
 */

#include <iostream>
using namespace std;
#include "PunteroGenerico.h"

int main(int argc, char** argv) {
    void *Clientes,*Libros;
    
    LeerLibros(Libros,"Libros.csv");
    ImprimirLibros(Libros, "ReporteLibros.txt");
    
    LeerClientes(Clientes,"Cientes.csv");
    ImprimirClientes(Clientes, "ReporteClientesInicial.txt");
    
    AgregarPedidos(Clientes,Libros,"Pedidos.csv");
    ImprimirClientes(Clientes, "ReporteClientesFinal.txt");
    return 0;
}


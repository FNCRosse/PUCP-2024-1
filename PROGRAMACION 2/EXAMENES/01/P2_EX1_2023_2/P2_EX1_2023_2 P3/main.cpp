/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 14:32
 */

#include <iostream>
using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01FuncionesProductos.h"
#include "ColaConEnteros.h"
#include "ColaConProductos.h"
#include "ColaGenerica.h"
int main(int argc, char** argv) {
    char **CodigoDelProducto;
    int **FechaClienteCantidad;
    void *Productos;
    void *Cola;
    
    cargarPedidos(FechaClienteCantidad,CodigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(FechaClienteCantidad,CodigoDelProducto,"PruebaPedidos.txt");
    cargarProductos(Productos,"Productos.csv");
    pruebaDeCargaDeProductos(Productos);
    
    CargaEnteros(Cola,leeNumero,"numeros.txt");
    mostrarEnteros(Cola,imprimeNumero,"ReporteNumeros.txt");
    
    ProcesarPedidos(FechaClienteCantidad,CodigoDelProducto,Productos);
    reporteDePedidos(Productos,"reportefinal.txt");
    return 0;
}


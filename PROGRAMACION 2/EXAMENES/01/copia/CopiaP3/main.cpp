/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 07:33
 */

#include <iostream>
using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"
#include "Pregunta02Examen01PunteroGenerico.h"
#include "ColaConEntero.h"
#include "ColaGenerica.h"
#include "ColaConProductos.h"
int main(int argc, char** argv) {
    char **CodigoDelProducto;
    int **FechaClienteCantidad;
    void *Productos;
    void *Cola;
    cargarPedidos(FechaClienteCantidad,CodigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(FechaClienteCantidad,CodigoDelProducto,"PruebaPedidos.txt");
    cargaProductos(Productos,"Productos.csv");
    PruebaDeCargaProductos(Productos,"PruebaProductos.txt");
    
    CargaEntero(Cola,leeNumero,"numeros.txt");
    MostrarEnteros(Cola,ImprimeNumero,"ReporteNumeros.txt");
    
    procesarPedidos(FechaClienteCantidad,CodigoDelProducto,Productos);
    reporteDePedidos(Productos,"ReporteFinal.txt");
    return 0;
}


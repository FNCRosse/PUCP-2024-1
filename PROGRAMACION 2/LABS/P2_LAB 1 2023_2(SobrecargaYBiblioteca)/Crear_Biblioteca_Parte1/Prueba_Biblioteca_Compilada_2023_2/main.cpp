/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de marzo de 2024, 13:31
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "SobreCargas.h"

int main(int argc, char** argv) {
    Cliente cliente[10];
    Producto prod[10];
    Pedido ped1, ped2;
    
    ifstream archC ("Clientes.csv",ios::in);
    archC>>cliente[0];
    ifstream archPR ("Productos.csv",ios::in);
    archPR>>prod[0];
    ifstream archCP ("Pedidos.csv",ios::in);
    archCP>>ped1;
    
    cliente[1].dni = 0;
    strcpy(prod[1].codigo,"XXXXXXX");
    prod +=ped1;
    cliente += ped1;
    
    ofstream Prueba ("Prueba.txt",ios::out);
    Prueba<<cliente[0];
    Prueba<<endl;
    Prueba<<prod[0];
    Prueba<<endl;
    return 0;
}


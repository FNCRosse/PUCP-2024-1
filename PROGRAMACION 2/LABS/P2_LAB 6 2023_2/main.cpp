/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:12
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "ProductoEntregado.h"
#include "Almacen.h"
#include "Cliente.h"
#include "Pedido.h"
#include "Producto.h"
int BuscarCliente(Cliente *ArrClientes,int dni){
    for(int i=0;ArrClientes[i].GetDNI() !=0;i++){
        if(dni == ArrClientes[i].GetDNI() ) return i;
    } 
    return -1;
}
int BuscarProd(Producto *ArrProd,char * codigo){
    for(int i=0;ArrProd[i].GetCodigo()!= nullptr;i++){
        if(strcmp(codigo,ArrProd[i].GetCodigo())==0) return i;
    } 
    return -1;
}
int main(int argc, char** argv) {
    int nClientes=0,nProductos=0,NPedidos=0;
    class Cliente ArrClientes[150];
    class Producto ArrProd[200];
    class Pedido ArrPedidos[600];
    ifstream ArchC,ArchProd,ArchPed;
    ofstream RepCliente,RepProd;
    AperturaDeUnArchivoDeTextosParaLeer(ArchC,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(RepCliente,"PruebaClientes.txt");
    AperturaDeUnArchivoDeTextosParaLeer(ArchProd,"Productos.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(RepProd,"PruebaProductos.txt");
    AperturaDeUnArchivoDeTextosParaLeer(ArchPed,"Pedidos.csv");
    //LECTURA//
    while(true){
        ArchC>>ArrClientes[nClientes];
        if(ArchC.eof()) break;
        nClientes++;
    }
    while(true){
        ArchProd>>ArrProd[nProductos];
        if(ArchProd.eof()) break;
        nProductos++;
    }
    while(true){
        ArchPed>>ArrPedidos[NPedidos];
        if(ArchPed.eof()) break;
        NPedidos++;
    }
    //AGREGACION
    for(int i=0;i<NPedidos;i++){
        int PosProd = BuscarProd(ArrProd,ArrPedidos[i].GetCodigo());
        if(PosProd != -1){
          ArrProd[PosProd] += ArrPedidos[i];  
        } 
    }
    for(int i=0;i<NPedidos;i++){
        int PosCliente = BuscarCliente(ArrClientes,ArrPedidos[i].GetDni_Cliente());
        if(PosCliente != -1){
          ArrClientes[PosCliente] += ArrPedidos[i];  
        } 
    }
    for(int i=0;i<nClientes;i++){
        RepCliente<<ArrClientes[i];
    }
    for(int i=0;i<nProductos;i++){
        RepProd<<ArrProd[i];
    }
    return 0;
}


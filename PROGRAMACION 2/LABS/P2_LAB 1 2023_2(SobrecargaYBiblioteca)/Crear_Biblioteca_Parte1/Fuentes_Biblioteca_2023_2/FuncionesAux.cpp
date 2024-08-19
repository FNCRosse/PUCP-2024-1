/* 
 * File:   FuncionesAux.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 1 de abril de 2024, 20:41
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "FuncionesAux.h"
#include "SobreCargas.h"

void LeerClientes(int &CantCli, struct Cliente *arrClientes,const char* namefile){
    ifstream arch (namefile,ios::in);
    if( !arch.is_open()){
        cout<<"No se encontro el archivo "<<namefile;
        exit(1);
    }
    CantCli = 0;
    while(true){
        arch>>arrClientes[CantCli];
        if(arch.eof()) break;
        CantCli++;
    }
    arrClientes[CantCli+1].dni = 0;
    arch.close();
}
void LeerProductos(int &CantProd, struct Producto *ArrProductos,const char* namefile){
    ifstream arch (namefile,ios::in);
    if( !arch.is_open()){
        cout<<"No se encontro el archivo "<<namefile;
        exit(1);
    }
    CantProd = 0;
    while(true){
        arch>>ArrProductos[CantProd];
        if(arch.eof()) break;
        CantProd++;
    }
    strcpy(ArrProductos[CantProd+1].codigo,"XXXXXXX");
    arch.close();
}
void LeerPedidos(int &CantPed, struct Pedido *ArrPedidos,const char* namefile){
    ifstream arch (namefile,ios::in);
    if( !arch.is_open()){
        cout<<"No se encontro el archivo "<<namefile;
        exit(1);
    }
    CantPed = 0;
    while(true){
        arch>>ArrPedidos[CantPed];
        if(arch.eof()) break;
        CantPed++;
    }
    arch.close();
}
void AgregacionPedidoAProducto(int CantPed,struct Pedido *ArrPedidos,struct Producto *ArrProductos){
   for(int i=0;i<CantPed;i++){
       ArrProductos += ArrPedidos[i];
    }
}
void AgregacionPedidoACliente(int CantPed,struct Pedido *ArrPedidos,struct Cliente *arrClientes){
    for(int i=0;i<CantPed;i++){
       arrClientes += ArrPedidos[i];
    }
}
void ImprimirRepClientes(int CantCli,struct Cliente *arrClientes,const char* namefile){
    ofstream arch (namefile,ios::out);
    for(int i=0;i<CantCli;i++){
        arch<<arrClientes[i];
        arch<<endl;
    }
}
void ImprimirRepProductos(int CantProd,struct Producto *ArrProductos,const char* namefile){
    ofstream arch (namefile,ios::out);
    for(int i=0;i<CantProd;i++){
        arch<<ArrProductos[i];
        arch<<endl;
    }
}




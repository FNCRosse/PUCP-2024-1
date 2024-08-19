/* 
 * File:   FuncionesAux.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 1 de abril de 2024, 20:41
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
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
void ImprimirReporte(int CantCli,struct Cliente *arrClientes,int CantProd,struct Producto *ArrProductos,
                                        const char* namefile){
    ofstream arch (namefile,ios::out);
    arch<<right<<setw(80)<<"REPORTE DE CLIENTES"<<endl;
    arch<<left<<setw(12)<<"  DNI"<<setw(50)<<"Nombre y Apellido"<<setw(10)<<"Telefono"<<setw(18)<<
            "Monto Final"<<setw(20)<<"Productos Entregados"<<endl;
    for(int i=0;i<CantCli;i++){
        arch<<arrClientes[i];
        arch<<endl;
    }
    arch<<endl<<right<<setw(45)<<"REPORTE DE PRODUCTOS"<<endl;
    arch<<left<<setw(9)<<"Codigo"<<setw(49)<<"Descripcion"<<setw(8)<<"Precio"<<setw(15)<<
            "stock"<<endl;
    for(int i=0;i<CantProd;i++){
        arch<<ArrProductos[i];
        arch<<endl;
    }
}





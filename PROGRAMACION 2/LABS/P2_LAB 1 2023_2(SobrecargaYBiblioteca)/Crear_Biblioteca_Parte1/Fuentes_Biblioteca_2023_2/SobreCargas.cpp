/* 
 * File:   SobreCargas.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 1 de abril de 2024, 20:49
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Estructuras.h"

bool operator >> (ifstream &arch, struct Cliente &cliente){
    char c;
    arch>>cliente.dni>>c;
    if(arch.eof()) return false;
    arch.getline(cliente.nombre,60,',');
    arch>>cliente.telefono;
    cliente.cantidadProductosEntrgados =0;
    cliente.montoTotal = 0 ;
    return true;
}
bool operator >> (ifstream &arch, struct Producto &prod){
    char c;
    arch.getline(prod.codigo,8,',');
    if(arch.eof()) return false;
    arch.getline(prod.descripcion,60,',');
    arch>>prod.precio>>c>>prod.stock;
    arch.get();
    prod.cantidadClientesNoServidos=0;
    prod.cantidadClientesServidos=0;
    return true;
}
bool operator >> (ifstream &arch, struct Pedido &ped){
    arch.getline(ped.CodigoProducto,8,',');
    if(arch.eof()) return false;
    arch>>ped.dniCliente;
    arch.get();
    ped.precioProducto =0 ;
    return true;
}

bool operator += (struct Producto *ArrProd, struct Pedido &ped){
    int i=0,indice;
    while(true){
        if(strcmp(ArrProd[i].codigo,"XXXXXXX") == 0) break;
        Producto a = ArrProd[i];
        if(strcmp(ArrProd[i].codigo, ped.CodigoProducto)==0){
            ped.precioProducto = ArrProd[i].precio;
            if(ArrProd[i].stock >0){
                ArrProd[i].stock--;
                indice = ArrProd[i].cantidadClientesServidos;
                ArrProd[i].clientesServidos[indice] = ped.dniCliente;
                ArrProd[i].cantidadClientesServidos++;
                return true;
            }
            else{
                indice = ArrProd[i].cantidadClientesNoServidos;
                ArrProd[i].clientesNoServidos[indice] = ped.dniCliente;
                ArrProd[i].cantidadClientesNoServidos++;
                return false;
            }
            Producto a = ArrProd[i];
            break;
        }
        i++;
    }
    return false;
}
void operator += (struct Cliente *ArrCli, struct Pedido &ped){
    int i=0,indice;
    while(true){
        if(ArrCli[i].dni == 0) break;
        if(ped.dniCliente == ArrCli[i].dni){
            indice = ArrCli[i].cantidadProductosEntrgados;
            struct ProductoEntregado prodEntregado;
            prodEntregado.precio = ped.precioProducto;
            strcpy(prodEntregado.codigo,ped.CodigoProducto);
            
            ArrCli[i].productosEntregados[indice] = prodEntregado;
            ArrCli[i].cantidadProductosEntrgados++;
            ArrCli[i].montoTotal += ped.precioProducto;
            break;
        }
        i++;
    }
}

void operator <<(ofstream &arch, const struct Cliente &cliente){
    arch.precision(2);
    arch<<fixed;
    arch<<right<<setw(10)<<cliente.dni<<"  "<<left<<setw(45)<<cliente.nombre<<right<<setw(12)<<cliente.telefono
            <<setw(10)<<cliente.montoTotal<<"  "<<left<<"Productos Entregados: ";
    if(cliente.cantidadProductosEntrgados>0){
        for(int i=0;i<cliente.cantidadProductosEntrgados;i++) arch<<cliente.productosEntregados[i].codigo<<" ";
    }
    else{
        arch<<" NO SE LE ENTREGARON PRODUCTOS";
    }
}
void operator <<(ofstream &arch, const struct Producto &prod){
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(9)<<prod.codigo<<setw(45)<<prod.descripcion<<right<<setw(10)<<prod.precio<<setw(5)<<
            prod.stock<<endl;
    arch<<"Clientes atendidos:    ";
    if(prod.cantidadClientesServidos>0){
        for(int i=0;i<prod.cantidadClientesServidos;i++) arch<<prod.clientesServidos[i]<<" ";
        arch<<endl;
    }
    else{
        arch<<"NO SE ATENDIERON PEDIDOS"<<endl;
    }
    arch<<"Clientes no atendidos: ";
    if(prod.cantidadClientesNoServidos>0){
        for(int i=0;i<prod.cantidadClientesNoServidos;i++) arch<<prod.clientesNoServidos[i]<<" ";
    }
    else{
        arch<<"NO HAY CLIENTES SIN ATENDER";
    }
}

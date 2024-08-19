/* 
 * File:   Producto.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:23
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Producto.h"

Producto::Producto(){
    Codigo=nullptr;
    Descripcion=nullptr;
    Precio =0;
    stock=0;
    CantClienteServ=0;
    CantClienteNOServ=0;
}
bool Producto::Leer(ifstream &arch){
    char Buff[120],c;
    arch.getline(Buff,120,',');
    SetCodigo(Buff);
    if(arch.eof()) return false;
    arch.getline(Buff,120,',');
    SetDescripcion(Buff);
    arch>>Precio>>c>>stock;
    arch.get();
    return true;
}
bool Producto::operator +=(Pedido &ped){
    int stock = GetStock();
    if(stock >0){
        int cant = GetCantClienteServ();
        ClientesServidos[cant] = ped.GetDni_Cliente();
        SetCantClienteServ(cant+1);
        SetStock(stock-1);
        ped.SetPrecioProd(GetPrecio());
        return true;
    } else{
        int cant = GetCantClienteNOServ();
        ClientesNOServidos[cant] = ped.GetDni_Cliente();
        SetCantClienteNOServ(cant+1);
        SetStock(0);
        return false;
    }
}
void Producto::ImprimirClientes(ofstream &arch){
    arch<<"Clientes Atendidos:  ";
    if(GetCantClienteServ()==0) arch<<"NO SE ATENDIERON PEDIDOS"<<endl;
    else{
        for(int i=0;i<GetCantClienteServ();i++){
            arch<<ClientesServidos[i]<<"  ";
        }
        arch<<endl;
    }
    arch<<"Clientes no Atendidos:  ";
    if(GetCantClienteNOServ()==0) arch<<"NO HAY CLIENTES SIN ATENDER"<<endl;
    else{
        for(int i=0;i<GetCantClienteNOServ();i++){
            arch<<ClientesNOServidos[i]<<"  ";
        }
        arch<<endl;
    }
}
bool operator >>(ifstream &arch, Producto &P){
    if(P.Leer(arch)) return true;
    else return false;
}
void operator <<(ofstream &arch, Producto P){
    char *Codigo = P.GetCodigo();
    char *Desc = P.GetDescripcion();
    arch<<left<<setw(12)<<Codigo<<setw(65)<<Desc<<setw(10)<<P.GetPrecio()<<P.GetStock()<<endl;
    P.ImprimirClientes(arch);
    arch<<endl<<endl;
}
void Producto::SetCantClienteNOServ(int CantClienteNOServ) {
    this->CantClienteNOServ = CantClienteNOServ;
}

int Producto::GetCantClienteNOServ() const {
    return CantClienteNOServ;
}

void Producto::SetCantClienteServ(int CantClienteServ) {
    this->CantClienteServ = CantClienteServ;
}

int Producto::GetCantClienteServ() const {
    return CantClienteServ;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double Precio) {
    this->Precio = Precio;
}

double Producto::GetPrecio() const {
    return Precio;
}

void Producto::SetDescripcion(char* cad) {
    if(Descripcion != nullptr) delete Descripcion;
    Descripcion = new char[strlen(cad)+1];
    strcpy(Descripcion,cad);
}

char* Producto::GetDescripcion() const {
    char *Cad;
    Cad = new char[strlen(Descripcion)+1];
    strcpy(Cad,Descripcion);
    return Cad;
}

void Producto::SetCodigo(char* cad) {
   if(Codigo != nullptr) delete Codigo;
    Codigo = new char[strlen(cad)+1];
    strcpy(Codigo,cad);
}

char* Producto::GetCodigo() const {
    char *Cad;
    Cad = new char[strlen(Codigo)+1];
    strcpy(Cad,Codigo);
    return Cad;
}


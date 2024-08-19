/* 
 * File:   Cliente.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 20:13
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Cliente.h"

Cliente::Cliente(){
    DNI =0;
    Nombre = nullptr;
    cantLibros =0;
    PagoTotal =0;
}
void Cliente::Leer(ifstream &arch){
    char c, buff[100];
    arch>>DNI>>c;
    arch.getline(buff,100,'\n');
    SetNombre(buff);
}
void Cliente::AgregarPedido(LibroSolicitado LibSol){
    librosSolicitados[GetCantLibros()] = LibSol;
    int cant = GetCantLibros();
    SetCantLibros(cant+1);
}
void Cliente::ImprimirPedidos(ofstream &arch){
    char *Codigo;
    arch<<"Libro entregados:"<<endl;
    arch<<left<<setw(5)<<" "<<setw(12)<<"Pedido No."<<setw(12)<<"Codigo"<<"Precio"<<endl;
    for(int i=0;i<GetCantLibros();i++){
        if(librosSolicitados[i].IsAtendido()==true){
            Codigo = librosSolicitados[i].GetCodigoLib();
            arch<<left<<setw(5)<<" "<<setw(12)<<librosSolicitados[i].GetNumPedido()<<setw(12)
                    <<Codigo<<librosSolicitados[i].GetPrecio()<<endl;
        }
    }
    arch<<"Total a pagar: "<<GetPagoTotal()<<endl;
    arch<<"Libro NO entregados por falta de stock:"<<endl;
    arch<<left<<setw(5)<<" "<<setw(12)<<"Pedido No."<<setw(12)<<"Codigo"<<endl;
    for(int i=0;i<GetCantLibros();i++){
        if(librosSolicitados[i].IsAtendido()==false){
            Codigo = librosSolicitados[i].GetCodigoLib();
            arch<<left<<setw(5)<<" "<<setw(12)<<librosSolicitados[i].GetNumPedido()<<setw(12)
                    <<Codigo<<endl;
        }
    }
    arch<<endl<<endl;
}
void Cliente::CalcularPagoTotal(){
    double MontoTotal=0;
    for(int i=0;i<GetCantLibros();i++){
        MontoTotal += librosSolicitados[i].GetPrecio();
    }
    SetPagoTotal(MontoTotal);
}
 void Cliente::operator ++(){
     CalcularPagoTotal();
 }
bool Cliente::operator <<(LibroSolicitado LibSol){
    if(GetCantLibros()<30){
        AgregarPedido(LibSol);
        return true;
    } else{
        return false;
    }
}
void operator >>(ifstream &arch, Cliente &C){
    C.Leer(arch);
}
void operator <<(ofstream &arch, Cliente c){
    char *Nombre = c.GetNombre();
    arch<<left<<setw(50)<<Nombre<<c.GetDNI()<<endl;
    c.ImprimirPedidos(arch);
}
void Cliente::SetPagoTotal(double PagoTotal) {
    this->PagoTotal = PagoTotal;
}

double Cliente::GetPagoTotal() const {
    return PagoTotal;
}

void Cliente::SetCantLibros(int cantLibros) {
    this->cantLibros = cantLibros;
}

int Cliente::GetCantLibros() const {
    return cantLibros;
}

void Cliente::SetNombre(char* cad) {
    if(Nombre!=nullptr) delete Nombre;
    Nombre=new char[strlen(cad)+1];
    strcpy(Nombre,cad);
}

char* Cliente::GetNombre() const {
    char *cad;
    cad = new char[strlen(Nombre)+1];
    strcpy(cad,Nombre);
    return cad;
}

void Cliente::SetDNI(int DNI) {
    this->DNI = DNI;
}

int Cliente::GetDNI() const {
    return DNI;
}


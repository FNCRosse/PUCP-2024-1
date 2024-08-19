/* 
 * File:   Cliente.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 15:57
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Cliente.h"

Cliente::Cliente(){
    DNI = 0;
    Nombre =nullptr;
    CantLibros =0;
    PagoTotal =0.0;
}
void Cliente::Leer(ifstream &arch){
    char c,buff[100]{};
    arch>>DNI>>c;
    arch.getline(buff,100,'\n');
    SetNombre(buff);
}
void Cliente::agregarLibro(LibroSolicitado Libsol){
    librosSolicitados[GetCantLibros()] = Libsol;
    int cant = GetCantLibros();
    SetCantLibros(cant+1);
}
void Cliente::ImprimirCliente(ofstream &arch){
    int dni;
    char *nombre=new char[100]{};
    dni = GetDNI();
    GetNombre(nombre);
    arch<<left<<setw(55)<<nombre<<dni<<endl;
    ImprimirLibros(arch);
}
void Cliente::ImprimirLibros(ofstream &arch){
    class LibroSolicitado LibSol;
    arch<<"Libros entregados:"<<endl;
    arch<<setw(20)<<"Pedido No."<<setw(15)<<"Codigo"<<setw(12)<<"Precio"<<endl;
    for(int i=0;i<GetCantLibros();i++){
        GetLibroSolicitado(i,LibSol);
        if(LibSol.IsAtendido()==true) LibSol.imprimirPedido(arch);
    }
    arch<<"Total a pagar : "<<PagoTotal<<endl;
    arch<<"Libros no entregados por falta de stock:"<<endl;
    arch<<setw(20)<<"Pedido No."<<setw(15)<<"Codigo"<<endl;
    for(int i=0;i<GetCantLibros();i++){
        GetLibroSolicitado(i,LibSol);
        if(LibSol.IsAtendido() == false){LibSol.imprimirPedido(arch);}
    }
    arch<<endl<<endl;
}
void Cliente::GetLibroSolicitado(int pos, class LibroSolicitado &newLibSol){
    char *Codigo;
    Codigo = librosSolicitados[pos].GetCodigoLibro();
    newLibSol.SetAtendido(librosSolicitados[pos].IsAtendido());
    newLibSol.SetCodigoLibro(Codigo);
    newLibSol.SetNumPedido(librosSolicitados[pos].GetNumPedido());
    newLibSol.SetPrecio(librosSolicitados[pos].GetPrecio());
}
void Cliente::calculaTotal(){
    double MontoTotal=0;
    for(int i=0;i<GetCantLibros();i++){
        if(librosSolicitados[i].IsAtendido()==true) MontoTotal += librosSolicitados[i].GetPrecio();
    }
    SetPagoTotal(MontoTotal);
}
bool Cliente::operator <<(LibroSolicitado Libsol){
    if(GetCantLibros()<60){
        agregarLibro(Libsol);
        return true;
    } else {
        return false;
    }
}
void Cliente::operator ++(){
    calculaTotal();
}
void operator >> (ifstream &arch, Cliente &C){
    C.Leer(arch);
}
void operator << (ofstream &arch, Cliente C){
    C.ImprimirCliente(arch);
}
void Cliente::SetPagoTotal(double PagoTotal) {
    this->PagoTotal = PagoTotal;
}

double Cliente::GetPagoTotal() const {
    return PagoTotal;
}

void Cliente::SetCantLibros(int CantLibros) {
    this->CantLibros = CantLibros;
}

int Cliente::GetCantLibros() const {
    return CantLibros;
}

void Cliente::SetNombre(const char* cad) {
    if(Nombre != nullptr) delete Nombre;
    Nombre = new char[strlen(cad)+1];
    strcpy(Nombre,cad);
}

void Cliente::GetNombre(char *cad) const {
    if(Nombre == nullptr) cad[0]=0;
    strcpy(cad,Nombre);
}

void Cliente::SetDNI(int DNI) {
    this->DNI = DNI;
}

int Cliente::GetDNI() const {
    return DNI;
}


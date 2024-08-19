/* 
 * File:   Cliente.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:14
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Cliente.h"
#include "Pedido.h"

Cliente::Cliente(){
    DNI =0;
    Nombre =nullptr;
    Telefono=0;
    cantProdEnt=0;
    MontoTotal=0;
}
bool Cliente::Leer(ifstream &arch){
    char c,Buff[100];
    arch>>DNI;
    if(arch.eof()) return false;
    arch>>c;
    arch.getline(Buff,100,',');
    SetNombre(Buff);
    arch>>Telefono;
    arch.get();
    return true;
}
void Cliente::operator +=(Pedido Ped){
    char *Codigo = Ped.GetCodigo();
    ProductosEnt[GetCantProdEnt()].SetPrecio(Ped.GetPrecioProd());
    ProductosEnt[GetCantProdEnt()].SetCodigo(Codigo);
    int cantP= GetCantProdEnt();
    int monto = GetMontoTotal();
    SetCantProdEnt(cantP+1);
    SetMontoTotal(MontoTotal+Ped.GetPrecioProd());
}
void Cliente::ImprimirProdEnt(ofstream &arch){
    if(GetCantProdEnt() ==0 ){
        arch<<"NO SE LE ENTREGARON PRODUCTOS"<<endl;
        return;
    }
    for(int i=0;i<GetCantProdEnt();i++){
        char *Codigo = ProductosEnt[i].GetCodigo();
        arch<<Codigo<<"  ";
    } 
    arch<<endl;
}
bool operator >>(ifstream &arch, Cliente &C){
    if(C.Leer(arch)) return true;
    else return false;
}
void operator <<(ofstream &arch, Cliente C){
    arch.precision(2);
    arch<<fixed;
    char *Nombre = C.GetNombre();
    arch<<left<<setw(12)<<C.GetDNI()<<setw(40)<<Nombre<<setw(15)<<C.GetTelefono()<<setw(12)
            <<C.GetMontoTotal()<<setw(12)<<"Productos entregados: ";
    C.ImprimirProdEnt(arch);
}

void Cliente::SetMontoTotal(double MontoTotal) {
    this->MontoTotal = MontoTotal;
}

double Cliente::GetMontoTotal() const {
    return MontoTotal;
}

void Cliente::SetCantProdEnt(int cantProdEnt) {
    this->cantProdEnt = cantProdEnt;
}

int Cliente::GetCantProdEnt() const {
    return cantProdEnt;
}

void Cliente::SetTelefono(int Telefono) {
    this->Telefono = Telefono;
}

int Cliente::GetTelefono() const {
    return Telefono;
}

void Cliente::SetNombre(char* cad) {
    if(Nombre != nullptr) delete Nombre;
    Nombre = new char[strlen(cad)+1];
    strcpy(Nombre,cad);
}

char* Cliente::GetNombre() const {
    char *Cad;
    Cad = new char[strlen(Nombre)+1];
    strcpy(Cad,Nombre);
    return Cad;
}

void Cliente::SetDNI(int DNI) {
    this->DNI = DNI;
}

int Cliente::GetDNI() const {
    return DNI;
}


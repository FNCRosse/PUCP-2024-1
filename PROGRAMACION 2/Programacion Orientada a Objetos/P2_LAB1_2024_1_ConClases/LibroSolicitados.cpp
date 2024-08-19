/* 
 * File:   LibroSolicitados.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 15:57
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "LibroSolicitados.h"
LibroSolicitado :: LibroSolicitado(){
    Atendido = false;
    precio =0;
    numPedido=0;
}
bool LibroSolicitado::operator >>(Libro * L){
    char *cod,*codigo;
    double precioLibro;
    int stock;
    for(int i=0;strcmp(L[i].GetCodigo(),"FIN")!=0;i++){
        cod = GetCodigoLibro();
        codigo = L[i].GetCodigo();
        if(strcmp(cod,codigo)==0){
            stock = L[i].GetStock();
            if(stock>0){
                precioLibro = L[i].GetPrecio();
                SetPrecio(precioLibro);
                SetAtendido(true);
                L[i].SetStock(stock-1);
                return true;
            } else {
                SetAtendido(false);
                return false;
            }
        }
    }
    return false;
}
void LibroSolicitado::imprimirPedido(ofstream &arch){
    char *Codigo = GetCodigoLibro();
    int numpedido= GetNumPedido();
    double Precio = GetPrecio();
    arch<<setw(18)<<numpedido<<setw(15)<<Codigo;
    if(IsAtendido())arch<<setw(15)<<Precio<<endl;
    else arch<<endl;
}
void LibroSolicitado::SetAtendido(bool Atendido) {
    this->Atendido = Atendido;
}

bool LibroSolicitado::IsAtendido() const {
    return Atendido;
}

void LibroSolicitado::SetPrecio(double precio) {
    this->precio = precio;
}

double LibroSolicitado::GetPrecio() const {
    return precio;
}

void LibroSolicitado::SetCodigoLibro(const char*cad) {
    strcpy(CodigoLibro,cad);
}

char* LibroSolicitado::GetCodigoLibro() const {
    char *Cad;
    Cad =  new char [strlen(CodigoLibro)+1]{};
    strcpy(Cad,CodigoLibro);
    return Cad;
}

void LibroSolicitado::SetNumPedido(int numPedido) {
    this->numPedido = numPedido;
}

int LibroSolicitado::GetNumPedido() const {
    return numPedido;
}


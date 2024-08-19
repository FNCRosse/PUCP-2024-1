/* 
 * File:   LibroSolicitado.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 20:13
 */
#include <iostream>
#include <cstring>
using namespace std;
#include "LibroSolicitado.h"

LibroSolicitado::LibroSolicitado(){
    
}
bool LibroSolicitado::operator >>(Libro *L){
    char *CodLibro,*codigo;
    for(int i=0;strcmp(L[i].GetCodigo(),"FIN")!=0;i++){
        CodLibro = GetCodigoLib();
        codigo = L[i].GetCodigo();
        if(strcmp(codigo,CodLibro)==0){
            int stock = L[i].GetStock();
            if(stock>0){
                SetPrecio(L[i].GetPrecio());
                SetAtendido(true);
                L[i].SetStock(stock-1);
                return true;
            } else {
                SetAtendido(false);
                return false;
            }
        }
    }
}
void LibroSolicitado::SetAtendido(bool Atendido) {
    this->Atendido = Atendido;
}

bool LibroSolicitado::IsAtendido() const {
    return Atendido;
}

void LibroSolicitado::SetPrecio(double Precio) {
    this->Precio = Precio;
}

double LibroSolicitado::GetPrecio() const {
    return Precio;
}

void LibroSolicitado::SetCodigoLib(char* cad) {
    if(CodigoLib!=nullptr) delete CodigoLib;
    CodigoLib=new char[strlen(cad)+1];
    strcpy(CodigoLib,cad);
}

char* LibroSolicitado::GetCodigoLib() const {
    char *cad;
    cad = new char[strlen(CodigoLib)+1];
    strcpy(cad,CodigoLib);
    return cad;
}

void LibroSolicitado::SetNumPedido(int NumPedido) {
    this->NumPedido = NumPedido;
}

int LibroSolicitado::GetNumPedido() const {
    return NumPedido;
}


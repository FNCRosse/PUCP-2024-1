/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 20:51
 */
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Estante.h"
#include "Espacio.h"

Estante::Estante(){
    altura =0;
    anchura=0;
    codigo=nullptr;
}
void Estante::LeerDatos(ifstream &arch){
    char buff[100],c;
    arch.getline(buff,100,',');
    SetCodigo(buff);
    arch>>anchura>>c>>altura>>c;
    SetEspacio();
}
void Estante::ImprimirFilas(ofstream &arch,int pos){
    for(int i=pos;i<anchura*altura;i+=altura){
        espacio[i].Imprimir(arch);
    }
}
void Estante::ImprimirEspacios(ofstream &arch){
    for(int i=0;i<altura;i++){
        ImprimirFilas(arch,i);
        arch<<endl;
    }
}
void Estante::Imprimir(ofstream &arch){
    arch<<left<<"Codigo Estante: "<<setw(15)<<codigo<<endl
            <<"Anchura del estante: "<<setw(6)<<anchura<<"Altura del Estante: "<<altura<<endl;
    for(int i=0;i<120;i++)arch<<"-";
    arch<<endl;
    ImprimirEspacios(arch);
    arch<<endl;
}
int Estante::ObtenerSobrante(int sumaAnchLib){
    return anchura-sumaAnchLib;
}
bool Estante::SePuedeAgregarLibro(Libro &L,int sobrante){
    int anchoLib = L.GetAncho();
    int altoLib = L.GetAlto();
    if(sobrante>0 && anchoLib<=sobrante && altoLib<=altura){
        for(int i=1;i<=anchoLib;i++){
            int cont=0;
            int pos = (anchura-sobrante)*altura+(altura*i)-1;
            for(int k=pos;cont<altoLib;k--){
                espacio[k].SetContenido('*');
                cont++;
            }
        }
        return true;
    }else return false;
}

void Estante::SetEspacio() {
    if(altura != 0 and anchura !=0){
        espacio = new Espacio[altura*anchura];
    }
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* cad) {
    if( codigo != nullptr) delete codigo;
    codigo = new char [strlen(cad)+1];
    strcpy(codigo,cad);
}

void Estante::GetCodigo(char* cad) const {
    if(codigo == nullptr) cad[0] =0;
    else strcpy(cad,codigo);
}
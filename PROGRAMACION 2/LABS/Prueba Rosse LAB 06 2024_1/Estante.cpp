/* 
 * File:   Estante.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 10:05
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Estante.h"
#include "Libro.h"

Estante::Estante(){
    Codigo = nullptr;
    cantidad_libros =0;
    altura=0;
    anchura=0;
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
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
    if(Codigo != nullptr) delete Codigo;
    Codigo = new char[strlen(cad)+1];
    strcpy(Codigo,cad);
}

void Estante::GetCodigo(char *&cad) const {
    if(Codigo == nullptr) cad[0] =0;
    cad = new char[strlen(Codigo)+1];
    strcpy(cad,Codigo);
}
void Estante::SetEspacios(){
    if(altura != 0 and anchura !=0){
        espacios = new Espacio[altura*anchura];
    }
}
int Estante::getSobrartes(){
    /*  
        - - - - - Inicio
        * *
        - - - - - Final Con 1 libro de 2 de ancho, me quedaria 3 de anchura sobrante
     */
    int SumaAncLibros=0;
    for(int i=0;i<cantidad_libros;i++){
        SumaAncLibros += libros[i].GetAncho();
    }
    return anchura-SumaAncLibros;
}
bool Estante::operator += (Libro &L){
    int sobrante = getSobrartes();
    int altoLib = L.GetAlto();
    int anchoLibr = L.GetAncho();
    if(sobrante>0 and anchoLibr<=sobrante and altoLib<=altura){
        //Colocar los espacios del libro 
        for(int i=1; i<=anchoLibr;i++){
            int cont=0;
            int pos=(anchura-sobrante) * altura+(altura*i) -1;
            for(int k=pos;cont<altoLib;k--){
                espacios[k].SetContenido('*');
                cont++;
            }
        }
        //Agregar libro
        char buff[100];
        L.GetCodigo(buff);
        libros[cantidad_libros].SetCodigo(buff);
        L.GetNombre(buff);
        libros[cantidad_libros].SetNombre(buff);
        libros[cantidad_libros].SetAlto(L.GetAlto());
        libros[cantidad_libros].SetAncho(L.GetAncho());
        libros[cantidad_libros].SetColocado(true);
        cantidad_libros++;
        L.SetColocado(true);
        return true;
    } else {
        return false;
    }
}
void Estante::LeerDatos(ifstream &arch){
    char buff[10],c;
    arch.getline(buff,10,',');
    SetCodigo(buff);
    arch>>anchura>>c>>altura;
    arch.get();
    SetEspacios();
}
void Estante::Imprimir (ofstream &arch){
    arch<<left<<"Codigo Estante: "<<setw(15)<<Codigo<<"Cantidad de Libros: "<<cantidad_libros<<endl
            <<"Anchura del estante: "<<setw(6)<<anchura<<"Altura del Estante: "<<altura<<endl;
    for(int i=0;i<100;i++)arch<<"-";
    arch<<endl;
    ImprimirEspacios(arch);
    ImprimirLibros(arch);
}
void Estante::imprimirFilaEstante (int pos,ofstream &arch){
    for(int i=pos;i<altura*anchura;i+=altura){
        arch<<espacios[i];
    }
}
void Estante::ImprimirEspacios (ofstream &arch){
    for(int i=0;i<altura;i++){
        imprimirFilaEstante(i,arch);
        arch<<endl;
    }
    arch<<endl;
}
void Estante::ImprimirLibros (ofstream &arch){
    arch<<left<<setw(10)<<"Codigo"<<setw(29)<<"Nombre"<<setw(8)<<"Ancho"<<"Alto"<<endl;
    for(int i=0;i<100;i++)arch<<".";
    arch<<endl;
    for(int i=0;i<cantidad_libros;i++){
        arch<<libros[i];
    }
}
void operator >> (ifstream &arch,Estante &E){
    E.LeerDatos(arch);
}
void operator << (ofstream &arch,Estante E){
    E.Imprimir(arch);
}

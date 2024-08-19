/* 
 * File:   Tesoreria.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 20:04
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::CargarEscalas(const char* filename){
    ifstream arch(filename);
    if(not arch.is_open()){
        cout<<"No se pudo abri el archivo "<<filename<<endl;
        exit(1);
    }
    int cod;
    double precio;
    while(true){
        arch>>cod;
        if(arch.eof()) break; arch.get();
        arch>>precio;
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(precio);
    }
}
void Tesoreria::CargarAlumnos(const char* filename){
    ifstream arch(filename);
    if(not arch.is_open()){
        cout<<"No se pudo abri el archivo "<<filename<<endl;
        exit(1);
    }
    char tipo;
    int nP=0,nS=0,nV=0;
    while(true){
        arch>>tipo;
        if(arch.eof()) break; arch.get();
        if(tipo == 'P'){
            lpresencial[nP].LeerDatos(arch);
            nP++;
        } else if (tipo == 'S'){
            lsemipresencial[nS].LeerDatos(arch);
            nS++;
        } else if (tipo == 'V'){
            lvirtual[nV].LeerDatos(arch);
            nV++;
        }
    }
}
void Tesoreria::Actualiza(double credito){
    int esc;
    double PrecioEsc;
    for(int i=0; lpresencial[i].GetCodigo();i++){
        esc = lpresencial[i].GetEscala();
        PrecioEsc = lescala[esc-1].GetPrecio();
        lpresencial[i].Actualiza(credito*PrecioEsc);
    }
    for(int i=0; lsemipresencial[i].GetCodigo();i++){
        esc = lsemipresencial[i].GetEscala();
        PrecioEsc = lescala[esc-1].GetPrecio();
        lsemipresencial[i].Actualiza(credito*PrecioEsc);
    }
    for(int i=0; lvirtual[i].GetCodigo();i++){
        esc = lvirtual[i].GetEscala();
        PrecioEsc = lescala[esc-1].GetPrecio();
        lvirtual[i].Actualiza(credito*PrecioEsc);
    }
}
void Tesoreria::Imprime(const char* filename){
    ofstream arch (filename);
    arch.precision(2);
    arch<<fixed;
    arch<<left<<setw(20)<<"Codigo"<<setw(50)<<"Nombre"<<setw(20)<<"Escala"<<setw(25)<<"Licencia"
            <<"Total"<<endl;
    for(int i=0;i<200;i++)arch<<"=";
    arch<<endl;
    for(int i=0;lpresencial[i].GetCodigo();i++){
        lpresencial[i].Imprimir(arch);
    }
    for(int i=0;lsemipresencial[i].GetCodigo();i++){
        lsemipresencial[i].Imprimir(arch);
    }
    for(int i=0;lvirtual[i].GetCodigo();i++){
        lvirtual[i].Imprimir(arch);
    }
}


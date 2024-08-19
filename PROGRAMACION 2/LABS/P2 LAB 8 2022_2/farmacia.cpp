/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   farmacia.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 16:26
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "farmacia.h"

farmacia::farmacia(){
    
}
void farmacia::CargarMedico(){
    ifstream arch("medicos.csv");
    int cantmed=0,cod;
    char buff[100];
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        arch.getline(buff,100,',');
        lmedico[cantmed].SetNombre(buff);
        arch.getline(buff,100,'\n');
        lmedico[cantmed].SetEspecialidad(buff);
        lmedico[cantmed].SetCodigo(cod);
        cantmed++;
    }
}
char* farmacia::BuscarEspecialidad(int codmed){
    char *especialidad=new char[100];
    for(int i=0;lmedico[i].GetCodigo()!=0;i++){
        if(lmedico[i].GetCodigo() == codmed){
            lmedico[i].GetEspecialidad(especialidad);
            return especialidad;
        }
    }
    return nullptr;
}
void farmacia::LeeRecetas(){
    ifstream arch("recetas.csv");
    int dia,mes,anio,dni,codmed,codmedicina,cant;
    int nCR=0,nSR=0;
    char c,buff[100];
    while(true){
        arch>>dia;
        if(arch.eof()) break;
        arch>>c>>mes>>c>>anio>>c>>dni>>c;
        arch.getline(buff,100,',');
        arch>>codmed>>c;
        while(true){
            arch>>codmedicina>>c>>cant;
            if(((codmedicina/10000)%2)==0){
                char *especialidad = BuscarEspecialidad(codmed);
                lconReceta[nCR].IngresarDatos(anio*10000+mes*100+dia,codmed,codmedicina,cant,especialidad);
                nCR++;
            } else {
                lsinReceta[nSR].IngresarDatos(anio*10000+mes*100+dia,dni,codmedicina,cant,buff);
                nSR++;
            }
            if(arch.get() == '\n') {
                break;
            }
        }
    }
}
void farmacia::ImprimirRecetas(){
    ofstream arch ("ReporteFinal.txt");
    arch<<left<<setw(10)<<"Codigo"<<setw(50)<<"Descripcion del Med."<<setw(20)<<"Cant."<<setw(18)<<"DNI"
            <<"Nombre"<<endl;
    for(int i=0;i<110;i++)arch<<"=";
    arch<<endl;
   
    for(int i=0;lsinReceta[i].GetCodigo()!=0;i++){
        lsinReceta[i].Imprimir(arch);
    }
    arch<<left<<setw(10)<<"Codigo"<<setw(50)<<"Descripcion del Med."<<setw(15)<<"Cant."<<setw(20)<<"Cod. Medico"
            <<"Especialidad"<<endl;
    for(int i=0;i<110;i++)arch<<"=";
    arch<<endl;
    for(int i=0;lconReceta[i].GetCodigo()!=0;i++){
        lconReceta[i].Imprimir(arch);
    }
}
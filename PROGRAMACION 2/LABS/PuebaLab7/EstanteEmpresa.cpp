/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   EstanteEmpresa.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 21:12
 */
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "EstanteEmpresa.h"

EstanteEmpresa::EstanteEmpresa(){
    RUC=0;
    cantLib=0;
}
void EstanteEmpresa::Leer(ifstream &arch){
    Estante::LeerDatos(arch);
    arch>>RUC;
    arch.get();
}
void EstanteEmpresa::Imprimir(ofstream &arch){
    arch<<left<<"El RUC del Colegio: "<<setw(15)<<RUC<<"Cantidad de Libros: "<<cantLib<<endl;
    Estante::Imprimir(arch);
    arch<<left<<setw(10)<<"Codigo"<<setw(29)<<"Nombre"<<setw(8)<<"Ancho"<<setw(10)<<"Alto"<<"Materia"<<endl;
    for(int i=0;i<cantLib;i++){
        librosEdu[i].Imprimir(arch);
    }
}
bool EstanteEmpresa::AgregarLibro(LibroEducativo &L){
    int sobrante = GetSobrante();
    bool bandera = Estante::SePuedeAgregarLibro(L,sobrante);
    if(bandera == true){
        char buff[100];
        L.GetCodigo(buff);
        librosEdu[cantLib].SetCodigo(buff);
        L.GetNombre(buff);
        librosEdu[cantLib].SetNombre(buff);
        L.GetMateria(buff);
        librosEdu[cantLib].SetMateria(buff);
        librosEdu[cantLib].SetAlto(L.GetAlto());
        librosEdu[cantLib].SetAncho(L.GetAncho());
        librosEdu[cantLib].SetColocado(true);
        L.SetColocado(true);
        cantLib++;
        return true;
    } else return false;
}
int  EstanteEmpresa::GetSobrante(){
    int sumaAnchLib=0;
    for(int i=0;i<cantLib;i++){
        sumaAnchLib+=librosEdu[i].GetAncho();
    }
    int sobrante = Estante::ObtenerSobrante(sumaAnchLib);
    return sobrante;
}
void EstanteEmpresa::SetRUC(int RUC) {
    this->RUC = RUC;
}

int EstanteEmpresa::GetRUC() const {
    return RUC;
}
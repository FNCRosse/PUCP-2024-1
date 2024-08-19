/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   EstantePsicologia.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 21:13
 */
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "EstantePsicologia.h"

EstantePsicologia::EstantePsicologia(){
    codPsicologo=0;
    cantLib=0;
}
void EstantePsicologia::Leer(ifstream &arch){
    Estante::LeerDatos(arch);
    arch>>codPsicologo;
    arch.get();
}
void EstantePsicologia::Imprimir(ofstream &arch){
    arch<<left<<"El Codigo del Psicologo: "<<codPsicologo<<"Cantidad de Libros: "<<cantLib<<endl;
    Estante::Imprimir(arch);
    arch<<left<<setw(10)<<"Codigo"<<setw(29)<<"Nombre"<<setw(8)<<"Ancho"<<setw(10)<<"Alto"<<"Ranking"<<endl;
    for(int i=0;i<cantLib;i++){
        librosPsico[i].Imprimir(arch);
    }
}
bool EstantePsicologia::AgregarLibro(LibroPsicologia &L){
    int sobrante = GetSobrante();
    bool bandera = Estante::SePuedeAgregarLibro(L,sobrante);
    if(bandera == true){
        char buff[100];
        L.GetCodigo(buff);
        librosPsico[cantLib].SetCodigo(buff);
        L.GetNombre(buff);
        librosPsico[cantLib].SetNombre(buff);
        librosPsico[cantLib].SetRanking(L.GetRanking());
        librosPsico[cantLib].SetAlto(L.GetAlto());
        librosPsico[cantLib].SetAncho(L.GetAncho());
        librosPsico[cantLib].SetColocado(true);
        L.SetColocado(true);
        cantLib++;
        return true;
    } else return false;
}
int  EstantePsicologia::GetSobrante(){
    int sumaAnchLib=0;
    for(int i=0;i<cantLib;i++){
        sumaAnchLib+=librosPsico[i].GetAncho();
    }
    int sobrante = Estante::ObtenerSobrante(sumaAnchLib);
    return sobrante;
}
void EstantePsicologia::SetCodPsicologo(int codPsicologo) {
    this->codPsicologo = codPsicologo;
}

int EstantePsicologia::GetCodPsicologo() const {
    return codPsicologo;
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   LibroPsicologia.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 21:10
 */

#include "LibroPsicologia.h"

LibroPsicologia::LibroPsicologia(){
    Ranking=0;
}
void LibroPsicologia::Leer(ifstream &arch){
    Libro::LeerDatos(arch);
    arch>>Ranking;
    arch.get();
}
void LibroPsicologia::Imprimir(ofstream &arch){
    Libro::Imprimir(arch);
    arch<<Ranking<<endl;
}
void LibroPsicologia::SetRanking(int Ranking) {
    this->Ranking = Ranking;
}

int LibroPsicologia::GetRanking() const {
    return Ranking;
}
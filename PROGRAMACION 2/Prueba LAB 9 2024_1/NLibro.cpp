/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NLibro.cpp
 * Author: Rosse
 * 
 * Created on 9 de julio de 2024, 05:46
 */

#include "NLibro.h"
#include "Enciclopedia.h"
#include "Revista.h"
#include "Novela.h"

NLibro::NLibro(){
    plibro = nullptr;
}
void NLibro::AsignarTipo(char tipo){
    switch(tipo){
        case 'E':
            plibro = new Enciclopedia();
            break;
        case 'R':
            plibro = new Revista();
            break;
        case 'N':
            plibro = new Novela();
            break;
    }
}
void NLibro::Leer(ifstream &arch){
    plibro->Leer(arch);
}
void NLibro::imprime(ofstream &arch){
    plibro->imprime(arch);
}
double NLibro::GetPeso(){
    return plibro->GetPeso();
}
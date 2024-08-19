/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   NEstante.cpp
 * Author: Rosse
 * 
 * Created on 9 de julio de 2024, 05:49
 */

#include "NEstante.h"

NEstante::NEstante() {
    izq = nullptr;
    der = nullptr;
    vlibros = vector<class NLibro>();
}

bool NEstante::LeerDatos(ifstream &arch) {
    arch>>id;
    if(arch.eof()) return true;
    arch.get();
    arch>>capacidad;
    SetDisponible(capacidad);
    arch.get();
    return false;
}
void NEstante::LeerLibros(ifstream &arch){
    class NLibro libro;
    char tipo;
    for(int i=0;i<10;i++){
        arch>>tipo;
        arch.get();
        libro.AsignarTipo(tipo);
        libro.Leer(arch);
        if(GetDisponible()-libro.GetPeso() >=0){
            vlibros.push_back(libro);
            SetDisponible(GetDisponible()-libro.GetPeso());
        }
    }
}
void NEstante::imprimeDatos(ofstream &arch) {
    arch << "Estante: " << id << endl;
    arch << "Capacidad: " << setw(10) << capacidad << "Disponible: " << disponible << endl;
    for (int i = 0; i < 100; i++)arch << "=";
    arch << endl;
    if (!vlibros.empty()) {
        for (class NLibro libro : vlibros) {
            libro.imprime(arch);
        }
        arch<<endl;
    }
}

void NEstante::SetDer(NEstante* der) {
    this->der = der;
}

NEstante* NEstante::GetDer() const {
    return der;
}

void NEstante::SetIzq(NEstante* izq) {
    this->izq = izq;
}

NEstante* NEstante::GetIzq() const {
    return izq;
}

void NEstante::SetVlibros(vector<NLibro> vlibros) {
    this->vlibros = vlibros;
}

vector<NLibro> NEstante::GetVlibros() const {
    return vlibros;
}

void NEstante::SetDisponible(double disponible) {
    this->disponible = disponible;
}

double NEstante::GetDisponible() const {
    return disponible;
}

void NEstante::SetCapacidad(double capacidad) {
    this->capacidad = capacidad;
}

double NEstante::GetCapacidad() const {
    return capacidad;
}

void NEstante::SetId(int id) {
    this->id = id;
}

int NEstante::GetId() const {
    return id;
}
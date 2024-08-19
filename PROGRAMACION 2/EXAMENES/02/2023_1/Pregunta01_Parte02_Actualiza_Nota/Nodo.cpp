/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Nodo.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 16:58
 */

#include "Nodo.h"

Nodo::Nodo(){
    siguiente = nullptr;
    anterior = nullptr;
}
void Nodo::AsignarAlumno(class Alumno &al){
    dato.SetAlumno(al);
}
void Nodo::AsignarNotas(ifstream &arch, int ciclo){
    dato.SetNotas(arch,ciclo);
}
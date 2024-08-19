/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   LVehiculos.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 15:47
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "LVehiculos.h"
#include "NodoLista.h"
#include "NPedido.h"

LVehiculos::LVehiculos() {

}

LVehiculos::~LVehiculos() {

}

void LVehiculos::Insertar(class NodoLista *&nuevoNodo) {
    if(lini == nullptr){
        lini = nuevoNodo;
        lfin = nuevoNodo;
    } else{
        lfin->sig = nuevoNodo;
        lfin = nuevoNodo;
    }
}

void LVehiculos::Asignar(char tipo, ifstream &arch) {
    NodoLista *nuevo;
    switch(tipo){
        case 'F':
            nuevo = new class NodoLista(tipo);
            break;
        case 'C':
            nuevo = new class NodoLista(tipo);
            break;
    }
    nuevo->LeerDatos(arch);
    Insertar(nuevo);
}

void LVehiculos::Imprimir(ofstream &arch) {
    class NodoLista * nodo = lini;
    while(nodo){
        nodo->ImprimirDatos(arch);
        nodo = nodo->sig;
    }
}
void LVehiculos::ColocarPedidos(ifstream &arch){
    NPedido nodoPed;
    int codCliente,cant;
    double peso;
    char buff[30],c;
    while(true){
        arch>>codCliente;
        if(arch.eof()) break;
        arch.get();
        arch.getline(buff,30,',');
        arch>>cant>>c>>peso;
        arch.get();
        nodoPed.SetPeso(peso);
        nodoPed.SetCantidad(cant);
        nodoPed.SetCodigo(buff);
        InsertarPedido(codCliente,nodoPed);
    }
}
void LVehiculos::InsertarPedido(int codCliente,class NPedido &nodoPed){
    NodoLista *Recorrer = lini;
    while (Recorrer) {
        double pesoAct = Recorrer->unidad->GetActcarga();
        double peso = nodoPed.GetPeso();
        int cliente = Recorrer->unidad->GetCliente();
        if(cliente == codCliente and peso+pesoAct<= Recorrer->unidad->GetMaxcarga()){
            Recorrer->InsertarPedido(nodoPed);
            pesoAct += peso;
            Recorrer->unidad->SetActcarga(pesoAct);
        }
        Recorrer = Recorrer->sig;
    }

}
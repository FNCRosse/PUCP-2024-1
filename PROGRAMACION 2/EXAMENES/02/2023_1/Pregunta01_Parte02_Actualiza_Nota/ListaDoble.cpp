/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   ListaDoble.cpp
 * Author: Rosse
 * 
 * Created on 8 de julio de 2024, 17:15
 */

#include "ListaDoble.h"

ListaDoble::ListaDoble(){
    inicio = nullptr;
    fin = nullptr;
}
void ListaDoble::insertarAlumno(class Alumno &datoA){
    class Nodo* nuevo = new Nodo();
    nuevo->AsignarAlumno(datoA);
    class Nodo *recorrer= inicio,*anterior=nullptr;
    while(recorrer != nullptr and recorrer->dato.GetCodigo() > datoA.GetCodigo_alumno()){
        if(recorrer->dato.GetCodigo() == datoA.GetCodigo_alumno()){
            delete nuevo;
            return;
        }
        anterior = recorrer;
        recorrer = recorrer->siguiente;
    }
    if(anterior == nullptr){
        nuevo->siguiente = inicio;
        if(inicio != nullptr) inicio->anterior= nuevo;
        inicio = nuevo;
        if(inicio->siguiente == nullptr) fin = nuevo;
    } else {
        nuevo->siguiente = anterior->siguiente;
        if(nuevo->siguiente == nullptr) fin = nuevo;
        else anterior->siguiente->anterior = nuevo;
        anterior->siguiente = nuevo;
        nuevo->anterior = anterior;
    }
}
void ListaDoble::Imprimir(ofstream &arch){
    class Nodo* recorrer = inicio;
    while(recorrer){
        recorrer->dato.Imprimir(arch);
        recorrer  =recorrer->siguiente;
    }
}
void ListaDoble::ActualizarCalificaciones(){
    class Nodo* recorrer = inicio;
    while(recorrer!= nullptr ){
        recorrer->dato.Actualizar();
        recorrer->dato.totalizar();
        recorrer  =recorrer->siguiente;
    }
}
void ListaDoble::insertarNotas(int ciclo,int codAlumno,ifstream &arch){
    class Nodo* recorrer = inicio;
    while(recorrer!= nullptr and recorrer->dato.GetCodigo() !=codAlumno){
        recorrer  =recorrer->siguiente;
    }
    if(recorrer!=nullptr){
        recorrer->AsignarNotas(arch,ciclo);
    }else while(arch.get()!='\n');
}
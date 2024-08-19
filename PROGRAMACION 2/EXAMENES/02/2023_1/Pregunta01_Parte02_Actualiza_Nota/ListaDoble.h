/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   ListaDoble.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 17:15
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "Util.h"
#include "Nodo.h"
class ListaDoble{
private:
    class Nodo *inicio;
    class Nodo *fin;
public:
    ListaDoble();
    void insertarAlumno(class Alumno &datoA);
    void Imprimir(ofstream &arch);
    void insertarNotas(int,int codAlumno,ifstream &archN);
    void ActualizarCalificaciones();
};
#endif /* LISTADOBLE_H */

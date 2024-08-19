/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 16:58
 */

#ifndef NODO_H
#define NODO_H
#include "Util.h"
#include "AlumnoNotas.h"
#include "ListaDoble.h"
class Nodo{
private:
    AlumnoNotas dato;
    class Nodo* siguiente;
    class Nodo* anterior;
public:
    Nodo();
    void AsignarAlumno(class Alumno &al);
    void AsignarNotas(ifstream &arch, int);
    friend class ListaDoble;
};
#endif /* NODO_H */

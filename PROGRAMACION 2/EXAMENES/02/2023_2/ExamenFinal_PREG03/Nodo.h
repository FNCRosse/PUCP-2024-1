/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 12:55
 */

#ifndef NODO_H
#define NODO_H
#include "Util.h"
#include "Vehiculo.h"
class Nodo{
private:
    class Vehiculo* unidad;
    class Nodo* izq;
    class Nodo* der;
public:
    Nodo();
    friend class Arbol;
};
#endif /* NODO_H */

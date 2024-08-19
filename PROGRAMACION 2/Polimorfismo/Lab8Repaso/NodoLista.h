/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NodoLista.h
 * Author: Rosse
 *
 * Created on 13 de junio de 2024, 20:46
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "LVehiculos.h"
class NodoLista{
private:
    class Vehiculo *unidad;
    class NodoLista *sig;
public:
    NodoLista(char tipo);
    void Imprimir(ofstream&arch);
    void Leer(ifstream&arch);
    friend class LVehiculos;
};
#endif /* NODOLISTA_H */

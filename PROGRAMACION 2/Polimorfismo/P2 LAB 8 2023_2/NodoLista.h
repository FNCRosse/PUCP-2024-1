/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NodoLista.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 15:45
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Vehiculo.h"
class NodoLista{
private:
    class Vehiculo *unidad;
    class NodoLista *sig;
public:
    NodoLista(char tipo);
    void LeerDatos(ifstream &arch);
    void ImprimirDatos(ofstream &arch);
    void InsertarPedido(class NPedido &nodoPed);
    friend class LVehiculos;
    
};
#endif /* NODOLISTA_H */

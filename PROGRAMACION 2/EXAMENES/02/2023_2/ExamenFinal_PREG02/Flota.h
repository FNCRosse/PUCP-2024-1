/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 11:59
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "Util.h"
#include "Vehiculo.h"
class Flota{
private:
    map<string,class Vehiculo*> vehiculos;
public:
    void Cargar_Vehiculo();
    void Mostrar_Vehiculo();
    void Cargar_Pedido();
    void ImprimirLinea(int n, char c, ofstream &arch);
};
#endif /* FLOTA_H */

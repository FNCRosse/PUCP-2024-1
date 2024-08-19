/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   LVehiculos.h
 * Author: Rosse
 *
 * Created on 13 de junio de 2024, 20:48
 */

#ifndef LVEHICULOS_H
#define LVEHICULOS_H
#include "NodoLista.h"
class LVehiculos{
private:
    class NodoLista *lini;
    class NodoLista *lfin;
public:
    LVehiculos();
    void AsignarVehiculo(char tipo,ifstream &arch);
    void Insertar(class NodoLista *&nuevoNodo);
    void ImprimirFlota(ofstream&arch);
};
#endif /* LVEHICULOS_H */

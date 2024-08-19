/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   LVehiculos.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 15:47
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
    virtual ~LVehiculos();
    void Insertar (class NodoLista *&dato);
    void Asignar (char tipo, ifstream &arch);
    void Imprimir(ofstream &arch );
    void ColocarPedidos(ifstream &arch);
    void InsertarPedido(int codCliente,class NPedido &nodoPed);
};
#endif /* LVEHICULOS_H */

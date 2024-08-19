/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Almacen.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 15:47
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include "OrdenVenta.h"
class Almacen{
private:
    OrdenVenta ordenes[600];
    int cantidad_ordenes;
public:
    Almacen();
    void SetCantidad_ordenes(int cantidad_ordenes);
    int GetCantidad_ordenes() const;
    
    void CargarPedidos();
    void Actualizar_Pedidos();
    void ImprimirOrdenesVenta();
};
#endif /* ALMACEN_H */

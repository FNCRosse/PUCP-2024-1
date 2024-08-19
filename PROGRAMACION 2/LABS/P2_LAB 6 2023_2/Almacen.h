/* 
 * File:   Almacen.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:32
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include "Cliente.h"
#include "Producto.h"
class Almacen{
private:
    Cliente ArrClientes[150];
    Producto ArrProd[200];
    int CantClientes;
    int cantProductos;
public:
    Almacen();
    void SetCantProductos(int cantProductos);
    int GetCantProductos() const;
    void SetCantClientes(int CantClientes);
    int GetCantClientes() const;
};


#endif /* ALMACEN_H */


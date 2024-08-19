/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   OrdenVenta.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 15:45
 */

#ifndef ORDENVENTA_H
#define ORDENVENTA_H
#include "Pedido.h"
class OrdenVenta{
private:
    Pedido *ptr_orden;
public:
    OrdenVenta();
    void LeerDatos(ifstream &arch,char tipo);
};
#endif /* ORDENVENTA_H */

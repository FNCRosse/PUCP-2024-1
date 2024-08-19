/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 11:44
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include "Util.h"
class Pedido{
private:
    string codigo;
    int cantidad;
    double peso;
public:
    Pedido();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(string codigo);
    string GetCodigo() const;
    
    void LeerPedido(ifstream &arch);
    void ImprimirPedido(ofstream &arch);
    bool operator < (const class Pedido &other)const;
};
#endif /* PEDIDO_H */

/* 
 * File:   Producto.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:21
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "Pedido.h"
class Producto{
private:
    char *Codigo;
    char *Descripcion;
    double Precio;
    int stock;
    int ClientesServidos[100];
    int ClientesNOServidos[100];
    int CantClienteServ;
    int CantClienteNOServ;
public:
    Producto();
    void SetCantClienteNOServ(int CantClienteNOServ);
    int GetCantClienteNOServ() const;
    void SetCantClienteServ(int CantClienteServ);
    int GetCantClienteServ() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetPrecio(double Precio);
    double GetPrecio() const;
    void SetDescripcion(char* Descripcion);
    char* GetDescripcion() const;
    void SetCodigo(char* Codigo);
    char* GetCodigo() const;
    
    bool Leer(ifstream &arch);
    bool operator +=(Pedido &ped);
    void ImprimirClientes(ofstream &arch);
};
bool operator >>(ifstream &arch, Producto &P);
void operator <<(ofstream &arch, Producto P);

#endif /* PRODUCTO_H */


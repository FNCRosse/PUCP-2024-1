/* 
 * File:   Cliente.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:14
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "ProductoEntregado.h"
#include "Pedido.h"

class Cliente{
private:
    int DNI;
    char *Nombre;
    int Telefono;
    ProductoEntregado ProductosEnt[100];
    int cantProdEnt;
    double MontoTotal;
public:
    Cliente();
    void SetMontoTotal(double MontoTotal);
    double GetMontoTotal() const;
    void SetCantProdEnt(int cantProdEnt);
    int GetCantProdEnt() const;
    void SetTelefono(int Telefono);
    int GetTelefono() const;
    void SetNombre(char* Nombre);
    char* GetNombre() const;
    void SetDNI(int DNI);
    int GetDNI() const;
    
    bool Leer(ifstream &arch);
    void ImprimirProdEnt(ofstream &arch);
    void operator +=(Pedido Ped);
};
bool operator >>(ifstream &arch, Cliente &C);
void operator <<(ofstream &arch, Cliente C);

#endif /* CLIENTE_H */


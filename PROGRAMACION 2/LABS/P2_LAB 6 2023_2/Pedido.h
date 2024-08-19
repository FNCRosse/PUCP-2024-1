/* 
 * File:   Pedido.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:29
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <fstream>
using namespace std;

class Pedido{
private:
    char *Codigo;
    int Dni_Cliente;
    double PrecioProd;
public:
    Pedido();
    void SetPrecioProd(double PrecioProd);
    double GetPrecioProd() const;
    void SetDni_Cliente(int Dni_Cliente);
    int GetDni_Cliente() const;
    void SetCodigo(char* Codigo);
    char* GetCodigo() const;
    bool Leer(ifstream &arch);
};
bool operator >>(ifstream &arch, Pedido &P);

#endif /* PEDIDO_H */


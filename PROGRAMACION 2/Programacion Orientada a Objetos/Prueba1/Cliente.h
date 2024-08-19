/* 
 * File:   Cliente.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 20:13
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "LibroSolicitado.h"

class Cliente{
private:
    int DNI;
    char *Nombre;
    LibroSolicitado librosSolicitados[30];
    int cantLibros;
    double PagoTotal;
public:
    Cliente();
    void SetPagoTotal(double PagoTotal);
    double GetPagoTotal() const;
    void SetCantLibros(int cantLibros);
    int GetCantLibros() const;
    void SetNombre(char* Nombre);
    char* GetNombre() const;
    void SetDNI(int DNI);
    int GetDNI() const;
    
    void Leer(ifstream &arch);
    void AgregarPedido(LibroSolicitado LibSol);
    void ImprimirPedidos(ofstream &arch);
    void CalcularPagoTotal();
    bool operator <<(LibroSolicitado LibSol);
    void operator ++();
};

void operator >>(ifstream &arch, Cliente &C);
void operator <<(ofstream &arch, Cliente c);

#endif /* CLIENTE_H */


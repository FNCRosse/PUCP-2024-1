/* 
 * File:   Cliente.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 15:57
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include "LibroSolicitados.h"

class Cliente{
private:
    int DNI;
    char* Nombre;
    int CantLibros;
    LibroSolicitado librosSolicitados[60];
    double PagoTotal;
public:
    Cliente();
    void SetPagoTotal(double PagoTotal);
    double GetPagoTotal() const;
    void SetCantLibros(int CantLibros);
    int GetCantLibros() const;
    void SetNombre(const char* Nombre);
    void GetNombre(char *) const;
    void SetDNI(int DNI);
    int GetDNI() const;
    void GetLibroSolicitado(int pos, class LibroSolicitado &newLibSol);
    
    void Leer(ifstream &arch);
    void agregarLibro(LibroSolicitado Libsol);
    void ImprimirLibros(ofstream &arch);
    void ImprimirCliente(ofstream &arch);
    void calculaTotal();
    bool operator <<(LibroSolicitado Libsol);
    void operator ++();
};

void operator >> (ifstream &arch, Cliente &C);
void operator << (ofstream &arch, Cliente C);

#endif /* CLIENTE_H */


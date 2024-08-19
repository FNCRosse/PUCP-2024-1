/* 
 * File:   LibroSolicitados.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 15:57
 */

#ifndef LIBROSOLICITADOS_H
#define LIBROSOLICITADOS_H

#include "Libro.h"

class LibroSolicitado{
private:
    int numPedido;
    char CodigoLibro[8];
    double precio;
    bool Atendido;
public:
    LibroSolicitado();
    void SetAtendido(bool Atendido);
    bool IsAtendido() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigoLibro(const char* CodigoLibro);
    char* GetCodigoLibro() const;
    void SetNumPedido(int numPedido);
    int GetNumPedido() const;
    
    void imprimirPedido(ofstream &arch);
    bool operator >>(Libro * L);
};

#endif /* LIBROSOLICITADOS_H */


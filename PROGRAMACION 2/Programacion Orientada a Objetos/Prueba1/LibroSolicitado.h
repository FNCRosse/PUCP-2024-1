/* 
 * File:   LibroSolicitado.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 20:13
 */

#ifndef LIBROSOLICITADO_H
#define LIBROSOLICITADO_H
#include "Libro.h"
class LibroSolicitado{
private:
    int NumPedido;
    char *CodigoLib;
    double Precio;
    bool Atendido;
public:
    LibroSolicitado();
    void SetAtendido(bool Atendido);
    bool IsAtendido() const;
    void SetPrecio(double Precio);
    double GetPrecio() const;
    void SetCodigoLib(char* CodigoLib);
    char* GetCodigoLib() const;
    void SetNumPedido(int NumPedido);
    int GetNumPedido() const;
    
    bool operator >>(Libro *L);
};

#endif /* LIBROSOLICITADO_H */


/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NPedidos.h
 * Author: Rosse
 *
 * Created on 13 de junio de 2024, 20:24
 */

#ifndef NPEDIDOS_H
#define NPEDIDOS_H
#include <fstream>
using namespace std;
#include "Vehiculo.h"
class NPedidos{
private:
    char *codigo;
    int cantidad;
    double peso;
    class NPedidos *sig;
public:
    NPedidos();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    
    void ImprimirPed(ofstream &arch);
    friend class Vehiculo;
};
#endif /* NPEDIDOS_H */

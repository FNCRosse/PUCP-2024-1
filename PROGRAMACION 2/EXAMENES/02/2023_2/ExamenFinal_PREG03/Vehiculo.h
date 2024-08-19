/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 11:48
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include "Util.h"
#include "Pedido.h"
class Vehiculo{
private:
    int dni;
    string placa;
    double carga_maxima;
    double carga_actual;
public:
    Vehiculo();
    void SetCarga_actual(double carga_actual);
    double GetCarga_actual() const;
    void SetCarga_maxima(double carga_maxima);
    double GetCarga_maxima() const;
    void SetPlaca(string placa);
    string GetPlaca() const;
    void SetDni(int dni);
    int GetDni() const;
    
    virtual void leer(ifstream &arch);
    virtual void mostrar(ofstream &arch);
    virtual void insertar(Pedido &ped);
};
#endif /* VEHICULO_H */

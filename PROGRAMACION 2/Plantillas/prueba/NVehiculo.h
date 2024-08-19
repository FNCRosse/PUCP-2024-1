/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NVehiculo.h
 * Author: Rosse
 *
 * Created on 21 de junio de 2024, 05:19
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H
#include "Util.h"
#include "Vehiculo.h"
class NVehiculo{
private:
    Vehiculo *unidad;
public:
    NVehiculo();
    virtual ~NVehiculo();
    void SetUnidad(Vehiculo* unidad);
    Vehiculo* GetUnidad() const;
    
    void lee(ifstream &arch,char);
    void imprime(ofstream &arch);
    void InsertarPedido(class NPedidos &ped);
    bool operator < (const class NVehiculo  &V)const;
    bool operator == (int cliente);
};
#endif /* NVEHICULO_H */

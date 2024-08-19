/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NVehiculo.h
 * Author: Rosse
 *
 * Created on 20 de junio de 2024, 14:57
 */

#ifndef NVEHICULO_H
#define NVEHICULO_H
#include "Vehiculo.h"
class NVehiculo{
private:
    Vehiculo * unidad;
public:
    NVehiculo();
     void leer(ifstream &arch,char tipo);
    void imprime(ofstream &arch);
};
#endif /* NVEHICULO_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: Rosse
 *
 * Created on 13 de junio de 2024, 20:49
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "LVehiculos.h"
class Flota{
private:
    class LVehiculos lista;
public:
    void CargaFlota();
    void MuestraCarga();
    void CargaPedidos();
};
#endif /* FLOTA_H */

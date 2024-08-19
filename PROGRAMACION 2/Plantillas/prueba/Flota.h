/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: Rosse
 *
 * Created on 21 de junio de 2024, 05:26
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "Util.h"
#include "NVehiculo.h"
class Flota{
private:
    vector<class NVehiculo> vflota;
public:
    Flota();
    void CargaFlota();
    void CargaPedidos();
    void MuestraCarga();
};
#endif /* FLOTA_H */

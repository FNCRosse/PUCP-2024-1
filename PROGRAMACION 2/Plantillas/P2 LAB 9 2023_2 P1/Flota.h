/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Flota.h
 * Author: Rosse
 *
 * Created on 20 de junio de 2024, 15:00
 */

#ifndef FLOTA_H
#define FLOTA_H
#include "NVehiculo.h"
#include "Util.h"
class Flota{
private:
    vector<class NVehiculo> vFlota;
public:
    void CargaFlota();
    void MuestraCarga();
};
#endif /* FLOTA_H */

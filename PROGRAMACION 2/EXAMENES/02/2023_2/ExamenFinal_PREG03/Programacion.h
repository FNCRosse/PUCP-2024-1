/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Programacion.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 12:58
 */

#ifndef PROGRAMACION_H
#define PROGRAMACION_H
#include "Util.h"
#include "Flota.h"
#include "Arbol.h"
class Programacion{
private:
    class Arbol ADespachos;
    class Flota fVehiculos;
public:
    void cargaVehiculos();
    void CargaProgramacion();
    void ReduceVehiculos(int);
    void MuestraProgramacion();
};
#endif /* PROGRAMACION_H */

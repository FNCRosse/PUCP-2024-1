/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Tesoreria.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 12:37
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Boleta.h"
#include "Escala.h"
class Tesoreria{
private:
    class Boleta lboleta[100];
    class Escala lescala[100];
public:
    void CargaEscalas();
    void CargaAlumnos();
    void ImprimirBoleta();
    void ActualizarBoleta();
};
#endif /* TESORERIA_H */

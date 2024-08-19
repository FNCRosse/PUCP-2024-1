/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   farmacia.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 16:26
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "conReceta.h"
#include "medico.h"
#include "sinReceta.h"

class farmacia{
private:
    medico lmedico[100];
    sinReceta lsinReceta[10000];
    conReceta lconReceta[10000];
public:
    farmacia();
    void CargarMedico();
    void LeeRecetas();
    void ImprimirRecetas();
    char *BuscarEspecialidad(int codmed);
};
#endif /* FARMACIA_H */

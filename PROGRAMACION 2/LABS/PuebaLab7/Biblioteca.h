/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 21:16
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "EstanteEmpresa.h"
#include "EstantePsicologia.h"
#include "LibroEducativo.h"
#include "LibroPsicologia.h"

class Biblioteca{
    EstanteEmpresa estantesCole[10];
    EstantePsicologia estantesPsico[10];
    LibroEducativo librosEdu[10];
    LibroPsicologia librosPsico[10];
    int cant_Lib_Edu;
    int cant_Lib_Psi;
    int cant_est_Cole;
    int cant_est_Psi;
public:
    Biblioteca();
    void SetCant_est_Psi(int cant_est_Psi);
    int GetCant_est_Psi() const;
    void SetCant_est_Cole(int cant_est_Cole);
    int GetCant_est_Cole() const;
    void SetCant_Lib_Psi(int cant_Lib_Psi);
    int GetCant_Lib_Psi() const;
    void SetCant_Lib_Edu(int cant_Lib_Edu);
    int GetCant_Lib_Edu() const;
    void CargarLibros();
    void CargarEstantes();
    void PosicionarLibros();
    void MostrarDatos();
};
#endif /* BIBLIOTECA_H */

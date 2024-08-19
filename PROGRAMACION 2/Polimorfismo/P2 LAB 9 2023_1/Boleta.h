/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Boleta.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 12:35
 */

#ifndef BOLETA_H
#define BOLETA_H
#include "Alumno.h"
class Boleta{
private:
    class Alumno *pboleta;
public:
    Boleta();
    virtual ~Boleta();
    void AsignarAlumno(char tipo, ifstream &arch);
    bool ExisteBoleta();
    void ImprimirDatos(ofstream &arch);
    int GetEscala();
    void ActualizarDatos(int precio);
};
#endif /* BOLETA_H */

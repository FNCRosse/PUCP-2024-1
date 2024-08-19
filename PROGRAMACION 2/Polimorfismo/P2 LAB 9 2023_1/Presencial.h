/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Presencial.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 12:29
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"

class Presencial : public Alumno {
private:
    double recargo;
    double total;
public:
    Presencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetRecargo(double recargo);
    double GetRecargo() const;
    /////////////////////////////////////////////////////
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    void actualizar(int precio);
};
#endif /* PRESENCIAL_H */

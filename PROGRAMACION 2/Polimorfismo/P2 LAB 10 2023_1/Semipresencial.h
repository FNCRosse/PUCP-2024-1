/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Semipresencial.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 21:18
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"

class Semipresencial : public Alumno {
private:
    double descuento;
    double total;
public:
    Semipresencial();
    void SetTotal(double total);
    double GetTotal() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    //otros
    void leer (ifstream &arch);
    void imprime (ofstream &arch);
    void Actualiza(double precio);
};
#endif /* SEMIPRESENCIAL_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Furgon.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 15:43
 */

#ifndef FURGON_H
#define FURGON_H
#include "Vehiculo.h"

class Furgon : public Vehiculo {
private:
    int filas;
    int puertas;
public:
    Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);


};
#endif /* FURGON_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Furgon.h
 * Author: Rosse
 *
 * Created on 13 de junio de 2024, 20:39
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
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void setPuertas(int puertas);
    int getPuertas() const;
    void setFilas(int filas);
    int getFilas() const;
};
#endif /* FURGON_H */

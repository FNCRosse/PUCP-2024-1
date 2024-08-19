/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Camion.h
 * Author: Rosse
 *
 * Created on 13 de junio de 2024, 20:35
 */

#ifndef CAMION_H
#define CAMION_H
#include "Vehiculo.h"

class Camion : public Vehiculo {
private:
    int ejes;
    int llantas;
public:
    Camion();
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void setLlantas(int llantas);
    int getLlantas() const;
    void setEjes(int ejes);
    int getEjes() const;
};
#endif /* CAMION_H */

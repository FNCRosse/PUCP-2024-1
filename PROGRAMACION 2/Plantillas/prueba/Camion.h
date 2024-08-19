/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Camion.h
 * Author: Rosse
 *
 * Created on 21 de junio de 2024, 05:05
 */

#ifndef CAMION_H
#define CAMION_H
#include "Util.h"
#include "Vehiculo.h"
#include "NPedidos.h"

class Camion : public Vehiculo {
private:
    int ejes;
    int llantas;
    map<int, class NPedidos> mdeposito;
public:
    Camion();
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;

    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void cargadeposito(NPedidos &pedido);
};
#endif /* CAMION_H */

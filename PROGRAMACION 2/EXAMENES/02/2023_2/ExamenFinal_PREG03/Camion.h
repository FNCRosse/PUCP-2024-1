/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Camion.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 11:52
 */

#ifndef CAMION_H
#define CAMION_H
#include "Util.h"
#include "Vehiculo.h"
#include "Pedido.h"

class Camion : public Vehiculo {
private:
    int ejes;
    int llantas;
    vector<class Pedido> depositos;
public:
    Camion();
    void SetDepositos(vector<Pedido> depositos);
    vector<Pedido> GetDepositos() const;
    void SetLlantas(int llantas);
    int GetLlantas() const;
    void SetEjes(int ejes);
    int GetEjes() const;

    void leer(ifstream &arch);
    void mostrar(ofstream &arch);
    void insertar(Pedido &ped);
};

#endif /* CAMION_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Furgon.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 11:55
 */

#ifndef FURGON_H
#define FURGON_H
#include "Util.h"
#include "Vehiculo.h"
#include "Pedido.h"

class Furgon : public Vehiculo {
private:
    int filas;
    int puertas;
    list<class Pedido> depositos;
public:
    Furgon();
    void setDepositos(list<Pedido> depositos);
    list<Pedido> getDepositos() const;
    void setPuertas(int puertas);
    int getPuertas() const;
    void setFilas(int filas);
    int getFilas() const;

    void leer(ifstream &arch);
    void mostrar(ofstream &arch);
    void insertar(Pedido &ped);
};
#endif /* FURGON_H */

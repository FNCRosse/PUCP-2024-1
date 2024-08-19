/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Furgon.h
 * Author: Rosse
 *
 * Created on 21 de junio de 2024, 05:16
 */

#ifndef FURGON_H
#define FURGON_H
#include "Util.h"
#include "Vehiculo.h"
#include "NPedidos.h"

class Furgon : public Vehiculo {
private:
    int filas;
    int puertas;
    list<class NPedidos> pdeposito;
public:
    Furgon();
    void SetPuertas(int puertas);
    int GetPuertas() const;
    void SetFilas(int filas);
    int GetFilas() const;

    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void cargadeposito(NPedidos &pedido);

};
#endif /* FURGON_H */

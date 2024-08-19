/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Fugon.h
 * Author: Rosse
 *
 * Created on 20 de junio de 2024, 14:54
 */

#ifndef FUGON_H
#define FUGON_H
#include "Util.h"
#include "Vehiculo.h"
#include "NPedidos.h"

class Fugon : public Vehiculo {
private:
    int Filas;
    int Puertas;
    list<class NPedidos> pdeposito;
public:
    Fugon();
    void SetPuertas(int Puertas);
    int GetPuertas() const;
    void SetFilas(int Filas);
    int GetFilas() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    void CargaDeposito(NPedidos &ped);
};
#endif /* FUGON_H */

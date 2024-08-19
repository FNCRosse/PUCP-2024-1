/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 15:36
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include <fstream>
using namespace std;
#include "NPedido.h"
class Vehiculo{
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    NPedido *ped;
public:
    Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* placa);
    void GetPlaca(char * ) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    ////////////////////////////////////////////////////////
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    void Push(class NPedido &nodoPed);
    bool PilaVacia();
    void ImprimirPila(ofstream &arch);
    
};
#endif /* VEHICULO_H */

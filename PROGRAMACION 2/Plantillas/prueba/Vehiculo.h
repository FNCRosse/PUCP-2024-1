/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Rosse
 *
 * Created on 21 de junio de 2024, 04:58
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include "NPedidos.h"
class Vehiculo{
private:
    int cliente;
    char *placa;
    double maxCarga;
    double ActCarga;
public:
    Vehiculo();
    virtual ~Vehiculo();
    void SetActCarga(double ActCarga);
    double GetActCarga() const;
    void SetMaxCarga(double maxCarga);
    double GetMaxCarga() const;
    void SetPlaca(const char* placa);
    void GetPlaca(char *) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual void cargadeposito(NPedidos &pedido)=0;
};
#endif /* VEHICULO_H */

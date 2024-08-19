/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Rosse
 *
 * Created on 13 de junio de 2024, 20:30
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include "NPedidos.h"
class Vehiculo{
private:
    int cliente;
    char * placa;
    double maxcarga;
    double actcarga;
    class NPedidos *ped;
public:
    Vehiculo();
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
    
    
    void setActcarga(double actcarga);
    double getActcarga() const;
    void setMaxcarga(double maxcarga);
    double getMaxcarga() const;
    void setPlaca(const char* placa);
    void getPlaca(char *) const;
    void setCliente(int cliente);
    int getCliente() const;
};
#endif /* VEHICULO_H */

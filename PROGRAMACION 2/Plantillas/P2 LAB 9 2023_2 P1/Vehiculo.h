/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Rosse
 *
 * Created on 20 de junio de 2024, 14:35
 */

#ifndef VEHICULO_H
#define VEHICULO_H

class Vehiculo{
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
public:
    Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* placa);
    void GetPlaca(char *cad) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    
    virtual void leer(ifstream &arch);
    virtual void imprime(ofstream &arch);
};
#endif /* VEHICULO_H */

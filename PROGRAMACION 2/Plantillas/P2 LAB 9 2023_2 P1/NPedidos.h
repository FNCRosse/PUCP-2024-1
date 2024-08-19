/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NPedidos.h
 * Author: Rosse
 *
 * Created on 20 de junio de 2024, 14:24
 */

#ifndef NPEDIDOS_H
#define NPEDIDOS_H

class NPedidos{
private:
    char * Codigo;
    int cantidad;
    double peso;
public:
    NPedidos();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* Codigo);
    void GetCodigo(char *cad) const;
    
    virtual void lee(ifstream &arch);
    virtual void imprime(ofstream &arch);
};
#endif /* NPEDIDOS_H */

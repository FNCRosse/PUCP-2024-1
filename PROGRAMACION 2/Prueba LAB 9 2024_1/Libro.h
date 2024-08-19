/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Rosse
 *
 * Created on 9 de julio de 2024, 05:32
 */

#ifndef LIBRO_H
#define LIBRO_H
#include "Util.h"
class Libro{
private:
    string nombre;
    int pagina;
    double peso;
public:
    Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPagina(int pagina);
    int GetPagina() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    
    virtual void Leer(ifstream &arch);
    virtual void imprime(ofstream &arch);
};
#endif /* LIBRO_H */

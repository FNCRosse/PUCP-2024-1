/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NLibro.h
 * Author: Rosse
 *
 * Created on 9 de julio de 2024, 05:46
 */

#ifndef NLIBRO_H
#define NLIBRO_H
#include "Util.h"
#include "Libro.h"
class NLibro{
private:
    class Libro *plibro;
public:
    NLibro();
    void AsignarTipo(char);
    void Leer(ifstream &arch);
    void imprime(ofstream &arch);
    double GetPeso();
    
};
#endif /* NLIBRO_H */

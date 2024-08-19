/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Rosse
 *
 * Created on 9 de julio de 2024, 05:53
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Util.h"
#include "NEstante.h"
class Arbol{
private:
    class NEstante *raiz;
    bool PuedeSerAsignadoREC(class NEstante *&raiz,double pesoLib,ofstream &arch);
    void InsertarRecursivo(class NEstante *&raiz,class NEstante *dato);
    void ImprimirRecursivo(class NEstante *&raiz,ofstream &arch);
public:
    Arbol();
    void Insertar(class NEstante *dato);
    void Imprimir(ofstream &arch);
    void inicializarArbol();
    bool PuedeSerAsignado(double pesoLib,ofstream &arch);
};
#endif /* ARBOL_H */

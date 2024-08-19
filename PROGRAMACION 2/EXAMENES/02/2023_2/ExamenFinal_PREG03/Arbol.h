/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 12:57
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Util.h"
#include "Nodo.h"
class Arbol{
private:
    class Nodo* raiz;
    void InsertarRecursivo(class Nodo*&raiz, class Vehiculo* dato);
    void ImprimirRecursivo(ofstream &arch, class Nodo *&raiz);
    void EliminarNodosRecursivo(int&,int cantidad, class Nodo *&raiz);
public:
    Arbol();
    void Insertar(class Vehiculo* dato);
    void Imprimir(ofstream &arch);
    void EliminarNodos(int cantidad);
    bool TieneHijos(class Nodo* raiz);
};
#endif /* ARBOL_H */

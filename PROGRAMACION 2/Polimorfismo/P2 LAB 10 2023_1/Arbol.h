/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 21:27
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include "Escala.h"
class Arbol{
private:
    class Nodo *raiz;
    class Escala lescala[10];
    void InsertarR(class Nodo *&raiz,Boleta &dato);
    void ImprimirEnOrdenR(ofstream &arch, class Nodo*&raiz);
    void ActualizarBoletaR(class Nodo*&raiz);
public:
    Arbol();
    void Asignar(char tipo, ifstream &arch);
    void Insertar(Boleta &dato);
    void ImprimirEnOrden(ofstream &arch);
    void LeerEscalas(ifstream &arch);
    void ActualizarBoleta();
};
#endif /* ARBOL_H */

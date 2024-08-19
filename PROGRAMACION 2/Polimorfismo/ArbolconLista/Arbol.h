/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 12:05
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
class Arbol{
private:
    class Nodo *arbol;
    void insertarR (class Nodo *&arbol, int dato);
    void MostrarEnOrdenR(class Nodo *arbol);
    void elimina (class Nodo *arbol);
    int buscarR(class Nodo *arbol, int dato);
public:
    Arbol();
    virtual ~Arbol();
    void Crear (const char* namefile);
    void Insertar(int);
    void MostrarEnOrden();
    int buscar (int);
};
#endif /* ARBOL_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 21:25
 */

#ifndef NODO_H
#define NODO_H
#include "Boleta.h"
#include "Arbol.h"
class Nodo{
private:
    class Boleta dboleta;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    void LeerDatos(ifstream &arch);
    void MostrarDatos(ofstream &arch);
    void ActualizaPrecio(class Escala *lescala);
    friend class Arbol;
};
#endif /* NODO_H */

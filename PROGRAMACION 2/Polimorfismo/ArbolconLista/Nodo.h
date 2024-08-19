/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 12:03
 */

#ifndef NODO_H
#define NODO_H
class Nodo{
private:
    int dato;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    friend class Arbol; 
};
#endif /* NODO_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 09:57
 */

#ifndef NODO_H
#define NODO_H
#include "Lista.h"
#include "Persona.h"
class Nodo{
private: 
    class Persona dato;
    class Nodo * sig;
public:
    Nodo();
    friend class Lista;
};
#endif /* NODO_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Rosse
 *
 * Created on 9 de julio de 2024, 06:06
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Util.h"
#include "Arbol.h"
class Biblioteca{
private:
    class Arbol AEstante;
public:
    void Carga();
    void Muestra();
    void Prueba(double pesoLib);
};
#endif /* BIBLIOTECA_H */

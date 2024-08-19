/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 10:14
 */

#ifndef LISTA_H
#define LISTA_H
#include <fstream>
using namespace std;
#include "Nodo.h"

class Lista{
private:
    class Nodo *lista;
    void imprimeRecursivo(ofstream &arch,class Nodo *p);
public:
    Lista();
    virtual ~Lista();
    void Crear(const char* filename);
    void Insetar(const class Persona &dato);
    void Imprimir(const char *filename);
    void elimina();
    void ImrprimirR(const char *filename);
};
#endif /* LISTA_H */

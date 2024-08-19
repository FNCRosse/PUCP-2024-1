/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   LibroEducativo.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 21:06
 */

#ifndef LIBROEDUCATIVO_H
#define LIBROEDUCATIVO_H

#include "Libro.h"

class LibroEducativo:public Libro{
    private:
        char *Materia;
    public:
        LibroEducativo();
        void SetMateria(const char* Materia);
        void  GetMateria(char *cad) const;
        
        void Leer(ifstream &arch);
        void Imprimir(ofstream &arch);
};
#endif /* LIBROEDUCATIVO_H */

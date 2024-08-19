/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Novela.h
 * Author: Rosse
 *
 * Created on 9 de julio de 2024, 05:41
 */

#ifndef NOVELA_H
#define NOVELA_H
#include "Util.h"
#include "Libro.h"

class Novela : public Libro {
private:
    string autor;
public:
    Novela();
    void SetAutor(string autor);
    string GetAutor() const;
    
    void Leer(ifstream &arch);
    void imprime(ofstream &arch);
};
#endif /* NOVELA_H */

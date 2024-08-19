/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Enciclopedia.h
 * Author: Rosse
 *
 * Created on 9 de julio de 2024, 05:37
 */

#ifndef ENCICLOPEDIA_H
#define ENCICLOPEDIA_H
#include "Util.h"
#include "Libro.h"

class Enciclopedia : public Libro {
private:
    int sku;
    int anho;
public:
    Enciclopedia();
    void SetAnho(int anho);
    int GetAnho() const;
    void SetSku(int sku);
    int GetSku() const;
    
    void Leer(ifstream &arch);
    void imprime(ofstream &arch);
};
#endif /* ENCICLOPEDIA_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   C.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 08:49
 */

#ifndef C_H
#define C_H
#include <fstream>
using namespace std;
#include "Ficha.h"

class C: public Ficha{
public:
    void imprime(ofstream &);
    void mover(char, int);
};
#endif /* C_H */
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   B.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 08:49
 */

#ifndef B_H
#define B_H
#include <fstream>
using namespace std;
#include "Ficha.h"

class B: public Ficha{
public:
    void imprime(ofstream &);
    void mover(char, int);
};
#endif /* B_H */

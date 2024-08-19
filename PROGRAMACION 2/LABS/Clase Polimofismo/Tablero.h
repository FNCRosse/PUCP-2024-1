/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Tablero.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 09:09
 */

#ifndef TABLERO_H
#define TABLERO_H
#include <fstream>
using namespace std;
#include "Ficha.h"
class Tablero{
private:
    class Ficha *ficha[100];
    int numFichas;
public:
    Tablero();
    virtual ~Tablero();
    void leerFichas(ifstream&);
    void ColocarFicha(char*,char ,int, int);
    void leerMovimiento(ifstream &);
    void MoverFicha(char *, char, int);
    void imprimirDatos(ofstream &);
};
#endif /* TABLERO_H */

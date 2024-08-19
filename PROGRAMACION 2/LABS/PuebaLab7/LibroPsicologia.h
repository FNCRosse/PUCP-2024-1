/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   LibroPsicologia.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 21:10
 */

#ifndef LIBROPSICOLOGIA_H
#define LIBROPSICOLOGIA_H
#include "Libro.h"
class LibroPsicologia:public Libro{
    private:
        int Ranking;
    public:
        LibroPsicologia();
        void SetRanking(int Ranking);
        int GetRanking() const;
        
        void Leer(ifstream &arch);
        void Imprimir(ofstream &arch);
};
#endif /* LIBROPSICOLOGIA_H */

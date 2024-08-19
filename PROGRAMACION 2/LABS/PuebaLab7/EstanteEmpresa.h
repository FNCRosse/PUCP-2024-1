/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   EstanteEmpresa.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 21:12
 */

#ifndef ESTANTEEMPRESA_H
#define ESTANTEEMPRESA_H

#include "Estante.h"
#include "LibroEducativo.h"
class EstanteEmpresa:public Estante{
    private:
        int RUC;
        LibroEducativo librosEdu[10];
        int cantLib;
    public:
        EstanteEmpresa();
        void SetRUC(int RUC);
        int GetRUC() const;
        
        void Leer(ifstream &arch);
        void Imprimir(ofstream &arch);
        bool AgregarLibro(LibroEducativo &L);
        int GetSobrante();
};
#endif /* ESTANTEEMPRESA_H */

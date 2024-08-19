/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   EstantePsicologia.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 21:13
 */

#ifndef ESTANTEPSICOLOGIA_H
#define ESTANTEPSICOLOGIA_H

#include "Estante.h"
#include "LibroPsicologia.h"

class EstantePsicologia:public Estante{
    private:
        int codPsicologo;
        LibroPsicologia librosPsico[10];
        int cantLib;
    public:
        EstantePsicologia();
        void SetCodPsicologo(int codPsicologo);
        int GetCodPsicologo() const;
        
        void Leer(ifstream &arch);
        void Imprimir(ofstream &arch);
        bool AgregarLibro(LibroPsicologia &L);
        int GetSobrante();
};
#endif /* ESTANTEPSICOLOGIA_H */

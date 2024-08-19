/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   conReceta.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 16:20
 */

#ifndef CONRECETA_H
#define CONRECETA_H

#include "medicamento.h"

class conReceta: public medicamento{
    private:
        int codmed;
        char* especialidad;
    public:
        conReceta();
        void SetEspecialidad(const char* especialidad);
        void GetEspecialidad(char* cad) const;
        void SetCodmed(int codmed);
        int GetCodmed() const;
        
        void IngresarDatos(int fecha, int codmed,int codmedicina,int cant,char *);
        void Imprimir(ofstream &arch);
};
#endif /* CONRECETA_H */

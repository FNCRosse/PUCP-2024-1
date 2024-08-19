/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   sinReceta.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 16:23
 */

#ifndef SINRECETA_H
#define SINRECETA_H

#include "medicamento.h"

class sinReceta:public medicamento{
    private:
        int dni;
        char* nombre;
    public:
        sinReceta();
        void SetNombre(const char* nombre);
        void GetNombre(char *cad) const;
        void SetDni(int dni);
        int GetDni() const;
        
        void IngresarDatos(int fecha, int dni,int codmedicina,int cant,char *name);
        void Imprimir(ofstream &arch);
};
#endif /* SINRECETA_H */

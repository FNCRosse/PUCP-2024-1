/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Nota.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 16:52
 */

#ifndef NOTA_H
#define NOTA_H
#include "Util.h"
class Nota{
private:
    int ciclo;
    string codigo_curso;
    double credito;
    int calificacion;
    int vez;
public:
    Nota();
    void SetVez(int vez);
    int GetVez() const;
    void SetCalificacion(int calificacion);
    int GetCalificacion() const;
    void SetCredito(double credito);
    double GetCredito() const;
    void SetCodigo_curso(string codigo_curso);
    string GetCodigo_curso() const;
    void SetCiclo(int ciclo);
    int GetCiclo() const;
    
    void imprimir(ofstream &arch);
    bool operator < (const class Nota &other)const;
};
void operator >> (ifstream &arch, class Nota &n);
#endif /* NOTA_H */

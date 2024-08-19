/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 16:55
 */

#ifndef ALUMNO_H
#define ALUMNO_H
#include "Util.h"
class Alumno{
private:
    int codigo_alumno;
    string nombre;
    double promedio;
public:
    Alumno();
    void SetPromedio(double promedio);
    double GetPromedio() const;
    void SetNombre(string nombre);
    string GetNombre() const;
    void SetCodigo_alumno(int codigo_alumno);
    int GetCodigo_alumno() const;
    
    void ImprimeAlumno(ofstream &arch);
};
bool operator >> (ifstream &arch, class Alumno &al);
#endif /* ALUMNO_H */

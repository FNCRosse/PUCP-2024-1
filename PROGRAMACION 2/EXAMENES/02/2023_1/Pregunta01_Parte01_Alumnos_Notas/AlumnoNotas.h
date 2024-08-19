/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   AlumnoNotas.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 16:56
 */

#ifndef ALUMNONOTAS_H
#define ALUMNONOTAS_H
#include "Util.h"
#include "Nota.h"
#include "Alumno.h"
class AlumnoNotas{
private:
    Alumno alumno;
    vector<class Nota> notas;
public:
    AlumnoNotas();
    void SetNotas(ifstream &arch,int ciclo);
    vector<Nota> GetNotas() const;
    void SetAlumno(Alumno alumno);
    Alumno GetAlumno() const;
    int GetCodigo();
    
    void Imprimir(ofstream &arch);
};
#endif /* ALUMNONOTAS_H */

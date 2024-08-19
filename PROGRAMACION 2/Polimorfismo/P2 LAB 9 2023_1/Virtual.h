/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Virtual.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 12:32
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"

class Virtual : public Alumno {
private:
    char *licencia;
    double total;
public:
    Virtual();
    void SetTotal(double total);
    double GetTotal() const;
    void SetLicencia(const char* licencia);
    void GetLicencia(char *cad) const;
     /////////////////////////////////////////////////////
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    void actualizar(int precio);

};
#endif /* VIRTUAL_H */

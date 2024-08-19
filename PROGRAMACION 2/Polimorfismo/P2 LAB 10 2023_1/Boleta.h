/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Boleta.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 21:23
 */

#ifndef BOLETA_H
#define BOLETA_H
#include "Alumno.h"
class Boleta{
private:
    class Alumno *pboleta;
public:
    void AsignarMemoria(char tipo);
    void LeerDatos(ifstream &arch);
    void MostrarDatos(ofstream &arch);
    int getCodigo();
    void ActualizaPrecio(class Escala *lescala);
};
#endif /* BOLETA_H */

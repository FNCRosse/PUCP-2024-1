/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Libro.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 20:43
 */

#ifndef LIBRO_H
#define LIBRO_H
#include <fstream>
using namespace std;
class Libro{
private:
    char * codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *cad) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *cad) const;
    
    void LeerDatos(ifstream &arch);
    void Imprimir(ofstream &arch);
};
#endif /* LIBRO_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Alumno.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 12:23
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno{
private:
    int codigo;
    char * Nombre;
    int escala;
    double creditos;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* Nombre);
    void GetNombre(char *) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    ////////////////////////////////////////////////7
    virtual void leer(ifstream &arch);
    virtual void imprimir(ofstream &arch);
    virtual void actualizar(int precio);
};
#endif /* ALUMNO_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Estante.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 20:51
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include "Espacio.h"
#include "Libro.h"
class Estante{
private:
    char *codigo;
    int anchura;
    int altura;
    Espacio *espacio;
public:
    Estante();
    void SetEspacio();
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char* cad) const;
    
    void LeerDatos(ifstream &arch);
    void Imprimir(ofstream &arch);
    void ImprimirFilas(ofstream &arch,int);
    void ImprimirEspacios(ofstream &arch);
    bool SePuedeAgregarLibro(Libro &L,int);
    int ObtenerSobrante(int sumaAnchLib);
    
};
#endif /* ESTANTE_H */

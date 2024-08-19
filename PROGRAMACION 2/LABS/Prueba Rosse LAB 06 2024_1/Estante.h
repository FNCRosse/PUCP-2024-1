/* 
 * File:   Estante.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 10:05
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include "Libro.h"
#include "Espacio.h"
class Estante{
private:
    char *Codigo;
    int anchura;
    int altura;
    Libro libros[10];
    Espacio *espacios;
    int cantidad_libros;
public:
    Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* Codigo);
    void GetCodigo(char *&cad) const;
    void SetEspacios();
    
    void LeerDatos(ifstream &arch);
    void imprimirFilaEstante (int pos,ofstream &arch);
    void ImprimirEspacios (ofstream &arch);
    void ImprimirLibros (ofstream &arch);
    void Imprimir (ofstream &arch);
    int getSobrartes();
    bool operator += (Libro &L);
};

void operator >> (ifstream &,Estante &E);
void operator << (ofstream &,Estante E);
#endif /* ESTANTE_H */


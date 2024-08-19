/* 
 * File:   Biblioteca.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 12:55
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Estante.h"
#include "Espacio.h"
#include "Libro.h"

class Biblioteca{
private:
    Estante estantes[10];
    int cantidad_estantes;
    Libro libros[10];
    int cantidad_libros;
public:
    Biblioteca();
    void CargaLibros();
    void CargaEstantes();
    void PosicionarLibros();
    void MostrarDatos();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetCantidad_estantes(int cantidad_estantes);
    int GetCantidad_estantes() const;
    
    void imprimirLinea(char letra, int cant, ofstream &arch);
};


#endif /* BIBLIOTECA_H */


/* 
 * File:   Tesoreria.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 20:04
 */

#ifndef TESORERIA_H
#define TESORERIA_H
#include "Presencial.h"
#include "SemiPresencial.h"
#include "Virtual.h"
#include "Escala.h"

class Tesoreria{
private:
    class Presencial lpresencial[100];
    class SemiPresencial lsemipresencial[100];
    class Virtual lvirtual[100];
    class Escala lescala[10];
public:
    void CargarEscalas(const char* filename);
    void CargarAlumnos(const char*filename);
    void Actualiza(double);
    void Imprime(const char*filename);
};


#endif /* TESORERIA_H */


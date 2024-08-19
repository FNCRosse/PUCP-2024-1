/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Persona.h
 * Author: Rosse
 *
 * Created on 20 de junio de 2024, 11:04
 */

#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;
class Persona {
private:
    int dni;
    char*nombre;
    double sueldo;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void operator = (const class Persona&);
    bool operator > (const class Persona&);
};
void operator >> (istream &, class Persona&);
ostream& operator<<(ostream &, const class Persona&);
#endif /* PERSONA_H */

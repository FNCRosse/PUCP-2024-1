/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Persona.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 09:43
 */

#ifndef PERSONA_H
#define PERSONA_H
class Persona{
private:
    int dni;
    char *Nombre;
    double sueldo;
public:
    Persona();
    virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(const char* Nombre);
    void GetNombre(char *cad) const;
    void SetDni(int dni);
    int GetDni() const;
    
    bool operator >(const class Persona &);
    void  operator = (const class Persona &);
};
ifstream &operator >>(ifstream &arch, class Persona &p);
ofstream &operator <<(ofstream &arch, class Persona &p);
#endif /* PERSONA_H */

/* 
 * File:   Rectangulo.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 10:49
 */

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <cmath>

class Rectangulo{
    private:
        //Aqui iria como lo que esta dentro de la clase, como el struct
        char *Nombre;
        double base;
        double altura;
public:
    Rectangulo();//constructor
    Rectangulo(double,double,char*);//constructor con elementos
    Rectangulo(const Rectangulo &org);
    virtual ~Rectangulo();
    void SetAltura(double Altura);
    double GetAltura()const;
    void SetBase(double Base);
    double GetBase()const;
    double area();
    void SetNombre(const char* nombre);
    void GetNombre(char*)const;
};

#endif /* RECTANGULO_H */


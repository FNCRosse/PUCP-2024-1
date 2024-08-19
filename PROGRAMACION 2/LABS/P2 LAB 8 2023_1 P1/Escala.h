/* 
 * File:   Escala.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:53
 */

#ifndef ESCALA_H
#define ESCALA_H

class Escala{
private:
    int codigo;
    double precio;
public:
    Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};


#endif /* ESCALA_H */


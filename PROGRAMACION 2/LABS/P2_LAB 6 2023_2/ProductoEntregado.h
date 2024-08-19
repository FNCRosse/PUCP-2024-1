/* 
 * File:   ProductoEntregado.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 21:13
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado{
private:
    char *Codigo;
    double Precio;
public:
    ProductoEntregado();
    void SetPrecio(double Precio);
    double GetPrecio() const;
    void SetCodigo(char* Codigo);
    char* GetCodigo() const;
};

#endif /* PRODUCTOENTREGADO_H */


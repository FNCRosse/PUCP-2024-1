/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Escala.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 21:14
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

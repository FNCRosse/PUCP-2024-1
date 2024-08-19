/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   medicamento.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 16:15
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
class medicamento{
private:
    int codigo;
    char* nombreMed;
    int cantidad;
    double precio;
    int fecha;
public:
    medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombreMed(const char* nombre);
    void GetNombreMed(char* cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void LeerDatos(int codmediciona);
};
#endif /* MEDICAMENTO_H */

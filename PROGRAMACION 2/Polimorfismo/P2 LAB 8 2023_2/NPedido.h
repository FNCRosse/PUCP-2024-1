/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NPedido.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 15:32
 */

#ifndef NPEDIDO_H
#define NPEDIDO_H
class NPedido{
private:
    char * codigo;
    int cantidad;
    double peso;
    class NPedido * sig;
public:
    NPedido();
    NPedido(const NPedido &orig);
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *) const;
    void imprimirPed(ofstream &arch);
    friend class Vehiculo;
};
#endif /* NPEDIDO_H */

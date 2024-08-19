/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NPedidos.h
 * Author: Rosse
 *
 * Created on 21 de junio de 2024, 04:52
 */

#ifndef NPEDIDOS_H
#define NPEDIDOS_H
class NPedidos{
private:
    char * codigo;
    int cantidad;
    double peso;
public:
    NPedidos();
    virtual ~NPedidos();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo( char* codigo);
   char* GetCodigo() const;
    
   void lee(ifstream &arch);
   void imprime(ofstream &arch);
};
#endif /* NPEDIDOS_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 15:28
 */

#ifndef PEDIDO_H
#define PEDIDO_H

class Pedido{
private:
    char *codigo;
    int dni_cliente;
    double subtotal;
    int fecha;
    char *Estado;
    double total;
public:
    Pedido();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEstado(const char* Estado);
    void GetEstado(char *cad) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetSubtotal(double subtotal);
    double GetSubtotal() const;
    void SetDni_cliente(int dni_cliente);
    int GetDni_cliente() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *cad) const;
    
    void LeerDato(ifstream &arch);
    void Imprimir(ofstream &arch);
};
#endif /* PEDIDO_H */

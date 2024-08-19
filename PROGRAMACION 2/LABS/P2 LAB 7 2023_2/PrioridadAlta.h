/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PrioridadAlta.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 15:37
 */

#ifndef PRIORIDADALTA_H
#define PRIORIDADALTA_H
#include "Pedido.h"
class PrioridadAlta: public Pedido{
    private:
        double recargo;
        double total;
    public:
        PrioridadAlta();
        void SetTotal(double total);
        double GetTotal() const;
        void SetRecargo(double recargo);
        double GetRecargo() const;
};
#endif /* PRIORIDADALTA_H */

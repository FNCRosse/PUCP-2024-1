/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PrioridadBaja.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 15:43
 */

#ifndef PRIORIDADBAJA_H
#define PRIORIDADBAJA_H

#include "Pedido.h"

class PrioridadBaja : public Pedido{
    private:
        int dias_espera;
        int nueva_fecha_entrega;
    public:
        PrioridadBaja();
        void SetNueva_fecha_entrega(int nueva_fecha_entrega);
        int GetNueva_fecha_entrega() const;
        void SetDias_espera(int dias_espera);
        int GetDias_espera() const;
};
#endif /* PRIORIDADBAJA_H */

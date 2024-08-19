/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   PrioridadMedia.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 15:40
 */

#ifndef PRIORIDADMEDIA_H
#define PRIORIDADMEDIA_H

#include "Pedido.h"

class PrioridadMedia:public Pedido{
    private:
        char *descripcion;
        int nueva_fecha_entrega;
    public:
        PrioridadMedia();
        void SetNueva_fecha_entrega(int nueva_fecha_entrega);
        int GetNueva_fecha_entrega() const;
        void SetDescripcion(const char* descripcion);
        void GetDescripcion(char *cad) const;
};
#endif /* PRIORIDADMEDIA_H */

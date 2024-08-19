/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Juego.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 09:23
 */

#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"
class Juego{
private:
    class Tablero tablero;
public:
    void CargarYMoverFichas(const char*, const char*,const char*);
};
#endif /* JUEGO_H */

// -*- C++ -*-

/* 
 * File:   NodoVertice.h
 * Author: ANA RONCAL
 *
 * Created on 20 de junio de 2024, 12:51
 */

#ifndef NODOVERTICE_H
#define NODOVERTICE_H

#include "Arista.h"
struct NodoVertice{
    char elemento;    //ACÄ puede cambiar el elemento
    struct Arista listaArista;
    struct NodoVertice * siguiente;
};

#endif /* NODOVERTICE_H */
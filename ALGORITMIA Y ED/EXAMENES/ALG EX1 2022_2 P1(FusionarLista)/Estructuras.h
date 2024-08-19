/* 
 * File:   Estructuras.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 19:39
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Pedido{
    int hora;
    int sucursal;
};

struct Nodo{
    struct Pedido elem;
    struct Nodo * sig;
};

struct Lista{
    struct Nodo* Cabeza;
    struct Nodo* cola;
    int longitud;
};

#endif /* ESTRUCTURAS_H */


/* 
 * File:   Pila.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 14:34
 */

#ifndef PILA_H
#define PILA_H

struct Nodo{
    int elem;
    struct Nodo* sig;
};

struct Lista{
    struct Nodo * Cabeza;
    int Longitud;
};

struct Pila{
    struct Lista lista;
};
#endif /* PILA_H */


/* 
 * File:   Cola.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 15:19
 */

#ifndef COLA_H
#define COLA_H

struct Cliente{
    int prioridad;
    char dni[3];
};
struct Nodo{
    struct Cliente cliente;
    struct Nodo * sig;
};

struct Lista{
    struct Nodo* cabeza;
    struct Nodo* colaVip;
    struct Nodo* colaNor;
    int Longitud;
};

struct Cola{
    struct Lista lista;
};

#endif /* COLA_H */


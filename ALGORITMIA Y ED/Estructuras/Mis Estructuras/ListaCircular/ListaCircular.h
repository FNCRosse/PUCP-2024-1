/* 
 * File:   ListaCircular.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 12:50
 */

#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

struct Nodo{
    int Elem;
    struct Nodo* Sig;
};
struct ListaC{
    struct Nodo *Cabeza;
    int longitud;
};


#endif /* LISTACIRCULAR_H */


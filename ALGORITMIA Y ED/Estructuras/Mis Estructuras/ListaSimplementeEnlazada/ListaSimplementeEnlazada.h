/* 
 * File:   ListaSimplementeEnlazada.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 19 de abril de 2024, 10:43
 */

#ifndef LISTASIMPLEMENTEENLAZADA_H
#define LISTASIMPLEMENTEENLAZADA_H

//Mi elemento es un struct 
struct Personaje{
    int id;
    char *Nombre;
    int poder;
};
//El nodo
struct Nodo{
    Personaje elem;
    struct Nodo *sig;
};
//La lista simplementeEnlazada
struct Lista{
    struct Nodo *Cabeza;
    int longitud;
};

#endif /* LISTASIMPLEMENTEENLAZADA_H */


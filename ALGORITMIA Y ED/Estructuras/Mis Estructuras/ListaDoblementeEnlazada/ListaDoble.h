/* 
 * File:   ListaDoble.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de abril de 2024, 14:23
 */

#ifndef LISTADOBLE_H
#define LISTADOBLE_H

struct Equipo{
    char * nombre; /*Nombre del equipo*/
    int victorias; /*cantidad de victorias*/
};

//Estructura del nodo
struct Nodo{
    struct Equipo equipo;
    struct Nodo *Ant;
    struct Nodo *Sig;
};

//Estructura de la lista doble
struct ListaD{
    struct Nodo * Cabeza;
    struct Nodo * Cola;
    int Longitud;
};


#endif /* LISTADOBLE_H */


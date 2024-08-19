/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 3 de septiembre de 2023, 01:28 AM
 */

#ifndef NODO_H
#define NODO_H

struct Producto{
    int calidad;
    int peso;
};
struct Nodo{
    struct Producto elemento;
    struct Nodo * siguiente;
};

#endif /* NODO_H */


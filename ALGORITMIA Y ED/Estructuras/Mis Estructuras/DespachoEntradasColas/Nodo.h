/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:31 PM
 */

#ifndef NODO_H
#define NODO_H
#include "Cliente.h"
struct Nodo{
    struct Cliente cliente;
    struct Nodo * siguiente;
};

#endif /* NODO_H */


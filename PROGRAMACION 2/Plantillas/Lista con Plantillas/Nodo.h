/* 
 * File:   Nodo.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de junio de 2024, 11:10
 */

#ifndef NODO_H
#define NODO_H

#include "Lista.h"
template <typename T>class Lista;

template <typename T>
class Nodo{
    private:
        T dato;
        class Nodo<T> *sig;
        public:
            Nodo();
            friend class Lista<T>;
};

template <typename T>
Nodo<T>::Nodo(){
    sig = nullptr;
}

#endif /* NODO_H */


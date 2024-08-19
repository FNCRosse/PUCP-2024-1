/* 
 * File:   Plantilla.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de junio de 2024, 10:53
 */

#ifndef PLANTILLA_H
#define PLANTILLA_H
#include <iostream>
using namespace std;

template <typename T>
class Plantilla {
private:
    T dato;
public:
    void SetDato(T dato) ;
    T GetDato() const;
    void Leer();
    void imprimir();
};
template <typename T>
void Plantilla<T>::SetDato(T dato) {
    this->dato = dato;
}
template <typename T>
T Plantilla<T>::GetDato() const {
    return dato;
}
template <typename T>
void Plantilla<T>::Leer(){
    cin>>dato;
}
template <typename T>
void Plantilla<T>::imprimir(){
    cout<<dato;
    cout<<endl;
}

#endif /* PLANTILLA_H */


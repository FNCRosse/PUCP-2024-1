/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de marzo de 2024, 07:26
 */

#include <iostream>
using namespace std;

void porValor(int *x){//el *p pasa como copia al parametro int *x
    *x=87;//le asignas el valor atravez *x modificando la DM apuntada por p
    x=new int; // creas un nuevo obj  en memoria, ahora x apunta a ese
    *x = 1010;// asignas al nuevo obj en memoria
}
void porReferencia(int *&x){// no es una copia, se trabaja directamente con el puntero original
    *x=87;//le asignas el valor atravez *x modificando la DM apuntada por p
    x=new int;// creas un nuevo obj  en memoria, ahora x apunta a ese y como *x y *p son los mismo *p ahora apunta al nuevo DM
    *x = 1010;// le asiganas a la nueva DM
}
int main(int argc, char** argv) {
    int *p;
    p = new int ;
    *p = 33;
    cout<<"P*= "<<*p<<endl;
    cout<<"P= "<<p<<endl;
    
    porValor(p);
    /*se destruye en puntero local x, pero esto no afecta al puntero original p y
      p sigue apuntando a la dirección de memoria donde se encuentra el valor 87, no al valor original 33*/
    cout<<"P*= "<<*p<<endl;
    cout<<"P= "<<p<<endl;
    
    porReferencia(p);
    /*Se actualiza el p y ahora apunta el nuevo DM creado*/
    cout<<"P*= "<<*p<<endl;
    cout<<"P= "<<p<<endl;
    /*Por valor se trabaja con una copia local del puntero, sin afectar al original
      Por refencia se trabaja directamente con el puntero original, permitiendo cambios fuera de la funcion*/
    return 0;
}


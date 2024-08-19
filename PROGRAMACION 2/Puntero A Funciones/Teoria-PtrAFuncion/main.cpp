/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de abril de 2024, 17:39
 */

#include <iostream>
using namespace std;
//Las funciones que voy a llamar con punteros
int suma (int a,int b){
    return a+b;
}
int resta (int a,int b){
    return a-b;
}
int multiplica (int a,int b){
    return a*b;
}
int divide (int a,int b){
    return a/b;
}

int main(int argc, char** argv) {
    //Los numero que vamos a usar y z como el resultado
    int x=15,y=4,z;
    //Aqui voy a declarar el puntero para las funciones
    int (*ptr) (int,int);
    //Aqui le asigno el ptr a la funcion y lo uso
    ptr = suma;
    z = ptr(x,y);
    cout <<"Z = "<<z<<endl;
    ptr = resta;
    z = ptr(x,y);
    cout <<"Z = "<<z<<endl;
    ptr = multiplica;
    z = ptr(x,y);
    cout <<"Z = "<<z<<endl;
    ptr = divide;
    z = ptr(x,y);
    cout <<"Z = "<<z<<endl<<endl;
    
    //Tambien se puede hacer un arreglo de ptr a funciones
    int (*arrPtr[4])(int, int) {suma,resta,multiplica,divide};
    //arr[0] = suma; arr[1] = resta; arr[2] = multiplica; arr[3] = diveide;
    z = arrPtr[0] (x,y);
    cout<<"Arr[0] z = "<<z<<endl;
    z = arrPtr[1] (x,y);
    cout<<"Arr[0] z = "<<z<<endl;
    z = arrPtr[2] (x,y);
    cout<<"Arr[0] z = "<<z<<endl;
    z = arrPtr[3] (x,y);
    cout<<"Arr[0] z = "<<z<<endl;
    return 0;
}


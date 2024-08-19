/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 22 de marzo de 2024, 09:15
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Punto2D.h"
// Aqui seteo el valor de la funcion
void imprimeFecha(int = 1, int =1, int=2000 );

//Definir la plantilla
// si es una clase cambiar typename por class
template<typename T>
T maximo(T a, T b){
    T mayor =a;
    if(b > mayor) mayor =b;
    return mayor;
}
template<typename T>
T maximo(T a, T b, T c){
    T mayor =a;
    if(b > mayor) mayor =b;
     if(c > mayor) mayor =c;
    return mayor;
}
template<typename T>
T maximo(T* arr,int n){
    T mayor =arr[0];
    for(int i=0;i<n;++i){
        if(arr[i] > mayor) mayor = arr[i];
    }
    return mayor;
}
template<typename T>
bool leerDatos(T* &arr,int &n, const char* filename){
    ifstream file (filename);
    if(! file.is_open()) {
        cout <<"El archivo no existe"<<endl;
        return false;
    }
    // inicializar los campos a rellenar
    arr = new T[100];
    n=0;
    while(true){
        file >> arr[n];
        if( file.eof()) break;
        ++n;
    }
    file.close();
    return true;
}
template<typename T>
void MostrarDatos(T* arr,const int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}


int main(int argc, char** argv) {
    //TEMPLATES
    //Buena practica -> indicar tipo de dato
    cout<<"Templates"<<endl;
    cout<<maximo<float>(8.8,8.1)<<endl;
    int *arr = nullptr;
    arr = new int[4] {12,5,20,15};
    cout<<maximo<int>(arr,4)<<endl;
    
    //SOBRECARGA DE FUNCIONES
    int dd=19, mm=3, aa=2024;
    imprimeFecha(dd,aa);
    imprimeFecha(dd,mm);
    imprimeFecha(dd);
    imprimeFecha();
    
    //SOBRECARGA DE OPERADORES
    Punto2D p1{5,3};
    Punto2D p2{2,1};
    cout<<endl<<"SobreCargar de operadores"<<endl;
    cout<<"Punto 1: "<<p1<<endl;
    cout<<"Punto 2: "<<p2<<endl;
    Punto2D p3 = p1 +p2;
    cout<<"Suma(+)"<<endl<<"Punto 3: "<<p3<<endl;
    
    cout<<"Mayor (>)"<<endl;
    if(p1 > p2)  cout<<"P1 es mayor"<<endl;
    else cout<<"P2 es mayor"<<endl;
    
    p3 += p2;
    cout<<"Suma Simplificada(+=)"<<endl<<"Punto 3: "<<p3<<endl;
    
    ++p3;
    cout<<"PreIncremento(++obj)"<<endl<<"Punto 3: "<<p3<<endl;
      p3++;
    cout<<"PostIncremento(obj++)"<<endl<<"Punto 3: "<<p3<<endl;
    --p3;
    cout<<"PreDisminucion(--obj)"<<endl<<"Punto 3: "<<p3<<endl;
      p3--;
    cout<<"PostDisminucion(obj--)"<<endl<<"Punto 3: "<<p3<<endl;
    
    //LEER DATOS 
    Punto2D* arreglo = nullptr ;
    int n=0;
    leerDatos<Punto2D>(arreglo,n,"Datos.txt");
    MostrarDatos<Punto2D>(arreglo,n);
    
    return 0;
}

void imprimeFecha(int dd, int mm, int aa ){
    cout<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<endl;
}
    
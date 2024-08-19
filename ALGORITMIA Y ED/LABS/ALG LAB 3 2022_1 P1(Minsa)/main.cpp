/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 9 de mayo de 2024, 12:33
 */

#include <iostream>
using namespace std;
#define N 10
int CalcularIncrementosCentro(int *Cifras,int inicio,int med,int fin){
    int contIzq=1,contDer=1;
    if(Cifras[med] < Cifras[med+1]){
        for(int i=med;i >=inicio;i--){
            if(Cifras[i-1] < Cifras[i]) contIzq++;
            else break;
        }
        for(int i=med+1;i<=fin;i++){
            if(Cifras[i] < Cifras[i+1]) contDer++;
            else break;
        }
        return contDer + contIzq;
    } else {
        return 1; // Se refiere aque solo cuenta el Cifra[med] sin ningun incremento
    }
}
int CalcularIntervaloMax(int *Cifras,int inicio,int fin){
    //Caso base 
    //Este caso se da por que si hay un unico elemento en el arreglo
    //Entonces solo habra 1 solo incremento, de 0 a el unico elemento del arreglo
    if(inicio == fin) return 1;
    //Caso Recursivo
    int med = (inicio+fin)/2;
    
    int incrementoIzq = CalcularIntervaloMax(Cifras,inicio,med);
    int incrementoDer = CalcularIntervaloMax(Cifras,med+1,fin);
    int incrementoCentro = CalcularIncrementosCentro(Cifras,inicio,med,fin);
    
    if(incrementoIzq >= incrementoDer && incrementoIzq >= incrementoCentro){
        return incrementoIzq;
    } else if (incrementoDer >= incrementoCentro && incrementoDer >= incrementoIzq){
        return incrementoDer;
    } else {
        return incrementoCentro;
    }
}
int main(int argc, char** argv) {
    int num = 10;
    int Cifras[N] = {7,2,9,10,16,10,13,8,2,10};
    int intervaloMax = CalcularIntervaloMax(Cifras,0,num-1);
    double Indice = (double) intervaloMax/num;
    
    cout<<"Para el caso de "<<num<<" dias tendra un intervalo maximo de incrementos de "
            <<intervaloMax<<", con indice de "<<Indice<<endl;
    return 0;
}


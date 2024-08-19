/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 10 de mayo de 2024, 10:43
 */

#include <iostream>
using namespace std;
int CalcularPesoMenor(int *evaluaciones,int inicio,int fin){
    //Caso base 
    if(inicio>=fin) return evaluaciones[inicio];
    int med = (inicio+fin)/2;
    
    int MenorIzq = CalcularPesoMenor(evaluaciones,inicio,med);
    int MenorDer = CalcularPesoMenor(evaluaciones,med+1,fin);
    
    if(MenorIzq < MenorDer) return MenorIzq;
    else return MenorDer;
}
int CalcularIntervalos(int *evaluaciones,int MenorPeso,int inicio,int med,int fin){
    int a = evaluaciones[med] ;
    if(evaluaciones[med] == MenorPeso){
        int Izq = 1, Der = 1;
        for(int i=med-1; i>= inicio;i--){
            int b = evaluaciones[i] ;
            if(evaluaciones[i] == MenorPeso) Izq++;
            else break;
        }
        for(int i=med+1; i<= fin;i++){
            int c = evaluaciones[i] ;
            if(evaluaciones[i] == MenorPeso) Der++;
            else break;
        }
        return Izq + Der - 1;
    } else {
        return 1;
    }
}
int CalcularRangoDiasPesoMenor(int *evaluaciones,int MenorPeso,int*DiasConsecutivos,int inicio,int fin){
    //Caso base
    if(inicio == fin ){
        if(evaluaciones[inicio] == MenorPeso) DiasConsecutivos[inicio] = inicio+1;
        return 1;
    }
    int med =(inicio +fin )/2;
    
    int RangoIzq = CalcularRangoDiasPesoMenor(evaluaciones,MenorPeso,DiasConsecutivos,inicio,med);
    int RangoDer = CalcularRangoDiasPesoMenor(evaluaciones,MenorPeso,DiasConsecutivos,med+1,fin);
    int intervalos = CalcularIntervalos(evaluaciones,MenorPeso,inicio,med,fin);
    
    if(RangoIzq>= RangoDer && RangoIzq >= intervalos){
        return RangoIzq;
    } else if (RangoDer >= RangoIzq && RangoDer >= intervalos){
        return RangoDer;
    } else {
        return intervalos;
    }
}
int main(int argc, char** argv) {
    int dias = 30;
    int evaluaciones[dias] = {98,95,92,89,91,92,89,89,92,93,94,92,91,90,88,88,88,89,90,91,88,88,90,90,92,89,90,
                                            88,90,91};
    int DiasConsecutivos[dias]{};
    int MenorPeso = CalcularPesoMenor(evaluaciones,0,dias-1);
    int CantDias = CalcularRangoDiasPesoMenor(evaluaciones,MenorPeso,DiasConsecutivos,0,dias-1);
    //Solo para escribir el rango de dias
    int RangoDias[CantDias]{}, k=0;
    for (int i=0;i<dias;i++){
        if(DiasConsecutivos[i] != 0 && k<= CantDias) {
            RangoDias[k] = DiasConsecutivos[i];
            k++;
        }
    }
    
    cout<<"El menor peso fue de "<<MenorPeso;
    cout<<" El rango de dias es de "<<CantDias<<" desde el dia "<<RangoDias[0]<<" hasta el dia "
            <<RangoDias[CantDias-1];
    
    return 0;
}


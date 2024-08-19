/* 
 * File:   funciones.cpp
 * Author: ANA RONCAL
 * Created on 2 de mayo de 2024, 12:37 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "funciones.h"
//int arreglo[] = {0, 0, 0, 0, 0, 1, 1, 1};
int cuentaCeros(int * arr, int ini, int fin, int cont) {

    if(ini > fin) return cont;
    int med = (ini + fin) / 2;
    
    if(arr[med] == 0)
        return cuentaCeros(arr, med + 1, fin, med + 1);
    else
        return cuentaCeros(arr, ini, med - 1, cont);
}

//int arreglo[] = {0, 0, 0, 0, 0, 1, 1, 1};
int cuentaUnos(int * arr, int ini, int fin, int cont) {
    
    if(ini > fin) return cont;
    int med = (ini + fin) / 2;
    
    if(arr[med] == 0)
        return cuentaUnos(arr, med + 1, fin, cont);
    else
        return cuentaUnos(arr, ini, med - 1, cont + fin - med + 1);
}

//int arreglo2[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
void buscaSolo(int *arr, int ini, int fin) {

    if (ini > fin) return;
    if(ini == fin){
        cout<<"BUSCA SOLO: "<<arr[ini]<<endl;
        return;
    }
    int med = (ini + fin) / 2;
    
    if(med % 2 == 0){
        if(arr[med] == arr[med + 1])
            buscaSolo(arr, med + 2, fin);
        else
            buscaSolo(arr, ini, med);
    }else{
        if(arr[med] == arr[med - 1])
            buscaSolo(arr, med + 1, fin);
        else
            buscaSolo(arr, ini, med - 1);
    }

}

// int arreglo3[] = {12, 24, 15, 12, 11, 10};
int buscaMax(int *arr, int ini, int fin) {
    
    int med = (ini + fin) / 2;
    if(ini >= fin) return arr[ini];
    
    if(arr[med] > arr[med + 1])
       return buscaMax(arr, ini, med);
    else
       return buscaMax(arr, med + 1, fin);
    
}
/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 9 de mayo de 2024, 14:24
 */

#include <iostream>
using namespace std;
#define MAXN 5
#define MAXM 6
void PasarMatriz_Arreglos(int matriz [MAXN][MAXM],int *Arr,int n,int m){
    int indice=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            Arr[indice] = matriz[i][k];
            indice++;
        }
    }
}
void PasarArreglo_Matriz(int *Arr,int matriz [MAXN][MAXM],int n,int m){
    int indice=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            matriz[i][k] = Arr[indice];
            indice++;
        }
    }
}

void merge (int *Arr_Reg,int *Arr_Lineas,int inicio,int medio,int fin){
    int i,p,q;
    int long1 = (medio+1) - inicio;
    int long2 = fin - medio;
    int P1[long1+1],P2[long1+1];
    int Q1[long2+1],Q2[long2+1];
    P1[long1]=999999,Q1[long1] = 9999999;
    for(i = inicio;i<medio+1;i++){
        P1[i-inicio] = Arr_Reg[i];
        P2[i-inicio] = Arr_Lineas[i];
    }
    for(i = medio+1;i<=fin;i++){
        Q1[i-(medio+1)] = Arr_Reg[i];
        Q2[i-(medio+1)] = Arr_Lineas[i];
    }
    p=q=0;
    for(i=inicio;i<=fin;i++){
        if(P1[p]<Q1[q]){
            Arr_Reg[i]=P1[p];
            Arr_Lineas[i]=P2[p];
            p++;
        } else {
            Arr_Reg[i]=Q1[q];
            Arr_Lineas[i]=Q2[q];
            q++;
        }
    }
}
void mergeSort(int *Arr_Reg,int *Arr_Lineas,int inicio,int fin){
    if(inicio == fin) return;
    int medio = (inicio+fin)/2;
    mergeSort(Arr_Reg,Arr_Lineas,inicio,medio);
    mergeSort(Arr_Reg,Arr_Lineas,medio+1,fin);
    merge(Arr_Reg,Arr_Lineas,inicio,medio,fin);
}
int CalcularCantidad(int ID[MAXN][MAXM],int Instrucciones[MAXN][MAXM],int registro,int inicioFila,int FinFila,
        int inicioCol,int finCol){
    //Caso base
    if( inicioCol == finCol && inicioFila==FinFila){//Si solo queda un 1x1
        if(registro == ID[inicioFila][inicioCol]){// Verificamos si en esa unica posicion coincide con el registro buscado
            return Instrucciones[inicioFila][inicioCol];
        } else {
            return 0; // si es que no coincide, no agregamos nada (0)
        }
    }
    //Caso Recursivo
    int medFila = (inicioFila+FinFila)/2;
    int medCol = (inicioCol+finCol)/2;
    //Casos:
    int Izq1=0,Der1=0,izq2=0,Der2=0;
    int cuad1=0,cuad2=0,cuad3=0,cuad4=0;
    //1° que las filas coinicidan en un punto
    if(inicioFila == FinFila){
        int Izq1 = CalcularCantidad(ID,Instrucciones,registro,inicioFila,FinFila,inicioCol,medCol);
        int Der1 = CalcularCantidad(ID,Instrucciones,registro,inicioFila,FinFila,medCol+1,finCol);
        return Izq1 + Der1;
    }
    //2° que las columnas coinicidan en un punto
    if(inicioCol == finCol){
        int Izq2 = CalcularCantidad(ID,Instrucciones,registro,inicioFila,medFila,inicioCol,finCol);
        int Der2 = CalcularCantidad(ID,Instrucciones,registro,medFila+1,FinFila,inicioCol,finCol);
        return Izq2+Der2;
    }
    //3° los otros casos
    //Lo vemos como cuadrantes, y hay que ver en que cuadrante esta ese registro
    //    1        2
    /* 0000 | 0000
     * 0000 | 0000
     * ---------------
     * 0000 | 0000
     * 0000 | 0000
     *   3        4
     */
    // El cuadrante 1
    if(registro>=ID[inicioFila][inicioCol] && registro<= ID[medFila][medCol]){
        cuad1 = CalcularCantidad(ID,Instrucciones,registro,inicioFila,medFila,inicioCol,medCol);
    }
    // El cuadrante 2
    if(registro>=ID[inicioFila][medCol+1] && registro<= ID[medFila][finCol]){
        cuad2 = CalcularCantidad(ID,Instrucciones,registro,inicioFila,medFila,medCol+1,finCol);
    }
    // El cuadrante 3
    if(registro>=ID[medFila+1][inicioCol] && registro<= ID[FinFila][medCol]){
        cuad3 = CalcularCantidad(ID,Instrucciones,registro,medFila+1,FinFila,inicioCol,medCol);
    }
    // El cuadrante 4
    if(registro>=ID[medFila+1][medCol+1] && registro<= ID[FinFila][finCol]){
        cuad4 = CalcularCantidad(ID,Instrucciones,registro,medFila+1,FinFila,medCol+1,finCol);
    }
    //retornar la suma de todos los cuadrantes
    return cuad1+cuad2+cuad3+cuad4;
}
int main(int argc, char** argv) {
    int n = 5, m =6; 
    int matriz_Registro[MAXN][MAXM] = {
        {-1,-2,-3,-4,-5,-6},
        {-7,-8,1,-9,2,-10},
        {-11,1,2,-12,-13,-14},
        {-15,-16,-17,1,-18,-19},
        {-20,1,2,-21,-22,-23},
    };
    int matriz_lineas_instruccion[MAXN][MAXM]={
        {10,5,8,9,8,1},  
        {10,5,2,8,2,3},  
        {4,2,1,4,8,1},  
        {1,2,4,3,5,3},  
        {8,3,3,8,5,3},  
    };
    // Pasar las matrices a arreglos para poder ordenarlas por si registro
    int Arr_Reg[n*m], Arr_Lineas[n*m];
    PasarMatriz_Arreglos(matriz_Registro,Arr_Reg,n,m);
    PasarMatriz_Arreglos(matriz_lineas_instruccion,Arr_Lineas,n,m);
    mergeSort(Arr_Reg,Arr_Lineas,0,n*m-1);
    PasarArreglo_Matriz(Arr_Reg,matriz_Registro,n,m);
    PasarArreglo_Matriz(Arr_Lineas,matriz_lineas_instruccion,n,m);
    
    //Ingresar el registro de virus a buscar y llamar la funcion para q me traiga cuantas lineas hay con ese virus
    int registro = 1;
    int cantLineas = CalcularCantidad(matriz_Registro,matriz_lineas_instruccion,registro,0,n-1, 0,m-1);
    cout<<"Registro: "<<registro<<endl;
    cout<<"Cantidad Lineas: "<<cantLineas<<endl;
    if(cantLineas>= 10){
        cout<<"Se considera que el archivo cuenta con codigo malicioso"<<endl;
    } else{
        cout<<"El archivo NO cuenta con codigo malicioso"<<endl;
    }
    return 0;
}


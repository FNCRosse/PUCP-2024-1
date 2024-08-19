/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: El Mismisimo
 *
 * Created on 28 de noviembre de 2023, 05:42 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

int numComb(int n);

int main(int argc, char** argv) {
    int n = 10;
    
    cout << numComb(n) << endl;
    return 0;
}

int numComb(int n){
    
    //tabla de resultados
    int F[n+1];
    //F[i]: numero de combinaciones dadas 'i' columnas
    
    //arreglo auxiliar: numero de combinaciones con inicio alterno
    // (o sea que inicien con la columna C/A o A/C)
    int numAlt[n+1];
    //numAlt[i]: numero de alternos iniciales en las combinaciones
    // dadas por 'i' columnas
    
    
    //inicialización
    F[0] = 0; //0 columnas -> 0 combinaciones
    F[1] = 3; // 1 columna -> (visualmente) 3 combinaciones
    
    numAlt[0] = 0; //0 combinaciones -> 0 alternos
    numAlt[1] = 1; //3 combinaciones -> (visualmente) 1 alterno
    // -> es decir, tomando solo uno de ellos, solo hay un C/A
    // el real numero de alternos sería 1 x 2 = 2, pero mantener
    // el conteo de uno solo nos ayudara en el calculo posterior
    
    //llenado de tabla
    for(int i=2;i<=n;i++){
        //Visualmente, una combinación de 'i' columnas, es una
        //combinación de las combinaciones de 1 columna con
        //las combinaciones de (i-1) columnas (considerar ese orden)
        
        // Esto significa que si F[i] representa el numero de
        // combinaciones de 'i' columnas, entonces ...
        // F[i] = F[1]*F[i-1]
        // => cada combinacion de F[1] (o sea c/u de las 
        //    3 combinaciones iniciales) aparecerán F[i-1]
        //    veces para formar las combinaciones de F[i]
        
        //Sin embargo, existe la sgte limitante:
        //-> Las combinaciones iniciales alternas (o sea C/A y A/C)
        //   no pueden combinarse con las combinaciones de F[i]
        //   que tengan como columna inicial la misma columna alterna
        // -> es decir
        //  C     C A
        //  A     A C
        //  no podrían combinarse (de nuevo, en ese orden) por tener
        //  la misma columna alterna C/A
        
        //¿cómo detectamos esas combinaciones no deseadas?
        // considerando solo un (1) caso alterno de las combinaciones
        // iniciales (ejm: solo considerando C/A), el numero
        // de combinaciones no deseadas para F[i] es igual
        // al numero de combinaciones F[i-1] que tengan
        // como columna inicial la alterna. Esto sucede porque
        // por ejm: la comb. inicial C/A se podrá combinar
        // con cualquier combinación de F[i-1], salvo con las que
        // tengan columna inicial C/A, por lo que el numero
        // combinaciones totales F[i] se verá reducida en
        // ese número de combinaciones no consideradas
        
        //entonces, ¿cómo determinamos el numero de combinaciones
        // con 'i-1' columnas que tienen alternos iniciales?
        // -> visualmente, se puede verificar que el numero de
        //    alternos de 'i' columnas, depende de cuantas comb.
        //    se pudieron formar con 'i-1' columnas y cuantos
        //   alternos tienen esas comb. de 'i-1' columnas
        //   Esto sucede porque:
        //   inicialmente el numero de alternos, de un tipo,
        //   debería ser F[i-1], pues cada alterno lo estamos
        //   combinando F[i-1] veces, pero se quita el numero
        //   de alternos existentes en F[i-1], pues
        //   estos no entraran en la combinación que forma F[i]
        //  debido a la limitante ya explicada
        
        // Así: numAlt[i] = F[i-1] - numAlt[i-1]
        
        //pero, esto es el numero de alternos de 1 solo tipo
        // (es decir, por ejm, solo alternos C/A)
        
        //Por lo que para quitar todas las combinaciones no deseadas
        // debemos quitar lo mismo multiplicado por 2
        // (para considerar los alternos C/A y A/C)
        
        //Finalmente
        //Así: F[i] = F[1]*F[i-1] - 2*numAlt[i-1] 
        
        //Version alterna que lei por ahí (tmb funciona :o )
        // F[i] = F[i-1] + 2*(F[i-1] - ((F[i-1] - F[i-2])/2));
        
        
        F[i] = (F[1]*F[i-1]) - (2*numAlt[i-1]);
        numAlt[i] = F[i-1] - numAlt[i-1];
    }
    
    //impresion
    cout<<"Alternos (de un solo tipo)"<<endl;
    for(int i=0;i<=n;i++){
        cout<<setw(6)<<numAlt[i];
    }
    cout<<endl;
    
    cout<<"Combinaciones"<<endl;
    for(int i=0;i<=n;i++){
        cout<<setw(6)<<F[i];
    }
    cout<<endl;
    
    return F[n];
}

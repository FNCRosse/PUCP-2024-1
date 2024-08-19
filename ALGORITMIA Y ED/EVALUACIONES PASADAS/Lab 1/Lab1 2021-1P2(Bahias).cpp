/* 
 * Project: Lab_1_2019-1
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 26 de marzo de 2023, 15:34
 */

#include <iostream>
#include<cmath>
using namespace std;
#define MAX_BAHIAS 3
#define MAX_N 10

void CargarCromo(int num,int *ArrBinario, int &cantUnos ){
     int i =0, resto;
     cantUnos =0;
// Convertirlo a binario 
    while(num>0){
        resto = num %2;
        num = num/2;
        ArrBinario[i] = resto;
        if (ArrBinario[i] == 1 ) cantUnos++;
        i++;
    }
}

int main(){
	// ingresar datos
	int N,M,C,filas,col;
	cout<<"Ingrese el numero de productos por bahia"<<endl;
	cin>>N;
	cout<<"Ingrese el numero de diviciones del camion"<<endl;
	cin>>M;
	cout<<"Ingrese el numero maximo de toneladas"<<endl;
	cin>>C;
	//arreglo donde se va guardar los pesos
	int ArrPesos[MAX_BAHIAS][N];
	int ArrMatriz[MAX_BAHIAS][N];
	int soluciones[MAX_BAHIAS][N],SumaMax=0;
	// llenar esos arrglos
	cout<<"Ingrese el peso de los productos de cada bahia"<<endl;
	for(filas=0;filas<MAX_BAHIAS;filas++){
		cout<<"Bahia "<<filas+1<<": ";
		for(col=0;col<N;col++){
			cin>>ArrPesos[filas][col];
		}
	}
	
	cout<<"Se va imprimir la lista de soluciones"<<endl;
	int cantUnos;
	int Opciones = (int)pow(2,MAX_BAHIAS*N);
	for(int i=0;i<Opciones;i++){
		//crear el arreglo a binario
		int ArrBinario [MAX_BAHIAS*N] = {0};//para inicializarlo todo en 0
		CargarCromo(i,ArrBinario,cantUnos);
		// solo contar las soluciones si tiene los M productos
		if(cantUnos == M){
			// crear el matriz binario y sumar los pesos
			int i=0,sumaParcial=0;
			for(filas=0;filas<MAX_BAHIAS;filas++){
				for(col=0;col<N;col++){
					ArrMatriz[filas][col] = ArrBinario[i];
					sumaParcial = ArrMatriz[filas][col]*ArrPesos[filas][col] + sumaParcial;
					i++;
				}
			}
			
			if(sumaParcial==C){
				cout<<endl;
				for(filas=0;filas<MAX_BAHIAS;filas++){
					cout<<"Bahia "<<filas+1<<":";
					for(col=0;col<N;col++){
						soluciones[filas][col] = ArrMatriz[filas][col];
						if(ArrMatriz[filas][col] == 1) cout<<ArrPesos[filas][col]<<" ";
					}
					cout<<endl;
				}
				
			}
		}
	}
	
	cout<<endl<<"La ultima solucion es:"<<endl;
	// imprimir la ultima solucion
	for(filas=0 ; filas<3 ; filas++){
		cout<<"Bahia "<<filas+1<<":";
		for(col=0 ; col<N ; col++){
			if(soluciones[filas][col]==1){
				cout<<ArrPesos[filas][col]<<" ";							
			}						
		}
		cout<<"  ";		
	}
	
	return 0;
}

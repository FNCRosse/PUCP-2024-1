#include <iostream>
using namespace std;
//MERGE SORT
void merge(int *Arreglo,int inicio, int med, int fin){
	int i,p,q; //Indices para los siguientes arreglos
	// i = indice para el arreglo
	// p = indice para arreglo izquierda
	// q = indice para arreglo derecha
	
	int long1,long2;
	long1 = (med+1) - inicio; //longitud de arreglo izquierda
	long2 = fin - med; //longitud de arreglo derecha
	
	//Creamos 2 arreglos para reordenar el arreglo
	int P[long1+1],Q[long2+1];
	P[long1] = 99999999, Q[long2]=99999999;
	
	//Le damos los valores a los arreglos creados respectivos
	for(i=inicio;i<med+1;i++) P[i-inicio] = Arreglo[i];
	for(i=med+1;i<=fin;i++) Q[i-(med+1)] = Arreglo[i];
	 p=q=0;
	//una iterativa para ordenar
	for(i=inicio;i<=fin;i++){
		if(P[p]<Q[q]) {// Si el elemento de P[] es el menor, entonces lo inserto
			Arreglo[i] = P[p++];
		} else {
			Arreglo[i] = Q[q++];
		}
	}
}
void mergeSort(int *Arreglo,int inicio, int fin){
	//Caso base 
	//Por que ya tenemos un solo elemento y este ya ordenado por ser uno
	if(inicio == fin) return;
	//tenemos la posicion del medio
	int med = (inicio + fin)/2;
	
	mergeSort(Arreglo,inicio,med);//la mitad del arreglo de la izquierda
	mergeSort(Arreglo,med+1,fin);//la mitad del arreglo de la derecha
	merge(Arreglo,inicio,med,fin);
}

int main(){
	int Arreglo[9] = {11,2,8,4,10,6,5,1,0};
	int longitud = 8;
	cout<<"Arreglo Normal: ";
	for(int i=0;i<8;i++) cout<<Arreglo[i]<<" ";
	
	//Opcion 1 mergeSort
	mergeSort(Arreglo,0,longitud-1);
	
	cout<<endl<<"Arreglo Ordenado: ";
	for(int i=0;i<8;i++) cout<<Arreglo[i]<<" ";
	
}

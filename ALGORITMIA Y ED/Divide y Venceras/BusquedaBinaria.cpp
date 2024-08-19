#include <iostream>
using namespace std;
//Busqueda Binaria
//Para usarlo el arreglo debe estar ordenado
int BusquedaBinaria(int *Arreglo, int Busca,int inicio, int fin){
	//Caso Base
	if(inicio>fin) return -1;//Cuando inicio se sobrepasa el fin
	int centro = (inicio+fin)/2;
	if(Arreglo[centro] == Busca){
		return centro;
	} else {
		if(Arreglo[centro] < Busca) {
			return BusquedaBinaria(Arreglo,Busca,centro+1, fin);
		} else {
			return BusquedaBinaria(Arreglo,Busca,inicio,centro-1);
		}
	}
}
int main(){
	int Valore[7]={1,5,7,9,12,15,17};
	int n=7;
	int NumBuscar = 15;//Numero a buscar
	cout<<"Arreglo Normal: ";
	for(int i=0;i<n;i++) cout<<Valore[i]<<" ";
	cout<<endl<<"Buscar: "<<NumBuscar<<endl;
	int indice = BusquedaBinaria(Valore,NumBuscar,0,n-1);
	if(indice == -1){
		cout<<"No se encontro el elemento"<<endl;
	} else{
		cout<<"Se encuentra en la posicion "<<indice+1<<endl;
	}
	
}

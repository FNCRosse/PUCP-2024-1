#include <iostream>
using namespace std;
int CuentaUnos(int *Arreglo,int inicio,int fin,int contador){
	//Caso Base
	if(inicio > fin) return contador; //Si inicio sobrepasa el fin
	int med = (inicio+fin)/2;
	
	if (Arreglo[med]==1){
		return CuentaUnos(Arreglo,med+1,fin,contador+1);
	} else {
		return CuentaUnos(Arreglo,med+1,fin,contador);
	}
}
int CuentaCeros(int *Arreglo,int inicio,int fin,int contador){
	//Caso Base
	if(inicio>fin) return contador;
	int med = (inicio+fin)/2;
	
	if(Arreglo[med] == 0){
		return CuentaCeros(Arreglo,med+1,fin,med+1);
	} else {
		return CuentaCeros(Arreglo,inicio,med-1,contador);
	}
}
void BuscarNumSolo(int *Arreglo,int inicio,int fin){
	//Caso Base
	if(inicio>fin) return;
	if(inicio == fin) {
		cout<<"BUSCA SOLO: "<<Arreglo[inicio]<<endl;
		return;
	}
	int med = (inicio+fin)/2;
	if(med %2 == 0){//Si es par
		if(Arreglo[med] == Arreglo[med+1]){
			BuscarNumSolo(Arreglo,med+2,fin);
		} else {
			BuscarNumSolo(Arreglo,inicio,med);
		}
	} else { //Si es par
		if(Arreglo[med] == Arreglo[med-1]){
			BuscarNumSolo(Arreglo,med+1,fin);
		} else {
			BuscarNumSolo(Arreglo,inicio,med-1);
		}
	}
}
int BuscarNumMax(int *Arreglo3,int inicio,int fin){
	//Caso base
	if(inicio>=fin) return Arreglo3[inicio];
	//Caso recursivo
	int med = (inicio+fin)/2;
	if(Arreglo3[med] > Arreglo3[med+1]){
		return BuscarNumMax(Arreglo3,inicio,med);
	}else{
		return BuscarNumMax(Arreglo3,med+1,fin);
	}
}
int main(){
	int Arreglo[8]={0,0,0,0,0,1,1,1};
	int n=8;
	cout<<"Arreglo 1: ";
	for(int i=0;i<n;i++) cout<<Arreglo[i]<<" ";
	
	///////////////////// Contador ///////////////////////////////////////////////
	int CantUno=CuentaUnos(Arreglo,0,n-1,0);//(Arreglo,inicio,fin,contador);
	cout<<endl<<"CUENTA UNOS: "<<CantUno<<endl;
	int CantCeros=CuentaCeros(Arreglo,0,n-1,0);//(Arreglo,inicio,fin,contador);
	cout<<"CUENTA CEROS: "<<CantCeros<<endl;
	
	///////////////////// Busca Solo ///////////////////////////////////////////////
	int Arreglo2[11]={1,1,3,3,4,5,5,7,7,8,8};
	n=11;
	cout<<"Arreglo 2: ";
	for(int i=0;i<n;i++) cout<<Arreglo2[i]<<" ";
	cout<<endl;
	BuscarNumSolo(Arreglo2,0,n-1);
	
	///////////////////// Buscar Maximo ///////////////////////////////////////////////
	int Arreglo3[6]={12,24,15,12,11,10};
	n=6;
	cout<<"Arreglo 3: ";
	for(int i=0;i<n;i++) cout<<Arreglo3[i]<<" ";
	cout<<endl;
	cout<<"NUM MAXIMO: "<<BuscarNumMax(Arreglo3,0,n-1)<<endl;
	return 0;
}

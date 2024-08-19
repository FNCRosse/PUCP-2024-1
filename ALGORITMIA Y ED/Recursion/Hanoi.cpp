//Torre de hanoi
//Mueve la torre de A hacia C usando la torre Aux B
//Solo puede mover un disco a la vez
//no puede ser de menor a mayor
#include <iostream>
using namespace std;

void hanoi(int numDisco,char desde,char aux, char hacia){
	//Caso base
	if(numDisco == 1){
		cout <<"Mover disco 1 desde la torre "<<desde<<" hacia la torre "<<hacia<<endl;
		return;
	}
	//Caso Recursivo
	//Quiero mover los discos restantes
	hanoi(numDisco-1,desde,hacia,aux);
	cout <<"Mover disco "<<numDisco<<" desde la torre "<<desde<<" hacia la torre "<<hacia<<endl;
	hanoi(numDisco-1,aux,desde,hacia);	
}
int main(){
	int numDisco=3;
	cout<<"Resultado de Hanoi"<<endl;
	hanoi(numDisco,'A','B','C');
	
	return 0;
}

#include <iostream>
using namespace std;
#define PROBADA 3
#define RUTA 7
bool valida(int tablero[3][5],int fil,int col){
	if(fil>=0 and fil<3 and col>=0 and col <5 && tablero[fil][col]==1){
		return true;
	}
	return false;
}
bool laberinto(int tablero[3][5],int fil,int col){
	bool terminado=false;
	if(valida(tablero,fil,col)){
		tablero[fil][col] = PROBADA;
		
		if(fil==2 and col==4){
			terminado = true;
		}
		else{
			if (not terminado)
				terminado = laberinto(tablero,fil+1,col);//Abajo
			if (not terminado)
				terminado = laberinto(tablero,fil,col+1);//derecha
			if (not terminado)
				terminado = laberinto(tablero,fil-1,col);//arriba
			if (not terminado)
				terminado = laberinto(tablero,fil,col-1);//izquierda
		}
		if(terminado){
			tablero[fil][col] = RUTA;
		}
	}
	return terminado;	
}
int main(){
	int tablero[3][5] = {{1,0,1,1,1},
						{1,1,1,0,1},
						{0,0,1,0,1}};
	bool terminado;
	terminado = laberinto(tablero,0,0);
	for(int i=0;i<3;i++){
		for(int j=0;j<5;j++){
			cout<<tablero[i][j]<<" --";
		}
		cout<<endl;
	}
	
	return 0;
}

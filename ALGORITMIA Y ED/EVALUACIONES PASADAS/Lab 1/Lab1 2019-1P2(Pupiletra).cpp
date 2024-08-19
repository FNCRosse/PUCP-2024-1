#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define N 15
using namespace std;
void PopulateGameBoard(int t,char tablero[N][N]){
	srand(time(NULL));
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			tablero[i][j]='A'+rand()%(26);
		}
	}
}
void ShowGameBoard(int t,char tablero[N][N]){
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			cout<< " "<<tablero[i][j]<<" | ";
		}
		cout<<endl;
	}
}
void SearchWord(char Word[],int t,char tablero[N][N],char Respuestas[3]){
	// por fueza bruta,es decir buscar todas las posibilidades
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			if(Word[0]==tablero[i][j]){
				/*Direcciones:
			      Derecha  (0)  j-> (+1)
				  Izquieda (1)  <-j (-1)
				  Arriba   (3)  i-> (+1)
				  Abajo    (4)  <-i (-1)
				*/
				for(int dir=0;dir<4;dir++){//buscar entre las 4 direcciones
					int dirFila = (dir==3) - (dir==2);
					int dirCol = (dir==0) - (dir==1);
					
					//posicion de la sig letra
					int i2 = i+dirFila;
					int j2 = j+dirCol;
					int k =1;// contador q empieza en word[1]
					int longword = strlen(Word);
					
					while((i2>=0 && i2<t) && (j2>=0 && j2<t)/*Condicion q no se pase del tablero*/
						   && (tablero[i2][j2] == Word[k]) /*Condicion q la sig letra coincida*/
						   && (k<longword)) /*condicion que k no se pase del tamano de la palabra a buscar*/{
						i2 += dirFila;
						j2 += dirCol;
						k++;
					}
					
					if(k==longword){// una vez k finalise el arreglo de palabra, guardar en respuesta
						Respuestas[0]= i+48;
						Respuestas[1]= j+48;
						
						if(dir==0) Respuestas[2]='R';
						if(dir==1) Respuestas[2]='L';
						if(dir==2) Respuestas[2]='U';
						if(dir==3) Respuestas[2]='D';
						return;
					}
				}
			}
		}
	}
}
int main(){
	int t,CantPalabras;
	char tablero[N][N];
	// crear el tablero del pupilera
	cout<<"Ingrese el tamano de la cuadricula:"<<endl;
	cin>>t;
	cout<<"Bienvenido al juego de sopa de letras"<<endl;
	PopulateGameBoard(t,tablero);
	ShowGameBoard(t,tablero);
	
	// ingresar las palabras buscar
	char PalabrasBuscar[CantPalabras][N];
	char Respuestas[CantPalabras][3]; /* respuesta[i][0] == coordenada x
									     respuesta[i][1] == coordenada y
									     respuesta[i][2] == Arriba/abajo/derecha/izq */
	cout<<endl<<"Ingrese la cantidad de palabras a buscar"<<endl;
	cin>>CantPalabras;
	
	for(int i=0;i<CantPalabras;i++){
		cout<<"Palabra "<<i+1<<": ";
		cin>>PalabrasBuscar[i];
		//buscar por cada palabra puesta
		SearchWord(PalabrasBuscar[i],t,tablero,Respuestas[i]);
	}
	
	// imprimir respuestas
	for(int i=0;i<CantPalabras;i++){
		cout<<"Palabra "<<i+1<<": - "<<PalabrasBuscar[i]<<" ";
		if(Respuestas[i][0] != -1){
			cout<<"encontrada en ("
				<<Respuestas[i][0]<<","
				<<Respuestas[i][1]<<") - "
				<<Respuestas[i][2]<<endl;
		}
		else{
			cout<<"no encontrada";
		}
		cout<<endl;
	}
	return 0;
}

#include <iostream>
#define N 6
#define M 6

int cuentaMinas(int tablero[N][M],int n,int m,int posX,int posY,int dirX,int dirY){
		
}

int main(){
	int tablero[N][M] = {{0,0,0,1,0,1},
						 {0,0,1,0,0,0},
						 {0,1,0,0,0,1},
						 {1,0,0,0,0,0},
						 {0,1,0,0,0,0},
						 {0,0,0,0,1,0}};
	int dirX = 0, n=6, m=6;
	int dirY = 1;
	cout << cuentaMinas(tablero,n,m,3,2,dirX,dirY);
	return 0;
}

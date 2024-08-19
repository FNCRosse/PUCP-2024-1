#include <iostream>
#define N 3
#define M 3

using namespace std;

int robot(int tablero[N][M], int n, int m, int i, int j){
	int derecha = -9999999, abajo = -9999999, total;
	if (i==n-1 && j==m-1){
		return tablero[i][j];
	}
	if (j<m-1){
		derecha = robot(tablero,n,m,i,j+1);
	}
	if (i<n-1){
		abajo = robot(tablero,n,m,i+1,j);
	}
	if (derecha<abajo){
		total = abajo + tablero[i][j];
	}
	else {
		total = derecha + tablero[i][j];
	}
	return total;
}

int main(){
	int tablero[N][M] = {{3,5,7},
						 {-2,4,-1},
						 {6,2,1}};
	int n=3, m=3;
	cout << robot(tablero,n,m,0,0);
	return 0;
}

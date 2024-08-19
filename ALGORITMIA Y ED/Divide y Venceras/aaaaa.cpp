#include<iostream>
using namespace std;

int main(){
	int matriz[4][6] = {{0,0,0,3,0,0},
						{1,0,0,3,0,0},
						{1,2,2,3,0,0},
						{1,2,2,3,0,0}};
	for(int i=0;i<4;i++){
		for(int k=0;k<6;k++){
			cout<<matriz[i][k]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	int arreglo[4*6]{},j=0;
	for(int i=0;i<4;i++){
		for(int k=0;k<6;k++){
			arreglo[j] = matriz[i][k];
			j++;
		}
	}
	for(int i=0;i<4*6;i++){
		cout<<arreglo[i]<<" ";
	}
			
}

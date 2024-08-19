#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void CargarBin(int num,int *croma){
	int i=0,resto;
	while(num>0){
		resto = num%2;
		num = num/2;
		croma[i]=resto;
		i++;
	}
}
struct Proyecto{
	int Num;
	int Costo;
	int Ganancia;
	int Prdecesores[5];	
	int CantPred;
};
int main(){
	//Ingresa de datos
	int N,P,predecesore;
	cout<<"Ingresar el numero de proyectos y Presupuesto:"<<endl;
	cin>>N>>P;
	//Colocar los datos en la estructura
	Proyecto proyectos[N];
	for(int i=0;i<N;i++){
		int k=0;
		proyectos[i].CantPred=0;
		proyectos[i].Num = i+1;
		cout<<"Proyecto "<<i+1<<": "<<endl;
		cout<<"Costo: ";
		cin>>proyectos[i].Costo;//Proyecto[i].Costo es el coste por proyecto
		cout<<"Ganancia: ";
		cin>>proyectos[i].Ganancia;//Proyecto[i].Ganancia es la ganancia por proyecto
		cout<<"Predecesores (si no hay poner 0): ";
		while(true){
			cin>>predecesore;
			if(predecesore == 0)break;
			proyectos[i].Prdecesores[k] = predecesore;//>Proyecto[i].Prdecesores[k] es la ganancia por proyecto
			k++;
			proyectos[i].CantPred++;
		}
		cout<<endl;
	}
	
	// desarrollo el problema
	int opciones = (int)pow(2,N);
	int GananciaParcial,MaxGanacia=0, CosteParcial;
	int solucion[N];
	for(int i=0;i<opciones;i++){
		// crear cromosoma
		int cromo[N]={0};
		CargarBin(i,cromo);
		GananciaParcial=0;
		CosteParcial=0;
		bool valido =true;
		for(int j=0;j<N;j++){
			if(cromo[j]!=0){
				GananciaParcial = cromo[j]*proyectos[j].Ganancia + GananciaParcial;
				CosteParcial= cromo[j]*proyectos[j].Costo + CosteParcial;
				for(int k=0;k<proyectos[j].CantPred;k++){
					int pre = proyectos[j].Prdecesores[k] -1;
					bool encontrado = false;
					for (int l=0;l<j;l++){
						if(cromo[j]!=0 && proyectos[l].Num == pre +1){
							encontrado = true;
							break;
						}
					}
					if(!encontrado){// si no ha encontrado el predecesor
						valido = false;
						break;
					}
				}
				if(!valido){// se sale del bucle y no se considera para la evaluación de la ganancia.
					break;
				}
			}
		}
		
		if(CosteParcial<=P && MaxGanacia<GananciaParcial && valido){
			MaxGanacia=GananciaParcial;
			for(int t=0;t<N;t++) solucion[t] = cromo[t];
		}
	}
	
	cout<<GananciaParcial<<endl;
	for(int i=0;i<N;i++){
		if(solucion[i] == 1) cout<<proyectos[i].Num<<" ";
	}

}

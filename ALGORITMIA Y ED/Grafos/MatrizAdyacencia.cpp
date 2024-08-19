#include <iostream>
#include <vector>

#define N 4
using namespace std;

void GenerarMatrizAdyacencia(int grafo[][N], int numero_vertices, vector<vector<int> > &mapa){
	for (int i=0; i<numero_vertices; i++){
		vector<int> arista;
		for (int j=0; j<numero_vertices; j++){
			arista.push_back(grafo[i][j]);//agregamos la arista
		}
		mapa.push_back(arista);//agregamos toda la fila (que tiene las aristas) a los v�rtices
	}
}

void GenerarListaAdyacencia(int listas[][2], int numero_aristas, vector<vector<int> > &mapaL, int numero_vertices){
	// Si las aristas (u, v) y (v, u) no son las mismas, se dice que la arista (u, v) est� dirigida desde el v�rtice u
	//Ej: Siendo los valores {u,v} que utilizaremos: {0,1}, {0,2}, {1,2}, {2,3}, {3,1}
	for (int i=0; i<numero_aristas; i++){
		int u=listas[i][0];//v�rtice origen
		int v=listas[i][1];//v�rtice destino
		mapaL[u].push_back(v);//Agregar en la lista de u (es origen y destino)
		mapaL[v].push_back(u);//Agregar en la lista de v (es destino y origen) //se retira en caso el grafo sea Digrafo/Grado dirigido
	}
}

int main (){
	int numero_vertices=N;
	
	//===================================================
	//Generaci�n de la MATRIZ DE ADYACENCIA del Grafo
	//===================================================
	int grafo[N][N]={{0,0,0,1},//representaci�n del GRAFO
					{0,0,1,0},
					{0,1,0,1},
					{1,0,1,0}};
	vector<vector<int> > mapa;//"guardar" la matriz de adyacencia
	
	GenerarMatrizAdyacencia(grafo, numero_vertices, mapa);
	
	//Mostramos la matriz de adyacencia
	cout<<"Matriz de adyacencia:"<<endl;
	for (int i=0; i<numero_vertices; i++){
		for (int j=0; j<numero_vertices; j++)
			cout<<mapa[i][j]<<" ";
		cout<<endl;
	}
	
	//===================================================
	//Generaci�n de la ESTRUCTURA DE ADYACENCIA del Grafo
	//===================================================
	int listas[][2]={{0,1},{0,2},{1,2},{2,3},{3,1}};//lista de aristas
	int numero_aristas=5; //numero de aristas del grafo
	
	vector<vector<int> > mapaL(numero_vertices);
	GenerarListaAdyacencia(listas, numero_aristas, mapaL, numero_vertices);
	
	//Mostramos las listas
	cout<<endl<<"Lista de adyacencia:"<<endl;
	for (int i=0; i<numero_vertices; i++){
		cout<<i<<": ";
		for (int j=0; j<mapaL[i].size();j++)//recorrer� dependiendo del tama�o de cada lista (size())
			cout<<mapaL[i][j]<< " ";
		cout<<endl;
	}
	return 0;
}

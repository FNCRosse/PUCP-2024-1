#include <iostream>
#include <limits.h> //para la constante máxima de enteros INT_MAX

#define V 5 //cantidad de vértices del grafo

using namespace std;

void MostrarSolucion(int distancias[]){
	for (int i=0; i<V; i++){
		cout << i << " " << distancias[i]<< endl;
	}
}

int MinimaDistancia(int distancias[], bool visitado[]){//función que encuentra el vértice con la distancia mínima que aún no ha sido visitado
	int indice_minimo, minima_distancia=INT_MAX;
	
	//recorrer todos los vértices para encontrar el de distancia mínima
	for (int i=0; i<V; i++){
		if (visitado[i]==false && distancias[i]<=minima_distancia){//CLAVE: es un nodo que aún no ha sido visitado
			minima_distancia=distancias[i];
			indice_minimo=i;
		}
	}
	return indice_minimo;	
}
void dijkstra(int grafo[V][V], int origen){
	int distancias[V];//para "guardar" las distancias mas cortas para llegar al vértice (i) desde (origen)
	bool visitados[V];//para "marcar" los vértices que ya han sido procesados.
	
	//Inicializamos los arreglos a utilizar
	for (int i=0; i<V; i++){
		distancias[i]=INT_MAX;//número grande para "guardar" los mínimos en el primer procesamiento
		visitados[i]=false;
	}
	
	//establecemos que la menor distancia hacia el (origen) es 0
	distancias[origen]=0;//no siempre el vértice origen es la posición 0.
	
	for (int vertice=0; vertice<V-1; vertice++){//vamos a procesar todos los vértices menos el origen.
		int vertice_minima_distancia=MinimaDistancia(distancias, visitados);
		//devuelva el nodo desde donde tengo la mínima distancia aún no visitado
		//comentario: en la primera iteración, será escogido el (origen) para ser procesado
		
		//voy a "marcar" el vertice_minima_distancia como visitado porque lo voy a procesar
		visitados[vertice_minima_distancia]=true;
		
		//Lo proceso: actualizar distancias[] de los vértices donde hay relación (adyacentes), es decir, hay aristas.
		for (int i=0; i<V; i++){//i recorrerá todos los vértices
			if (!visitados[i]//menos los que ya fueron visitados
			&& grafo[vertice_minima_distancia][i]//tengan una relación (i) con (vertice_minima_distancia)
			&& distancias[vertice_minima_distancia]!= INT_MAX//la relación no es infinito (es decir es el valor inicial)
			&& distancias[vertice_minima_distancia] + grafo[vertice_minima_distancia][i] < distancias[i]) //es decir, encontramos una nueva mínima distancia
			distancias[i]=distancias[vertice_minima_distancia] + grafo[vertice_minima_distancia][i];//actualizo, porque encontré una nueva distancia mínima hacia (i)
		}
	}
	MostrarSolucion(distancias); //mostramos el arreglo que tiene las distancias a todos los nodos
}

int main (){
	int grafo[V][V]={{0,3,0,7,0},//Representación del Grafo: Matriz de Adyacencia
			{3,0,4,2,0},
			{0,4,0,5,6},
			{7,2,5,0,4},
			{0,0,6,4,0}};
			
	dijkstra(grafo, 0);//el vértice inicial será (a) o la posición 0.
	
	return 0;
}

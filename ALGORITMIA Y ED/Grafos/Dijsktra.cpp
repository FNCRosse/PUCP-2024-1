#include <iostream>
#include <limits.h> //para la constante m�xima de enteros INT_MAX

#define V 5 //cantidad de v�rtices del grafo

using namespace std;

void MostrarSolucion(int distancias[]){
	for (int i=0; i<V; i++){
		cout << i << " " << distancias[i]<< endl;
	}
}

int MinimaDistancia(int distancias[], bool visitado[]){//funci�n que encuentra el v�rtice con la distancia m�nima que a�n no ha sido visitado
	int indice_minimo, minima_distancia=INT_MAX;
	
	//recorrer todos los v�rtices para encontrar el de distancia m�nima
	for (int i=0; i<V; i++){
		if (visitado[i]==false && distancias[i]<=minima_distancia){//CLAVE: es un nodo que a�n no ha sido visitado
			minima_distancia=distancias[i];
			indice_minimo=i;
		}
	}
	return indice_minimo;	
}
void dijkstra(int grafo[V][V], int origen){
	int distancias[V];//para "guardar" las distancias mas cortas para llegar al v�rtice (i) desde (origen)
	bool visitados[V];//para "marcar" los v�rtices que ya han sido procesados.
	
	//Inicializamos los arreglos a utilizar
	for (int i=0; i<V; i++){
		distancias[i]=INT_MAX;//n�mero grande para "guardar" los m�nimos en el primer procesamiento
		visitados[i]=false;
	}
	
	//establecemos que la menor distancia hacia el (origen) es 0
	distancias[origen]=0;//no siempre el v�rtice origen es la posici�n 0.
	
	for (int vertice=0; vertice<V-1; vertice++){//vamos a procesar todos los v�rtices menos el origen.
		int vertice_minima_distancia=MinimaDistancia(distancias, visitados);
		//devuelva el nodo desde donde tengo la m�nima distancia a�n no visitado
		//comentario: en la primera iteraci�n, ser� escogido el (origen) para ser procesado
		
		//voy a "marcar" el vertice_minima_distancia como visitado porque lo voy a procesar
		visitados[vertice_minima_distancia]=true;
		
		//Lo proceso: actualizar distancias[] de los v�rtices donde hay relaci�n (adyacentes), es decir, hay aristas.
		for (int i=0; i<V; i++){//i recorrer� todos los v�rtices
			if (!visitados[i]//menos los que ya fueron visitados
			&& grafo[vertice_minima_distancia][i]//tengan una relaci�n (i) con (vertice_minima_distancia)
			&& distancias[vertice_minima_distancia]!= INT_MAX//la relaci�n no es infinito (es decir es el valor inicial)
			&& distancias[vertice_minima_distancia] + grafo[vertice_minima_distancia][i] < distancias[i]) //es decir, encontramos una nueva m�nima distancia
			distancias[i]=distancias[vertice_minima_distancia] + grafo[vertice_minima_distancia][i];//actualizo, porque encontr� una nueva distancia m�nima hacia (i)
		}
	}
	MostrarSolucion(distancias); //mostramos el arreglo que tiene las distancias a todos los nodos
}

int main (){
	int grafo[V][V]={{0,3,0,7,0},//Representaci�n del Grafo: Matriz de Adyacencia
			{3,0,4,2,0},
			{0,4,0,5,6},
			{7,2,5,0,4},
			{0,0,6,4,0}};
			
	dijkstra(grafo, 0);//el v�rtice inicial ser� (a) o la posici�n 0.
	
	return 0;
}

#include <iostream>

using namespace std;

typedef int TInfo;
// ===========================
// ====== INICIO COLAS =======
// ===========================
typedef struct NodoCola{
    int elem;
    struct NodoCola* sig;
} TNodoCola;
typedef TNodoCola* TCola;


void imprimecola(TCola ptrcola)
{
    while(ptrcola!=NULL){
        cout << ptrcola->elem << " ";
        ptrcola=ptrcola->sig;
    }
    cout<<endl;
}

/*implementacion de las funciones para la cola*/
void crea_cola(TCola *ptrCola){
    *ptrCola = NULL;
}

int cola_vacia(TCola ptrCola){
    return ptrCola==NULL;
}

/*encolar, se inserta un elemento al final de la cola. Se representa como una
insercion al inicio.*/
void encolar(TCola *ptrCola, int valor){
    TNodoCola *ptrNuevo = new TNodoCola;
    ptrNuevo->elem=valor;
    ptrNuevo->sig=*ptrCola;
    *ptrCola=ptrNuevo;
}

/*saco la cabeza de la cola. Se representa como una eliminacion del nodo final de
la lista.*/
int desencolar(TCola *ptrCola)
{   TNodoCola *ptrRecorrido, *ptrUltimo;
    int valor;    
    if (!cola_vacia(*ptrCola))
    {
        ptrUltimo = NULL;
        ptrRecorrido = *ptrCola;
        while (ptrRecorrido->sig)
        {
            ptrUltimo = ptrRecorrido;
            ptrRecorrido = ptrRecorrido->sig;
        }
        if (ptrUltimo == NULL)
            *ptrCola=NULL;
        else
            ptrUltimo->sig=NULL;
           
        valor=ptrRecorrido->elem;
        delete ptrRecorrido;
        return(valor);
    }
}
// ===========================
// ======== FIN COLAS ========
// ===========================

// ===========================
// ======= INICIO PILAS ======
// ===========================


typedef struct NodoPila {
    int valor;
    struct NodoPila *ptrSig; //estructura auto-referenciada
} TNodoPila;

typedef TNodoPila* Tpila;

void crear(Tpila* ptrpila) {
    *ptrpila = NULL;
}

void push(Tpila* Pila, int valor) {
    TNodoPila* ptrNuevo;
    ptrNuevo = new TNodoPila;
    ptrNuevo->valor = valor;
    ptrNuevo->ptrSig = *Pila;
    *Pila = ptrNuevo;
}

bool pila_vacia(Tpila* ptrPila) {
    return *ptrPila == NULL;
}

void top(Tpila* ptrPila) {
    TNodoPila* ptrrec;
    ptrrec = *ptrPila;
    if (pila_vacia(ptrPila))
        cout << "Pila vacia" << endl;
    else
        cout << ptrrec->valor << endl;
}

int pop(Tpila* Pila) {
    TNodoPila* ptrEliminar;
    int valor;
    if (!pila_vacia(Pila)) {
        ptrEliminar = *Pila;
        valor = ptrEliminar->valor;
        *Pila = ptrEliminar->ptrSig;
        delete ptrEliminar;
    }
    return valor;
}

void finalizar(Tpila ptrPila) {
    TNodoPila* ptrEliminar;
    ptrEliminar = ptrPila;
    while (ptrEliminar != NULL) {
        ptrPila = ptrEliminar->ptrSig;
        delete ptrEliminar;
        ptrEliminar = ptrPila;
    }
}

void cambia(Tpila ptrPila, int n) {
    ptrPila->valor = n;
}

void imprimepila(Tpila ptrpila) {
    while (ptrpila != NULL) {
        cout << ptrpila->valor << " ";
        ptrpila = ptrpila->ptrSig;
    }
}
// ===========================
// ======== FIN PILAS ========
// ===========================

void DistribuirCola (TCola *cola, int n){
    //C4->C3->C2->C1->B4->B3->B2->B1->A4->A3->A2->A1
    //A=1, B=2, C=3
    //34->33->32->31->24->23->22->21->14->13->12->11
    Tpila paux;
    crear(&paux);
    
    int lote,i,valor;
    lote=n/3;//por el enunciado sabemos que SIEMPRE son 3 lotes (Tipo A, Tipo B, Tipo C)
    
    //Nos deshacemos de los productos de calidad Tipo C
    //Desencolamos y encolamos los lotes Tipo A y Tipo B
    for (i=0;i<2*lote;i++){
    	valor = desencolar(cola);
    	encolar (cola, valor);
	}
	cout<<"Desencolamos y encolamos Tipo A y Tipo B"<<endl;
	cout<<"Cola: ";
    imprimecola(*cola);
    cout<<endl;
    //Sólo desencolamos el lote Tipo C
  	for (i=0;i<lote;i++){
    	valor = desencolar(cola);
	}
	cout<<"Desencolamos Tipo C"<<endl;
	cout<<"Cola: ";
    imprimecola(*cola);
    cout<<endl;
    
    
    //24->23->22->21->14->13->12->11
    
    //24->14->23->13->22->12->21->11
    
    //Apilamos desde la Cola a todos los productos Tipo A (para invertirlos)
    for (i=0;i<lote;i++)
    	push(&paux,desencolar(cola));
    	
    //Encolamos desde la Pila todos los elementos (los productos Tipo A)
    for (i=0;i<lote;i++)
    	encolar(cola,pop(&paux));
    
	//Desencolamos y encolamos todos los productos Tipo B
    for (i=0;i<lote;i++)
    	encolar(cola,desencolar(cola));
    
    //Apilamos desde la Cola a todos los productos Tipo A (para invertirlos nuevamente, es decir tenelos en orden)
	for (i=0;i<lote;i++)
    	push(&paux,desencolar(cola));
	
	//Encolamos desde la Pila (1 producto Tipo A)
	//Encolamos desde la Cola (1 producto Tipo B)
	//Repetimos hasta hacer todo el lote
	while (!pila_vacia(&paux)){
		encolar(cola, pop(&paux));
		encolar(cola,desencolar(cola));
	}
}

int main(int argc, char** argv) {
    TCola ptrCola;
    int n;

    crea_cola(&ptrCola);
    //C4->C3->C2->C1->B4->B3->B2->B1->A4->A3->A2->A1
    //A=1, B=2, C=3
    //34->33->32->31->24->23->22->21->14->13->12->11
    
    
    encolar(&ptrCola, 11);
    encolar(&ptrCola, 12);
    encolar(&ptrCola, 13);
    encolar(&ptrCola, 14);
    encolar(&ptrCola, 21);
    encolar(&ptrCola, 22);
    encolar(&ptrCola, 23);
    encolar(&ptrCola, 24);
    encolar(&ptrCola, 31);
    encolar(&ptrCola, 32);
    encolar(&ptrCola, 33);
    encolar(&ptrCola, 34);
    
    cout<<"Cola: ";
    imprimecola(ptrCola);
    cout<<endl;
    DistribuirCola(&ptrCola, 12);
    cout << endl;
    cout<<"Cola: ";
    imprimecola(ptrCola);
    cout<<endl;


    return 0;
}

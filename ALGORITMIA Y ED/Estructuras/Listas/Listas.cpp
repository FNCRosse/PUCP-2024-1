#include <iostream>

using namespace std;

/*informacion que se almacenara en el nodo*/
typedef int TInfo;

/*se define el  tipo de dato TNodo que representa a una estructura autoreferenciada*/
typedef struct Nodo{
    int elem;
    struct Nodo* sig;
} TNodo;

/*se define el tipo de dato para gestionar la lista enlazada*/
typedef TNodo* TLista;



/*prototipos del TAD Lista*/
void crear_lista(TLista &ptrLista);
bool esta_vacia(TLista ptrLista);
void insertar_inicio(TLista &ptrLista, TInfo elem);
void insertar_final(TLista &ptrLista, TInfo elem);
void imprimir(TLista ptrLista);
void finalizar_lista(TLista &ptrLista);
bool esta_en_lista(TLista ptrLista, TInfo elem);
int tamano(TLista ptrLista);
void invierte_lista(TLista *ptrLista);
TLista invierte_lista_rec (TLista ptrLista);

int main() {
    TLista ptrLista, ptrLista2, ptrpar, ptrimpar;

    crear_lista(ptrLista);
    insertar_final(ptrLista, 19);
    insertar_final(ptrLista, 20);
    insertar_final(ptrLista, 16);
    insertar_final(ptrLista, 14);
    imprimir(ptrLista);
    cout << "Tamano: " << tamano(ptrLista) << endl;
    
    //invierte_lista(&ptrLista); Invierte lista iterativa
    ptrLista2=invierte_lista_rec (ptrLista);
    imprimir(ptrLista2);
    
    finalizar_lista(ptrLista);
    return 0;
}

int tamano(TLista ptrLista)
{   TLista ptrrec;
    int cont=0;

    ptrrec=ptrLista;
    while(ptrrec)
    {
        ptrrec=ptrrec->sig;
        cont++;
    }

    return cont;
}

void crear_lista(TLista &ptrLista){
    ptrLista = NULL;
}

bool esta_vacia(TLista ptrLista){
    return ptrLista==NULL;
}

void insertar_inicio(TLista &ptrLista, TInfo elem){
    TNodo *ptrNuevo;
    ptrNuevo = new TNodo;

    ptrNuevo->elem = elem;
    ptrNuevo->sig = ptrLista;
    ptrLista = ptrNuevo;
}

void insertar_final(TLista &ptrLista, TInfo elem){
    TNodo *ptrNuevo, *ptrRec, *ptrUltimo;
    ptrNuevo = new TNodo;

    ptrNuevo->elem = elem;
    ptrNuevo->sig = NULL;
    ptrRec = ptrLista;
    ptrUltimo = NULL;
    while (ptrRec){
        ptrUltimo = ptrRec;
        ptrRec = ptrRec->sig;
    }

    if (ptrUltimo)
        ptrUltimo->sig=ptrNuevo;
    else
        ptrLista = ptrNuevo;
}


void imprimir(TLista ptrLista){
    TNodo *ptrRec;
    ptrRec = ptrLista;

    while (ptrRec){
        cout << ptrRec->elem << " -> ";
        ptrRec = ptrRec->sig;
    }
    cout << "NULL" << endl;
}

void finalizar_lista(TLista &ptrLista){
    TNodo *ptrRec, *ptrLiberar;
    ptrRec = ptrLista;

    while (ptrRec){
        ptrLiberar = ptrRec;
        ptrRec = ptrRec->sig;
        delete ptrLiberar;
    }
}

bool esta_en_lista(TLista ptrLista, TInfo elem){
    TNodo *ptrRec;
    ptrRec = ptrLista;

    while (ptrRec){
        if (ptrRec->elem==elem)
            return true;
        ptrRec = ptrRec->sig;
    }
    return false;
}


void invierte_lista(TLista *ptrLista){	
	int i, j, n;
	
	TLista ptrant, ptrrec;//nuestros punteros para poder realizar la inversión de la lista
	TLista ptrini; //servirá para "guardar" al nuevo inicio de la lista invertida
	
	n=tamano(*ptrLista);//tamaño de la lista
	
	for (i=1;i<n;i++){
		ptrrec=*ptrLista;
		for (j=i;j<n;j++){
			ptrant=ptrrec;//ptrant va "persiguiendo" a ptrrec
			ptrrec=ptrrec->sig;//ptrrec se va al siguiente
		}
		if(i==1) ptrini=ptrrec;
		ptrrec->sig=ptrant;//empezamo a invertir los nodos de la lista
		ptrant->sig=NULL;
	}
	*ptrLista=ptrini;
	
}

TLista invierte_lista_rec (TLista ptrLista){
	TLista ptrini;//va a ser el ptr que "guarde" el nuevo inicio de la lista invertida.
	
	if(ptrLista==NULL) return NULL;//sea lista vacía
	if(ptrLista->sig==NULL) return ptrLista;//CASO BASE
	
	ptrini=invierte_lista_rec (ptrLista->sig);//llamada recursiva a una lista mas pequeña
	
	ptrLista->sig->sig=ptrLista;//con estas instrucciones invertimos la lista
	ptrLista->sig=NULL;//con estas instrucciones invertimos la lista
	return ptrini;//va a retornar "acumulado" el nuevo inicio de la lista invertida.
}




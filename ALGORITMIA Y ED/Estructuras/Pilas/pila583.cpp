#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodoP
{
    Elemento elem;
    struct nodoP *sig;
} NodoP;

typedef struct
{
    NodoP *cima;
    int longitud;
} Pila;

void construir( Pila *pP )
{
    // toda pila empieza vacia
    pP->cima = NULL;
    pP->longitud = 0;
}

bool esPilaVacia( Pila P )
{
    return P.cima == NULL;
    // return P.longitud == 0;
}

int obtenerLongitud( Pila P )
{
    return P.longitud;
}

NodoP* crearNodo( Elemento e, NodoP *s )
{
    NodoP *p;
    p = new NodoP;
    p->elem = e;
    p->sig = s;
    return p;  // devuelve la direccion del nodo creado
}

void apilar( Pila *pP, Elemento e )
{
    NodoP *p;
    p = crearNodo( e, pP->cima );
    pP->cima = p;
    pP->longitud++;
}

void mostrar( Pila P )
{
    NodoP *p;
    int i;
    if ( esPilaVacia(P) )
        cout << "Pila vacia" << endl << endl;
    else
    {
        p = P.cima;
        for(i=1; i<=P.longitud; i++)
        {
            cout << p->elem << endl;
            p = p->sig;
        }
        cout << endl;
    }
}

// esta funcion solo sera invocada si la pila no es vacia
Elemento desapilar( Pila *pP )
{
    Elemento x;
    NodoP *p;
    p = pP->cima;
    x = p->elem;
    pP->cima = p->sig;
    pP->longitud--;
    delete p;
    return x;
}

int main()
{
    Pila P1;
    Elemento e;
    
    construir( &P1 );
    mostrar( P1);
    
    apilar( &P1, 25);
    mostrar(P1);
    
    apilar( &P1, 72);
    mostrar(P1);
    
    apilar( &P1, 48);
    mostrar(P1);
    
    apilar( &P1, 50);
    mostrar(P1);
    
    while ( !esPilaVacia(P1) )
    {
        e = desapilar( &P1);
        cout << "dato desapilado: " << e << endl;
        mostrar(P1);
    }
    return 0;
}
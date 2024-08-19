#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodoC
{
    Elemento elem;
    struct nodoC *sig;
} NodoC;

typedef struct
{
    NodoC *frente;
    NodoC *final;
    int longitud;
} Cola;

void construir( Cola *pC )
{
    // toda cola empieza vacia
    pC->frente = NULL;
    pC->final = NULL;
    pC->longitud = 0;
}

bool esColaVacia( Cola C)
{
    return C.frente == NULL;
    // return C.final == NULL;
    // return C.longitud == 0;
}

int obtenerLongitud( Cola C )
{
    return C.longitud;
}

NodoC* crearNodo( Elemento e, NodoC *s )
{
    NodoC *p;
    p = new NodoC;
    p->elem = e;
    p->sig = s;
    return p;  // devuelve la direccion del nodo creado
}

void mostrar( Cola C )
{
    NodoC *p;
    int i;
    if ( esColaVacia(C) )
        cout << "Cola vacia" << endl;
    else
    {
        p = C.frente;
        for(i=1; i<=C.longitud; i++)
        {
            cout << p->elem << "  ";
            p = p->sig;
        }
        cout << endl;
    }
}

void encolar( Cola *pC, Elemento e )
{
    NodoC *p, *pU;
    p = crearNodo( e, NULL);
    if ( esColaVacia(*pC) )
    {
        pC->frente = p;
    }
    else
    {
        pU = pC->final;
        pU->sig = p;
    }
    pC->final = p;
    pC->longitud++;
}

// esta funcion solo sera invocada si la cola no esta vacia
Elemento desencolar( Cola *pC )
{
    Elemento x;
    NodoC *p;
    p = pC->frente;
    x = p->elem;
    pC->frente = p->sig;
    if ( pC->longitud == 1 )
        pC->final = NULL;
    pC->longitud--;
    delete p;
    return x;
}

void destruir( Cola *pC )
{
    int i;
    NodoC *p, *q;
    if ( !esColaVacia(*pC) )
    {
        p = pC->frente;
        for(i=1; i<=pC->longitud; i++)
        {
            q = p->sig;
            delete p;
            p = q;
        }
        pC->frente = NULL;
        pC->final = NULL;
        pC->longitud = 0;
    }
}

int main()
{
    Cola C1;
    Elemento e;
    
    construir(&C1);
    mostrar(C1);
    
    encolar(&C1,28);
    mostrar(C1);
    
    encolar(&C1,14);
    mostrar(C1);
    
    encolar(&C1,35);
    mostrar(C1);
    
    encolar(&C1,80);
    mostrar(C1);
    
    /* while( !esColaVacia(C1) )
    {
        e = desencolar(&C1);
        cout << "elemento desencolado: " << e << endl;
        mostrar(C1);
    }*/
    
    destruir( &C1);
    mostrar(C1);
    
    return 0;
}
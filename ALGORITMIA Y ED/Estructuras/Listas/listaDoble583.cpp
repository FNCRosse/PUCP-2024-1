#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodo
{
    struct nodo *ant;
    Elemento elem;
    struct nodo *sig;
} Nodo;

typedef struct
{
    Nodo *cabeza;
    int longitud;
} ListaD;

void construir( ListaD *pL )
{
    // toda lista empieza vacia
    pL->cabeza = NULL;
    pL->longitud = 0;
}

bool esListaVacia( ListaD L)
{
    return L.cabeza == NULL;
    // return L.longitud == 0;
}

int obtenerLongitud( ListaD L )
{
    return L.longitud;
}

Nodo* crearNodo( Nodo *a, Elemento e, Nodo *s )
{
    Nodo *p;
    p = new Nodo;
    p->ant = a;
    p->elem = e;
    p->sig = s;
    return p;  // devuelve la direccion del nodo creado
}

void insertarComienzo( ListaD *pL, Elemento e )
{
    Nodo *p, *q;
    p = crearNodo( NULL ,e, pL->cabeza);
    if (!esListaVacia(*pL) )
    {
        q = pL->cabeza;
        q->ant = p;
    }
    pL->cabeza = p;
    pL->longitud++;
}

void mostrar( ListaD L )
{
    Nodo *p;
    int i;
    if ( esListaVacia(L) )
        cout << "Lista vacia" << endl;
    else
    {
        p = L.cabeza;
        for(i=1; i<=L.longitud; i++)
        {
            cout << p->elem << "  ";
            p = p->sig;
        }
        cout << endl;
    }
}

Nodo* ubicarUltimo( ListaD L )
{
    Nodo *pU;
    int i;
    if ( esListaVacia(L) )
        return NULL;   //  no hay ultimo al ser la lista vacia
    else
    {
        pU = L.cabeza;
        for(i=1; i<=L.longitud-1; i++)
            pU = pU->sig;
        return pU;  // devuelve la direccion del ultimo nodo    
    }
}

void mostrarReves( ListaD L )
{
    Nodo *p;
    int i;
    p = ubicarUltimo(L);
    if ( p == NULL )
        cout << "Lista vacia" << endl;
    else
    {
        for(i=1;i<=L.longitud;i++)
        {
            cout << p->elem << "  ";
            p = p->ant;
        }
        cout << endl;
    }
}

void insertarFinal( ListaD *pL, Elemento e )
{
    Nodo *p, *pU;
    
    pU = ubicarUltimo(*pL);
    p = crearNodo( pU , e, NULL);
    if ( pU == NULL )
        pL->cabeza = p;
    else
        pU->sig = p;
    pL->longitud++;
}

void destruir( ListaD *pL )
{
    Nodo *p, *q;
    int i;
    if ( !esListaVacia(*pL) )
    {
        p = pL->cabeza;
        for(i=1;i<=pL->longitud;i++)
        {
            q = p->sig;
            delete p;
            p = q;
        }
        pL->cabeza = NULL;
        pL->longitud = 0;
        cout << "Todos los nodos han sido eliminados" << endl;
    }
}


int main()
{
    ListaD L1;
    construir(&L1);
    mostrar(L1);
    mostrarReves(L1);
    
    insertarComienzo(&L1,61);
    mostrar(L1);
    mostrarReves(L1);
    
    insertarComienzo(&L1,82);
    mostrar(L1);
    mostrarReves(L1);
    
    insertarComienzo(&L1,37);
    mostrar(L1);
    mostrarReves(L1);
     
    insertarComienzo(&L1,66);
    mostrar(L1);
    mostrarReves(L1);
    
    insertarFinal( &L1, 22);
    mostrar(L1);
    mostrarReves(L1);
    
    insertarFinal( &L1, 55);
    mostrar(L1);
    mostrarReves(L1);
    
    destruir(&L1);
    mostrar(L1);
    mostrarReves(L1);
    
    return 0;
}


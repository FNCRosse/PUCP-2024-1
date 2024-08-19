#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodo
{
    Elemento elem;
    struct nodo *sig;
} Nodo;

typedef struct
{
    Nodo* cabeza;
    int longitud;
} ListaC;

void construir( ListaC *pL )
{
    pL->cabeza = NULL;
    pL->longitud = 0;
    // la lista empieza vacia
}

bool esListaVacia( ListaC L )
{
    return L.cabeza == NULL;
    // return L.longitud == 0;
}

int obtenerLongitud( ListaC L )
{
    return L.longitud;
}

Nodo* crearNodo( Elemento e, Nodo *s )
{
    Nodo *p;
    p = new Nodo;
    p->elem = e;
    p->sig = s;
    return p; // retorna la direccion del nodo creado
} 

Nodo* ubicarUltimo( ListaC L )
{
    int i;
    Nodo *pU;
    if ( esListaVacia(L) )
        return NULL;
    else
    {
        pU = L.cabeza;
        for(i=1;i<=L.longitud-1;i++)
            pU = pU->sig;
        return pU; // retorna la direccion del ultimo nodo
    }
}

void insertarComienzo( ListaC *pL, Elemento e )
{
    Nodo *p, *pU;
    p = crearNodo( e, pL->cabeza );
    pU = ubicarUltimo( *pL );
    if ( pU == NULL ) // la lista esta vacia
        p->sig = p;
    else // la lista ya tiene nodos
        pU->sig = p;
    pL->cabeza = p;
    pL->longitud++;
}

void mostrar( ListaC L )
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

void insertarFinal( ListaC *pL, Elemento e )
{
    Nodo *p, *pU;
    p = crearNodo( e, pL->cabeza );
    pU = ubicarUltimo( *pL );
    if ( pU == NULL ) // lista esta vacia
    {
        p->sig = p;
        pL->cabeza = p;
    }
    else // lista no esta vacia
        pU->sig = p;
    pL->longitud++;    
}

Nodo* ubicar( ListaC L, Elemento e )
{
    Nodo *p;
    int i;
    p = L.cabeza;
    for(i=1; i<=L.longitud; i++)
    {
        if ( p->elem == e )
            return p;
        p = p->sig;
    }
    return NULL;
}

Nodo* ubicarAnterior( ListaC L, Elemento e)
{
    Nodo *p, *pA;
    int i;
    pA = NULL;
    p = L.cabeza;
    for(i=1; i<=L.longitud; i++)
    {
        if ( p->elem == e )
            return pA;
        pA = p;
        p = p->sig;
    }
}

void eliminar( ListaC *pL, Elemento e )
{
    Nodo *p, *pU, *pA;
    if ( esListaVacia(*pL) )
        cout << "No se pude eliminar de una lista vacia" << endl;
    else
    {
        p = ubicar( *pL, e);
        if ( p==NULL) // el dato no esta en Lista
            cout << "No se puede eliminar un dato inexistente" << endl;
        else
        {
            pA = ubicarAnterior(*pL,e);
            if ( pA == NULL) // se elimina 1er nodo
            {
                if ( pL->longitud == 1 )
                    pL->cabeza = NULL;
                else
                {
                    pU = ubicarUltimo(*pL);
                    pL->cabeza = p->sig;
                    pU->sig = p->sig;
                }
            }
            else  // no es el primero
            {
                pA->sig = p->sig;
            }
            delete p;
            pL->longitud--;
        }
    }
}

void destruir( ListaC *pL )
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
        cout << "La lista ha sido destruida" << endl;
    }
}

int main()
{
    ListaC L1;
    construir( &L1);
    mostrar( L1);
    
    insertarComienzo( &L1, 39);
    mostrar(L1);
    
    insertarComienzo( &L1, 72);
    mostrar(L1);
    
    insertarComienzo( &L1, 48);
    mostrar(L1);
    
    insertarComienzo( &L1, 94);
    mostrar(L1);
    
    insertarFinal( &L1, 28);
    mostrar(L1);
    
    eliminar( &L1, 11);
    mostrar(L1);
    
    eliminar( &L1, 72);
    mostrar(L1);
    
    eliminar(&L1, 28);
    mostrar(L1);
    
    eliminar(&L1, 94);
    mostrar(L1);
    
    destruir(&L1);
    mostrar(L1);
    
    return 0;
}

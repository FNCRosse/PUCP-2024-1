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
    Nodo *cabeza;
    int longitud;
} Lista;

void construir( Lista *pL )
{
    // toda lista empieza vacia
    pL->cabeza = NULL;
    pL->longitud = 0;
}

bool esListaVacia( Lista L)
{
    return L.cabeza == NULL;
    // return L.longitud == 0;
}

int obtenerLongitud( Lista L )
{
    return L.longitud;
}

Nodo* crearNodo( Elemento e, Nodo *s )
{
    Nodo *p;
    p = new Nodo;
    p->elem = e;
    p->sig = s;
    return p;  // devuelve la direccion del nodo creado
}

void insertarComienzo( Lista *pL, Elemento e)
{
    Nodo *p;
    p = crearNodo( e, pL->cabeza);
    pL->cabeza = p;
    pL->longitud++;
}

void mostrar( Lista L )
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

Nodo* ubicarUltimo( Lista L )
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

void insertarFinal( Lista *pL, Elemento e)
{
    Nodo *p, *pU;
    
    p = crearNodo(e,NULL );  
    
    if ( esListaVacia(*pL) )
        pL->cabeza = p;
    else
    {
        pU = ubicarUltimo(*pL);
        pU->sig = p;
    }
    pL->longitud++;
}

Nodo* ubicar( Lista L, Elemento e)
{
    Nodo *p;
    int i;
    if ( esListaVacia(L) )
        return NULL;
    else
    {
        p = L.cabeza;
        for(i=1;i<=L.longitud;i++)
        {
            if ( p->elem == e )
                return p;  // devuelve la direc del nodo donde encontro el dato el e
            p = p->sig;
        }
        return NULL;  // el dato no fue hallado en la lista
    }
}
    
Nodo* ubicarAnterior( Lista L, Elemento e)
{
    Nodo *p, *pA;
    int i;
    pA = NULL;
    p = L.cabeza;
    for(i=1;i<=L.longitud;i++)
    {
        if ( p->elem == e )
            return pA;
        pA = p;
        p = p->sig;
    }
}
    
void eliminar( Lista *pL, Elemento e)
{
    Nodo *p, *pA;
        
    p = ubicar( *pL, e);
    if ( p == NULL )  // el dato e no esta en la Lista
        cout << "No se puede eliminar un dato inexistente" << endl;
    else  // el dato si está en la Lista
    {
        pA = ubicarAnterior(*pL,e);
        if ( pA == NULL) // el nodo a eliminar es el primero
            pL->cabeza = p->sig;  
        else // el nodo a eliminar no es el primero 
            pA->sig = p->sig;
        pL->longitud--;
        delete p;  // se elimina el nodo
    }
}

void destruir( Lista *pL )
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
    Lista L1;
    construir( &L1);
    mostrar(L1);
    
    /*insertarComienzo( &L1, 48);
    mostrar( L1);
    
    insertarComienzo( &L1, 51);
    mostrar( L1);
    
    insertarComienzo( &L1, 37);
    mostrar( L1);
    
    insertarComienzo( &L1, 24);
    mostrar( L1);
    
    insertarComienzo( &L1, 80);
    mostrar( L1);*/
    
    insertarFinal(&L1, 32);
    mostrar(L1);
    
    insertarFinal(&L1, 90);
    mostrar(L1);
    
    insertarFinal(&L1, 25);
    mostrar(L1);
    
    insertarFinal(&L1, 17);
    mostrar(L1);
    
    insertarFinal(&L1, 42);
    mostrar(L1);
    
    eliminar(&L1,25);
    mostrar(L1);
    
    eliminar(&L1,42);
    mostrar(L1);
    
    eliminar(&L1,32);
    mostrar(L1);
    
    eliminar(&L1,100);
    mostrar(L1);
    
    destruir(&L1);
    mostrar(L1);
    
    return 0;
}


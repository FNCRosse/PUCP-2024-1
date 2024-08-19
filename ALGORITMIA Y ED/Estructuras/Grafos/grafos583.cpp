#include<iostream>

using namespace std;

typedef struct nodoA
{
    char vertice;  
    struct nodoA *sig;  
} NodoA;

typedef struct nodoV
{
    char vertice;  
    nodoA *ady;
    struct nodoV *sig;  
} NodoV;

typedef struct
{
    NodoV *cabeza; 
    int cantV; 
} Grafo;

void construir( Grafo *pG )
{
    
    pG->cabeza = NULL;
    pG->cantV = 0;
}

bool esGrafoVacio( Grafo G )
{
    return G.cabeza == NULL;

}

NodoV* crearNodoV( char v, NodoV *s )
{
    NodoV *p;
    p = new NodoV; 
    p->vertice = v;
    p->ady = NULL;
    p->sig = s;
    return p;
}

NodoA* crearNodoA( char v, NodoA *s )
{
    NodoA *p;
    p = new NodoA; 
    p->vertice = v;
    p->sig = s;
    return p;
}

void mostrar( Grafo G )
{
    NodoV *p;
    NodoA *q;
    if ( esGrafoVacio(G) )
        cout << "El grafo esta vacio" << endl;
    else
    {
        p = G.cabeza;
        while ( p!= NULL )
        {
            cout << "vertice "<< p->vertice << ":   vertices adyacentes = ";
            q = p->ady;
            while ( q != NULL )
            {
            	cout << q->vertice << " ";
            	q = q->sig;
			}
			cout << endl;
            p = p->sig;
        }
        cout << endl;
    }
}

NodoV* ubicarVertice( Grafo G, char v )
{
    NodoV *p;
    if ( esGrafoVacio(G) )
        return NULL;
    else
    {
        p = G.cabeza;
        while ( p != NULL )
        {
            if ( p->vertice == v )
                return p;
            p = p->sig;    
        }
        return NULL;
    }
}

NodoV* ubicarUltimoV( Grafo G )
{
    NodoV *pU;
    int i;
    if ( esGrafoVacio(G) )
        return NULL;
    else
    {
        pU = G.cabeza;
        for(i=1; i<=G.cantV-1; i++ )
            pU = pU->sig;
        return pU;
    }
}

void insertarFinalV( Grafo *pG, char v )
{
    NodoV *p, *q, *pU;
    q = ubicarVertice( *pG, v );
    if ( q == NULL )
    {
    	p = crearNodoV( v, NULL);
    	if ( esGrafoVacio(*pG) )
        	pG->cabeza = p;
    	else
    	{
        	pU = ubicarUltimoV( *pG );
        	pU->sig = p;
    	}
    	pG->cantV++;
	}
	else
		cout << "El vertice " << v << " ya se encuentra en el grafo" << endl;
    
}

NodoA* ubicarUltimoA( NodoA *pLA )
{
    NodoA *pU;
    int i;
    if ( pLA == NULL )
        return NULL;
    else
    {
        pU = pLA;
        while (  pU->sig != NULL )
            pU = pU->sig;
        return pU;
    }
}

void insertarFinalA( NodoA* *pLA, char v )
{
    NodoA *p, *pU;
    p = crearNodoA( v, NULL);
    if ( *pLA == NULL )
        *pLA = p;
    else
    {
        pU = ubicarUltimoA( *pLA );
        pU->sig = p;
    }
}

void agregarAdyacente( Grafo *pG, char v1, char v2 )
{
	NodoV *pv1, *pv2;
	pv1 = ubicarVertice( *pG, v1);
	pv2 = ubicarVertice( *pG, v2);
	if ( pv1 == NULL || pv2 == NULL )
		cout << "Uno a ambos vertices no existen " << endl;
	else
		insertarFinalA( &(pv1->ady), v2 );		
}

int main()
{
    Grafo G1;
    construir( &G1 );
    mostrar( G1 );
    
    insertarFinalV( &G1, 'A');
    mostrar( G1);
    
    insertarFinalV( &G1, 'B');
    mostrar( G1);
    
    insertarFinalV( &G1, 'C');
    mostrar( G1);
    
    insertarFinalV( &G1, 'D');
    mostrar( G1);
    
    insertarFinalV( &G1, 'C');
    
    agregarAdyacente( &G1, 'A' , 'B' );
    agregarAdyacente( &G1, 'A' , 'C' );
    agregarAdyacente( &G1, 'B' , 'B' );
    agregarAdyacente( &G1, 'C' , 'A' );
    agregarAdyacente( &G1, 'C' , 'B' );
    agregarAdyacente( &G1, 'C' , 'C' );
    agregarAdyacente( &G1, 'D' , 'C' );
    
    mostrar( G1);
    
    return 0;
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAYOR 0
#include "arbolBinario.h"
using namespace std;
/*Construir Arbol*/
void construir(ABB *punteroArbol){
    punteroArbol->raiz=NULL;
}
/*Crear nuevo nodo en el arbol*/
NodoAlumno *crearNuevoNodoAlumno(char alumno[20]){
    NodoAlumno *nuevoNodo=new NodoAlumno;
    strcpy(nuevoNodo->alumno,alumno);
    nuevoNodo->pcur=NULL;
    nuevoNodo->hder=NULL;
    nuevoNodo->hizq=NULL;
    return nuevoNodo;
}
/*Buscaremos al alumno dentro del arbol*/
/*Profesor esta funcion la usare mucho por eso es que la declaro aca como es una de las que usamos en clase*/

NodoAlumno *ubicarAlumno(NodoAlumno *punteroArbol, char alumno[20]){
    nodoAlumno *recorrido;
    recorrido = punteroArbol;
    while ( recorrido != NULL )
    {
        if ( strcmp(recorrido->alumno,alumno)==0 )
            return recorrido;
        else
            if ( strcmp(recorrido->alumno,alumno)>0 )
                recorrido = recorrido->hizq;
            else
                recorrido = recorrido->hder;
    }
    return NULL;
}
/*Agregaremos un nuevo nodo al arbol con el dato del alumno*/
void registrarAlumno( ABB *alumnos, char alumno[20])
{   
    NodoAlumno *nuevoNodo, *punteroSigue2, *punteroSigue, *punteroAlumno;
    nuevoNodo= crearNuevoNodoAlumno(alumno);
    if ( alumnos->raiz==NULL)
        alumnos->raiz = nuevoNodo;
    else
    {
        punteroAlumno=ubicarAlumno(alumnos->raiz,alumno);
        if(punteroAlumno!=NULL){
            cout<<"No se puede agregar el alumno ya se encuentra"<<endl;
        }
        else{
            punteroSigue = NULL;
            punteroSigue2 = alumnos->raiz;
            while ( punteroSigue2 != NULL )
            {
                punteroSigue = punteroSigue2;
                if ( strcmp(alumno,punteroSigue2->alumno)<0 )    
                    punteroSigue2 = punteroSigue2->hizq;
                else 
                    punteroSigue2 = punteroSigue2->hder;
            }
            if ( strcmp(alumno,punteroSigue->alumno)<0 )
                punteroSigue->hizq = nuevoNodo;
            else
            punteroSigue->hder = nuevoNodo;        
        }
    }
}

NodoCurso *crearNuevoNodoCurso(NodoCurso *siguiente, int nota, char curso[10]){
    NodoCurso *nuevoNodo=new NodoCurso;
    strcpy(nuevoNodo->curso,curso);
    nuevoNodo->nota=nota;
    nuevoNodo->sig=siguiente;
    return nuevoNodo;
}

void registrarNota(ABB *alumnos,char alumno[20], int nota, char curso[10]){
    NodoAlumno *puntero=ubicarAlumno(alumnos->raiz,alumno);
    if(puntero==NULL){
        cout<<"El alumno no esta en el arbol"<<endl;
    }
    else{
        NodoCurso *nuevoNodo=crearNuevoNodoCurso(puntero->pcur,nota,curso);
        puntero->pcur=nuevoNodo;
    }
}

void mostrarNotasAlumno(NodoAlumno *raiz,char alumno[20]){
    NodoAlumno *punteroAlumno=ubicarAlumno(raiz,alumno);
    if(punteroAlumno==NULL){
        cout<<"No se encontro al alumno"<<endl;
    }
    else{
        NodoCurso *recorrido=punteroAlumno->pcur;
        int mostrarCabeza=1;
        cout<<"[";
        while(recorrido!=NULL){
            if(!mostrarCabeza)
                cout<<",";
            else
                mostrarCabeza=0;
            cout<<recorrido->curso<<":"<<recorrido->nota;
            recorrido=recorrido->sig;
        }
        cout<<"]";
        cout<<endl;
    }
}

void mostrarNotasCurso(NodoAlumno *punteroAlumno)
{
    NodoAlumno *punteroIzquierdo, *punteroDerecho;
    if ( punteroAlumno!= NULL  )
    {
        punteroIzquierdo = punteroAlumno->hizq;
        punteroDerecho = punteroAlumno->hder;
        mostrarNotasCurso( punteroIzquierdo );
        cout << punteroAlumno->alumno<< "  ";
        mostrarNotasAlumno(punteroAlumno,punteroAlumno->alumno);
        mostrarNotasCurso( punteroDerecho );
    }
}

int obtenerCursoMejorNota(NodoAlumno *raiz,char alumno[20]){
    NodoAlumno *punteroAlumno=ubicarAlumno(raiz,alumno);
    NodoCurso *guardarMayor;
    guardarMayor->nota=MAYOR;
    if(punteroAlumno==NULL){
        cout<<"No se encontro al alumno"<<endl;
    }
    else{
        NodoCurso *recorrido=punteroAlumno->pcur;
        while(recorrido!=NULL){
            if(recorrido->nota > guardarMayor->nota)
               guardarMayor= recorrido;
            recorrido=recorrido->sig;
        }  
    }
    return guardarMayor->nota;
}

void aprobadosDesaprobados(NodoAlumno *raiz,char curso[10], int *aprobados, 
        int *desaprobados){
    NodoAlumno *punteroIzquierdo, *punteroDerecho;
    if ( raiz!= NULL  )
    {
        NodoCurso *recorrido=raiz->pcur;
        punteroIzquierdo = raiz->hizq;
        punteroDerecho = raiz->hder;
        aprobadosDesaprobados( punteroIzquierdo, curso,aprobados,desaprobados);
        while(recorrido!=NULL){
            if(recorrido->nota<11 and strcmp(curso,recorrido->curso)==0){
                *desaprobados++;
            }
            if(recorrido->nota>11 and strcmp(curso,recorrido->curso)==0){
                *aprobados++;
            }
            recorrido=recorrido->sig;
        }
        aprobadosDesaprobados( punteroDerecho,  curso,aprobados,desaprobados);
    }
}
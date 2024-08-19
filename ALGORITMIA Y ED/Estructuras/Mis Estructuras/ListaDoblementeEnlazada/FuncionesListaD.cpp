/* 
 * File:   FuncionesListaD.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de abril de 2024, 14:26
 */
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ListaDoble.h"
#include "FuncionesListaD.h"

///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct ListaD &tad){
    tad.Cabeza = nullptr;
    tad.Cola = nullptr;
    tad.Longitud =0;
}
bool ListaEstaVacia(const struct ListaD &tad){
    return tad.Cabeza == nullptr;
}
int LongitudLista(const struct ListaD &tad){
    return tad.Longitud;
}

/////////////////////////////////////////////////////////////////////// INSERTAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void InsertarInicio(struct ListaD &tad,struct Equipo elem){
    struct Nodo* NuevoNodo = CrearNodo(elem,nullptr,nullptr);
    if(tad.Cabeza != nullptr){ //Si hay un dato a mas, significa que el anterior debe be apuntar al nuevo nodo
        tad.Cabeza->Ant = NuevoNodo;
    }
    NuevoNodo->Sig = tad.Cabeza;
    tad.Cabeza = NuevoNodo;
    if(NuevoNodo->Sig == nullptr){ //Si este es el primer dato el sig del nuevo nodo es nulo, entonces es la cola
        tad.Cola = NuevoNodo;
    }
    tad.Longitud++;
}
void InsertarFinal(struct ListaD &tad,struct Equipo elem){
    struct Nodo* NuevoNodo = CrearNodo(elem,nullptr,nullptr);
    struct Nodo * UltimoNodo = tad.Cola;
    if(UltimoNodo == nullptr){ //la lista esta vacia
        tad.Cabeza = NuevoNodo;
        tad.Cola = NuevoNodo;
    }
    else{
        UltimoNodo->Sig = NuevoNodo;
        NuevoNodo->Ant = UltimoNodo;
        tad.Cola = NuevoNodo;
    }
    tad.Longitud++;
}
void InsertarEnOrden(struct ListaD &tad,struct Equipo elem){
    struct Nodo* NuevoNodo = CrearNodo(elem,nullptr,nullptr);
    //Nos da el nodo anterior a donde vamos a insertar
    struct Nodo * NodoAnterior = ObtenerNodoAnterior(elem,tad); 
    if(NodoAnterior == nullptr){ // No hay lista o solo hay un elemento en la lista
        NuevoNodo->Sig = tad.Cabeza;
        //Solo hay UN elemento y el nuevo nodo va al comienzo de la lista
        // Redireccionamos su anterior al nuevo nodo
        if(tad.Cabeza != nullptr) tad.Cabeza->Ant = NuevoNodo;
        tad.Cabeza = NuevoNodo;
        //Si NO HAY elemento en la lista entonces la cola es el nuevo nodo
        if(tad.Cabeza->Sig== nullptr) tad.Cola = NuevoNodo;;
    } else { // Hay elementos en la lista
        NuevoNodo->Sig = NodoAnterior->Sig;
        //Por si insierta al final
        if(NodoAnterior->Sig == nullptr) tad.Cola = NuevoNodo;
        else NodoAnterior->Sig->Ant = NuevoNodo;
        NodoAnterior->Sig = NuevoNodo;
        NuevoNodo->Ant = NodoAnterior;
    }
    tad.Longitud++;
}
struct Nodo* CrearNodo(struct Equipo elem,struct Nodo *sig,struct Nodo *Ant){
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->Ant = Ant;
    nuevoNodo->Sig = sig;
    nuevoNodo->equipo = elem;
    return nuevoNodo;
}
struct Nodo* ObtenerNodoAnterior(struct Equipo elem,struct ListaD &tad){
    struct Nodo *Anterior = nullptr;
    struct Nodo * Recorrer = tad.Cabeza;
    while((Recorrer != nullptr ) and (Recorrer->equipo.victorias > elem.victorias)){
        Anterior = Recorrer;
        Recorrer = Recorrer->Sig;
    }
    return Anterior;
}
struct Nodo* EncontrarNodo(const struct ListaD &tad, struct Equipo elem){
    struct Nodo* recorrido = tad.Cabeza;
    while((recorrido!=nullptr) and (strcmp(recorrido->equipo.nombre,elem.nombre)!=0)){
        recorrido = recorrido->Sig;
    }
    return recorrido;
}
/////////////////////////////////////////////////////////////////////// ELIMINAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void EliminarNodo(struct ListaD &tad,struct Equipo elem){
    struct Nodo *NodoAEliminar = EncontrarNodo(tad,elem);
    if(NodoAEliminar != nullptr){
        struct Nodo *NodoAnteriorAEliminar = NodoAEliminar->Ant;
        if(NodoAnteriorAEliminar == nullptr){//Significa que quiere eliminar el 1er elemento
            tad.Cabeza = NodoAEliminar->Sig;
            if(NodoAEliminar->Sig == nullptr) tad.Cola = nullptr;
            else{
                tad.Cabeza->Ant = nullptr;
            }
        } else {
            NodoAnteriorAEliminar->Sig = NodoAEliminar->Sig;
            if(NodoAnteriorAEliminar->Sig != nullptr) NodoAEliminar->Sig->Ant = NodoAnteriorAEliminar;
            else tad.Cola = NodoAnteriorAEliminar;
        }
        delete NodoAEliminar;
        tad.Longitud--;
    }
}
void EliminarCabeza(struct ListaD&tad){
    struct Nodo* NodoEliminar = tad.Cabeza;
    if(NodoEliminar == nullptr){
        cout<<"No se puede eliminar por que la lista esta vacia"<<endl;
        return;
    }
    tad.Cabeza = tad.Cabeza->Sig;
    if(NodoEliminar->Sig == nullptr) tad.Cola = nullptr;
    else tad.Cabeza->Ant = nullptr;
    delete NodoEliminar;
    tad.Longitud--;
}
void EliminarCola(struct ListaD&tad){
    struct Nodo* NodoEliminar = tad.Cola;
    if(NodoEliminar == nullptr){
        cout<<"No se puede eliminar por que la lista esta vacia"<<endl;
        return;
    }
    tad.Cola = NodoEliminar->Ant;
    if(NodoEliminar->Ant != nullptr ) NodoEliminar->Ant->Sig = NodoEliminar->Sig;
    else tad.Cabeza = tad.Cola;
    delete NodoEliminar;
    tad.Longitud--;
}
void EliminarRepetidos(struct ListaD &tad){
    struct Nodo*  Anterior= tad.Cabeza;
    struct Nodo* Recorrido = Anterior->Sig;
    while(Recorrido!= nullptr){
         //2.1° Recorrer hasta encontrar si hay elemento repetido
        while(strcmpi(Anterior->equipo.nombre,Recorrido->equipo.nombre)!=0){
            Anterior = Anterior->Sig;
            Recorrido = Recorrido->Sig;
            if(Recorrido == nullptr) break;
        }
         //2.2 Si hay repetido tenemos que redireccionar para luego eliminar el repetido
        if(Recorrido != nullptr){
            Anterior->Sig = Recorrido->Sig;
            Recorrido->Ant = Anterior; //Esto lo unico diferente al de ListaS
            delete Recorrido;
            tad.Longitud--;
            Recorrido = Anterior->Sig;
        }
    }
}
/////////////////////////////////////////////////////////////////////// DESTRUIR LISTA S ///////////////////////////////////////////////////////////////////////
void Destruir(struct ListaD &tad){
    struct Nodo* Eliminar;
    struct Nodo* Recorrer = tad.Cabeza;
    
    while(Recorrer!=nullptr){
        Eliminar = Recorrer;
        Recorrer  =Recorrer->Sig;
        delete Eliminar;
    }
    tad.Cabeza = nullptr;
    tad.Cola = nullptr;
    tad.Longitud = 0;
}

/////////////////////////////////////////////////////////////////////// MOSTRAR LISTA S ///////////////////////////////////////////////////////////////////////
void mostrar(const struct ListaD &tad){
    if(ListaEstaVacia(tad)){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    struct Nodo *recorrer = tad.Cabeza;
    while(recorrer!=nullptr){
        cout<<left<<setw(15)<<recorrer->equipo.nombre<<recorrer->equipo.victorias<<endl;
        recorrer =recorrer->Sig;
    }
}
 
void MostrarDesdeFinal(const struct ListaD &tad){
    if(ListaEstaVacia(tad)){
        cout<<"La lista esta vacia"<<endl;
        return;
    }
    struct Nodo *recorrer = tad.Cola;
    while(recorrer!=nullptr){
        cout<<left<<setw(15)<<recorrer->equipo.nombre<<recorrer->equipo.victorias<<endl;
        recorrer =recorrer->Ant;
    }
}
/////////////////////////////////////////////////////////////////////// INVERTIR  LISTA S ///////////////////////////////////////////////////////////////////////
void InvertirIterativo(struct ListaD &ptrLista){
    struct Nodo* Pinicio, *AntCambio;
    int n = ptrLista.Longitud;
    for(int i=1;i<n;i++){
        AntCambio = ptrLista.Cabeza;
        for(int j=i+1;j<n;j++) AntCambio = AntCambio->Sig;
        if(i==1){
            Pinicio = AntCambio->Sig;
            Pinicio->Ant = nullptr;
        }
        AntCambio->Sig->Sig = AntCambio;
        AntCambio->Ant = AntCambio->Sig;
    }
    AntCambio->Sig = nullptr;
    ptrLista.Cabeza = Pinicio;
    ptrLista.Cola=AntCambio;
}
void InvertirRecursivo(struct ListaD &ptrLista){
    
}
struct Nodo* RecorrerEInvertirRec(Nodo *ptrAntCambio){
    
}
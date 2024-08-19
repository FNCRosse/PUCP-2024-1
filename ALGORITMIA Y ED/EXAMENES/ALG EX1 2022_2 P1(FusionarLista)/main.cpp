/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 19:32
 */

#include <iostream>
using namespace std;
#include "Estructuras.h"
#include "FuncionesLista.h"

void FusionarListas(struct Lista & ListaPrin, struct Lista &ListaSec){
    // Voy a tener un nodo para cada lista para poder recorrerlas
    struct Nodo* NodoP = ListaPrin.Cabeza; //Recorre lista principal donde guardaré la lista fusionada
    struct Nodo* NodoS = ListaSec.Cabeza;//Recorre lista secundaria
    struct Nodo* Anterior = nullptr; 
    //Voy a recorrer la lista secundaria para poder insertarla ordenadamente en la lista principal
    while(NodoS != nullptr){
        //Verificar que la lista Principal no este vacia
        if(NodoP != nullptr){
            //Si es que si hay elementos en la lista principal voy a ir comparandolo con los elementos de la lista 
            // secundaria para ver la forma que voy a ir insertando ordenadamente
            if(NodoS->elem.hora < NodoP->elem.hora){
                //Si es q si cumple, voy hacer una copia del nodoS para ese nodo insertarlo ordenado en 
                // La lista principal
                struct Nodo* CopiaNSec = CrearNodo(NodoS->elem,nullptr);
                
                Anterior->sig = CopiaNSec;
                CopiaNSec->sig = NodoP;
                Anterior =CopiaNSec;
                ListaPrin.longitud++;
                //Ahora avanzamos el nodoS
                NodoS = NodoS->sig;
                
            } else {
                //Si no cumple quiere decir que el elem de LP es menor asi que esta bien su posicion
                //Entonces esa posicion se combierte en el anterior y avanzamos el nodoP
                Anterior = NodoP;
                NodoP = NodoP->sig;
            }
        } else {
            //Si esta vacia significa que no hay elementos en esa lista o que hemos recorrido toda la lista 1
            // entonces solo agregaré los elementos a la lista secundaria a la lista principal
            InsertarFinal(ListaPrin,NodoS->elem);
            NodoS = NodoS->sig;
        }
    }
}
int main(int argc, char** argv) {
    Lista lunes, martes, miercoles, jueves, viernes;
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
    
    insertarEnOrden(lunes,{8,6});
    insertarEnOrden(lunes,{10,14});
    insertarEnOrden(lunes,{12,1});
    
    insertarEnOrden(martes,{9,3});
    insertarEnOrden(martes,{11,8});
    
    insertarEnOrden(miercoles,{8,2});
    insertarEnOrden(miercoles,{9,5});
    insertarEnOrden(miercoles,{10,10});
    
    insertarEnOrden(jueves,{14,13});
    insertarEnOrden(jueves,{15,9});
    insertarEnOrden(jueves,{16,11});
    
    insertarEnOrden(viernes,{17,4});
    insertarEnOrden(viernes,{18,12});
    insertarEnOrden(viernes,{19,7});
    
    Imprimir(lunes);
    Imprimir(martes);
    Imprimir(miercoles);
    Imprimir(jueves);
    Imprimir(viernes);
    
    FusionarListas(lunes,martes);
    FusionarListas(lunes,miercoles);
    FusionarListas(lunes,jueves);
    FusionarListas(lunes,viernes);
    cout<<endl<<"Lista Fusionada"<<endl;
    Imprimir(lunes);
    return 0;
}


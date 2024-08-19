/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 19 de abril de 2024, 10:43
 */

#include <iostream>
using namespace std;
#include "ListaSimplementeEnlazada.h"
#include "FuncionesListaS.h"

int main(int argc, char** argv) {
    struct Lista Personajes ,PersonajeArchivo;
    
    //// CREACION Y DATOS DE LISTA S /////////
    Construir(Personajes);
    Construir(PersonajeArchivo);
    cout<<"Datos De Lista incio: "<<endl;
    cout << ListaEstaVacia(Personajes)<<endl;
    cout << LongitudLista(Personajes)<<endl<<endl;
    
    /// INSERTAR EN LISTA S /////  
    cout<<"Insertar inicio"<<endl;
    InsertarInicio(Personajes,{102,"Aatrox",78});
    InsertarInicio(Personajes,{45,"Ahri",63});
    InsertarInicio(Personajes,{3,"Galio",60});
    mostrar(Personajes);
    
    cout<<endl<<"Insertar Final"<<endl;
    InsertarFinal(Personajes,{245,"Ekko",76});
    InsertarFinal(Personajes,{420,"Illaoi",83});
    InsertarFinal(Personajes,{875,"Bard",52});
    mostrar(Personajes);
    
    cout<<endl<<"Insertar En Orden"<<endl;
    InsertarEnOrden(Personajes,{58,"Caitlyn",80});
    InsertarEnOrden(Personajes,{517,"Sylas",85});
    InsertarEnOrden(Personajes,{223,"Syndra",85});
    mostrar(Personajes);
    
    cout<<endl<<"Insertar apartir de un archivo"<<endl;
    InsertarPorArchivo(PersonajeArchivo,"Personajes.txt");
    mostrar(PersonajeArchivo);
    
    ///// ELIMINAR EN LISTA S ///////
    cout<<endl<<"Eliminar un nodo "<<endl;
    EliminarNodo(PersonajeArchivo,{14,"Seraphine",75});
    EliminarNodo(PersonajeArchivo,{19,"Warwick",82});
    mostrar(PersonajeArchivo);
    
    cout<<endl<<"Eliminar la cabeza  "<<endl;
    EliminarCabeza(PersonajeArchivo);
    mostrar(PersonajeArchivo);
    
    cout<<endl<<"Eliminar la cola  "<<endl;
    EliminarCola(PersonajeArchivo);
    mostrar(PersonajeArchivo);
    
    cout<<endl<<"Eliminar elementos repetidos  "<<endl;
    EliminarRepetidos(PersonajeArchivo);
    mostrar(PersonajeArchivo);
    
    ////DESTRUIR LISTA S //////
    cout<<endl<<"Destruir primera lista creada  "<<endl;
    Destruir(Personajes);
    mostrar(Personajes);
    
    /// INVERTIR LISTS S ///
    cout<<endl<<"Invertir lista creada por archivo "<<endl;
    cout<<"Iterativo: "<<endl;
    InvertirIterativo(PersonajeArchivo);
    mostrar(PersonajeArchivo);
    
    cout<<"Recursivo: "<<endl;
    InvertirRecursivo(PersonajeArchivo);
    mostrar(PersonajeArchivo);
    return 0;
}


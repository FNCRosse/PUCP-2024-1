/* 
 * File:   funcionesListaC.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de abril de 2024, 12:52
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "ListaCircular.h"
#include "funcionesListaC.h"

///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct ListaC &tad){
    tad.Cabeza = nullptr;
    tad.longitud =0;
}
bool ListaEstaVacia(const struct ListaC &tad){
    return tad.Cabeza == nullptr;
}
int LongitudLista(const struct ListaC &tad){
    return tad.longitud;
}

/////////////////////////////////////////////////////////////////////// INSERTAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void InsertarInicio(struct ListaC &tad,int elem){
    //1° Crear un nodo para guardar el nuevo elemento
    struct Nodo* nuevoNodo = CrearNodo(elem,tad.Cabeza);
    if(tad.Cabeza == nullptr){
        tad.Cabeza = nuevoNodo;
        nuevoNodo->Sig = nuevoNodo;
    } else {
        struct Nodo* UltimoNodo = ObtenerUltimoNodo(tad);
        UltimoNodo->Sig = nuevoNodo;
        tad.Cabeza = nuevoNodo;
    }
    tad.longitud++;
}
void InsertarFinal(struct ListaC &tad,int elem){
    //1° Encontrar el ultimo nodo para de desde ahi poner el nuevo nodo
    struct Nodo *UltimoNodo = ObtenerUltimoNodo(tad);
    //2° Crear el nuevo nodo donde voy a poner el dato
    struct Nodo * NuevoNodo = CrearNodo(elem,tad.Cabeza);
    //3° Verificar si hay ultimo nodo, sino hay significa que no hay lista, y direccionamos la cabeza del tad a l nuevo
    //nodo sino redireccionamos el sig del ultimo nodo al nuevo nodo
    if(UltimoNodo ==  nullptr) {
        tad.Cabeza = NuevoNodo;
        NuevoNodo->Sig = NuevoNodo;
    } else {
        UltimoNodo->Sig = NuevoNodo;
    }
    tad.longitud++;
}
struct Nodo* ObtenerUltimoNodo(const ListaC &tad){
    //1° Creamos el nodo que vamos a devolver
    struct Nodo *ultrimo = nullptr;
    //2° Creamos un nodo que nos ayudara a recorrer todo la lista
    struct Nodo *recorrer = tad.Cabeza;
    //3° Recorrer hasta tener el ultimo
    do{
        ultrimo = recorrer;
        recorrer = recorrer->Sig;
    }while(recorrer != tad.Cabeza);
    return ultrimo;
}
struct Nodo* CrearNodo(int elem,struct Nodo *sig){
    struct Nodo* NuevoNodo = new struct Nodo;
    NuevoNodo->Elem = elem;
    NuevoNodo->Sig = sig;
    return NuevoNodo;
}
void InsertarEnOrden(struct ListaC &tad,int elem){
    //1° necesito encontrar el nodo ante
    struct Nodo* nodoAnterior = ObtenerNodoAnterior(elem,tad);
    //2° Crear el nuevo nodo donde guardar el elemento
    struct Nodo* NuevoNodo = CrearNodo(elem,nullptr);
    //3° Verificar si hay nodo anterior
    if(nodoAnterior == nullptr){
        struct Nodo* UltimoNodo = ObtenerUltimoNodo(tad);
        NuevoNodo->Sig = tad.Cabeza;
        tad.Cabeza = NuevoNodo;
        if (UltimoNodo != nullptr ) UltimoNodo->Sig = NuevoNodo;
        else NuevoNodo->Sig = NuevoNodo;
    } else {
        NuevoNodo->Sig = nodoAnterior->Sig;
        nodoAnterior->Sig = NuevoNodo;
    }
    tad.longitud++;
}
struct Nodo* ObtenerNodoAnterior(int elem,struct ListaC &tad){
    struct Nodo* nodoAnterior = nullptr;
    struct Nodo* recorrido = tad.Cabeza;
    do{
        if(recorrido->Elem < elem){
            nodoAnterior = recorrido;
            recorrido = recorrido->Sig;
        }
    }while(recorrido != tad.Cabeza and recorrido->Elem < elem);
    return nodoAnterior;
}
struct Nodo* EncontrarNodo(const struct ListaC &tad, int elem){
    if(ListaEstaVacia(tad)) return nullptr;
    struct Nodo* recorrido = tad.Cabeza;
    do{
        if(recorrido->Elem == elem) return recorrido;
        recorrido = recorrido->Sig;
    }while(recorrido != tad.Cabeza);
    return nullptr;
}

/////////////////////////////////////////////////////////////////////// ELIMINAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void EliminarNodo(struct ListaC &tad,int elem){
   //1° Como quiero eliminar un nodo especifico voy a recorrer hasta obtener uno anterior al de el
    struct Nodo* AnteriorEncontrado = nullptr;
    struct Nodo* recorrido = tad.Cabeza;
    int Encontrado=0;
    do{
        if(recorrido->Elem == elem){
            Encontrado =1;
            break;
        }
        AnteriorEncontrado = recorrido;
        recorrido = recorrido->Sig;
    }while(recorrido != tad.Cabeza);
    //2° Si el recorrido esta en null -> hemos recorrido todo y no ha encontrado elemento, so no elimina,
    //    Si el recorrido no esta en null -> verificamos si es nodo anterior es null
    if( Encontrado){
        // 3°Si el anterior es null -> el elemento a eliminar esta en la cabeza
        //    Si el anterior no es null ->  Lo encontro en otra posicion
        if(AnteriorEncontrado == nullptr){
            if(recorrido == recorrido->Sig) tad.Cabeza = nullptr;
            else{
                struct Nodo* ultimoNodo = ObtenerUltimoNodo(tad);
                tad.Cabeza = recorrido->Sig;
                if(ultimoNodo != nullptr) ultimoNodo->Sig = tad.Cabeza;
            }
        }
        else{
            AnteriorEncontrado->Sig = recorrido->Sig;
        }
        delete recorrido;
        tad.longitud--;
    }
    
}
void EliminarCabeza(struct ListaC&tad){
//    //1° Creas el nodo que apunte a la cabeza pues este sera el q quieres eliminar
//    struct Nodo* nodoEliminar = tad.Cabeza;
//    //2° si este no es nulo enontonces redireccionas la cabeza al siguiete para omitir el valor eliminado 
//    //y eliminas el nodo a eliminar
//    if(nodoEliminar != nullptr){
//        tad.Cabeza = tad.Cabeza->sig;
//        delete nodoEliminar;
//        tad.longitud--;
//    }
}
//Eliminar el ultimo dato de la lista
void EliminarCola(struct ListaC&tad){
//    //1° Crear un nodo ultimo y penultimo para luego redireccionar el penultimo y elimnar el ultimo
//    struct Nodo* Ultimo = nullptr;
//    struct Nodo* Penultimo = nullptr;
//    struct Nodo* recorrido = tad.Cabeza;
//    
//    while( recorrido != nullptr){
//        if( Ultimo != nullptr ) Penultimo = Ultimo; // Solo por el primer caso cuadno tiene solo un elemento
//        Ultimo  = recorrido;
//        recorrido = recorrido->sig;
//    }
//    if(Ultimo != nullptr){
//        //Esto quere decir que no hay penultimo -> solo hay un elemento en la lista
//        if(Penultimo == nullptr ) tad.Cabeza = nullptr;
//        else Penultimo->sig =nullptr;
//        delete Ultimo;
//        tad.longitud--;
//    }
}
void EliminarRepetidos(struct ListaC &tad){
//    //1° Tener ambos nodos, para luego comparar sus elementos si tiene repertidos
//    struct Nodo* Anterior = tad.Cabeza;
//    struct Nodo* recorrido = tad.Cabeza->sig;
//    //2° Recorrer toda la lista
//    while(recorrido != nullptr){
//        //2.1° Recorrer hasta encontrar si hay elemento repetido
//        while( Anterior->elem.id != recorrido->elem.id){
//            Anterior = Anterior->sig;
//            recorrido = recorrido->sig;
//            if(recorrido == nullptr) break;
//        }
//        //2.2 Si hay repetido tenemos que redireccionar para luego eliminar el repetido
//        if(recorrido != nullptr){
//            Anterior->sig = recorrido->sig;
//            delete recorrido;
//            tad.longitud--;
//            recorrido = Anterior->sig;
//        }
//    }
}
/////////////////////////////////////////////////////////////////////// DESTRUIR LISTA S ///////////////////////////////////////////////////////////////////////
void Destruir(struct ListaC &tad){
    //1° crear un nodo para recorrer la lista
    struct Nodo* recorrido = tad.Cabeza;
    if(recorrido == nullptr) return;
    //2° recorrer la lista y por cada nodo recorrido le asigno un nodo aux que luego hare delete
    do{
        struct Nodo * nodoEliminar = recorrido;
        recorrido = recorrido->Sig;
        delete nodoEliminar;
    } while(recorrido!= tad.Cabeza);
    //3° volver a inicializar la lista
    tad.Cabeza = nullptr;
    tad.longitud =0;
}

/////////////////////////////////////////////////////////////////////// MOSTRAR LISTA S ///////////////////////////////////////////////////////////////////////
void mostrar(const struct ListaC &tad){
    if(ListaEstaVacia(tad)){
        cout<<"La lista esta vacia, no hay datos para mostrar"<<endl;
        return;
    } else {
        struct Nodo *recorrido = tad.Cabeza;
        do{
            cout<<recorrido->Elem<<" ";
            recorrido = recorrido->Sig;
        }while (recorrido != tad.Cabeza);
    }
}

/////////////////////////////////////////////////////////////////////// INVERTIR  LISTA S ///////////////////////////////////////////////////////////////////////
void InvertirIterativo(struct ListaC &ptrLista){
//    struct Nodo *Pinicio; //Aqui guardare el ultimo nodo, pues este sera el primero en la lista invertida
//    struct Nodo * ptrAntCambio; // Con este recorrere hasta esta un nodo anterior al nodo que voy a redireccionar
//    int n = ptrLista.longitud;
//    //1° Crear un for para cambiar la direcciones e invertir estas
//    for(int i=1;i<n;i++){
//        //1.1° le damos la cabeza de la lista al ptr con el que voy a recorrer
//        ptrAntCambio = ptrLista.Cabeza;
//        //1.2° Este recorrera hasta el nodo anterior del q queremos redireccionar
//        for(int j=i+1;j<n;j++) ptrAntCambio = ptrAntCambio->sig;
//        //1.3 Si es la primera iteracion, habremos llegado al final, entonces asignamos el Pinicio
//        if(i == 1) Pinicio = ptrAntCambio->sig;
//        //1.4 para acceder al nodo que queremos redireccionar seria con ptrAntCambio->sig, pero como queremos
//        // es redireccionar el sig de este nodo, seria asi ptrAntCambio->sig->sig, y ahi es donde le asignamos el anterior
//        ptrAntCambio->sig->sig = ptrAntCambio;
//    }
//    // 2° como donde deje el ptrAntCambio sigue redirecionando a la lista, y este sera nuestro ultimo, pues 
//    //lo tenemos que redireccionar a nullptr
//    ptrAntCambio->sig = nullptr;
//    //3° Finalmente le tenemos que dar a la cabeza la nueva direccion, es decir el nodo Pinicio
//    ptrLista.Cabeza = Pinicio;
}
void InvertirRecursivo(struct ListaC &ptrLista){
//    //1° Crear una funcion recursiva que me va traer el nodo ya invertido
//    struct Nodo *PInicio = RecorrerEInvertirRec(ptrLista.Cabeza);
//    // 2° darle null al primer elemento para que no sea un bucle
//    ptrLista.Cabeza->sig = nullptr;
//    //3° dar la direccion del nodo  ya invertido;
//    ptrLista.Cabeza = PInicio;
}
struct Nodo* RecorrerEInvertirRec(Nodo *ptrAntCambio){
//    //Caso Base
//    if(ptrAntCambio == nullptr) return nullptr;
//    // Caso que encuentre el ultimo nodo = PrimerNodo de la lista invertida
//    if( ptrAntCambio->sig == nullptr) return ptrAntCambio;
//    // Creamos el PI y hacemos que recorra hasta que cumpla lo de arriba
//    struct Nodo* PInicio = RecorrerEInvertirRec(ptrAntCambio->sig);
//    //Una vez ya tengamos el inicio aplicamos el 1.4 del invertir iterativo
//    ptrAntCambio->sig->sig = ptrAntCambio;
//    //Y lo vamos retornando con esos cambios
//    return PInicio;
}

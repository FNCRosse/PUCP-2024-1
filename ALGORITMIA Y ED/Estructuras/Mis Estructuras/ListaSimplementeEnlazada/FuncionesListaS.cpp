/* 
 * File:   FuncionesListaS.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 19 de abril de 2024, 10:49
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesListaS.h"
///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct Lista &tad){
    tad.Cabeza = nullptr;
    tad.longitud =0;
}
bool ListaEstaVacia(const struct Lista &tad){
    return tad.Cabeza == nullptr;
}
int LongitudLista(const struct Lista &tad){
    return tad.longitud;
}

/////////////////////////////////////////////////////////////////////// INSERTAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void InsertarInicio(struct Lista &tad,struct Personaje elem){
    //1° Crear un nodo para guardar el nuevo elemento
    struct Nodo* nuevoNodo = new struct Nodo;
    //2° Le damos elemento al nuevo nodo y le damos la cabeza al siguiente del nuevo nodo, por que lo que habia
    //en la lista se va poner despues del nuevo elemento, por q inserta al inicio
    nuevoNodo->elem = elem;
    nuevoNodo->sig = tad.Cabeza;
    // 3° Redireccionamos la cabeza de la lista al nuevo nodo y aumentamos la longitud
    tad.Cabeza =nuevoNodo;
    tad.longitud++;
}
void InsertarFinal(struct Lista &tad,struct Personaje elem){
    //1° Encontrar el ultimo nodo para de desde ahi poner el nuevo nodo
    struct Nodo *UltimoNodo = ObtenerUltimoNodo(tad);
    //2° Crear el nuevo nodo donde voy a poner el dato
    struct Nodo * NuevoNodo = CrearNodo(elem,nullptr);
    //3° Verificar si hay ultimo nodo, sino hay significa que no hay lista, y direccionamos la cabeza del tad a l nuevo
    //nodo sino redireccionamos el sig del ultimo nodo al nuevo nodo
    if(UltimoNodo ==  nullptr) {
        tad.Cabeza = NuevoNodo;
    } else {
        UltimoNodo->sig = NuevoNodo;
    }
    tad.longitud++;
}
struct Nodo* ObtenerUltimoNodo(const Lista &tad){
    //1° Creamos el nodo que vamos a devolver
    struct Nodo *ultrimo = nullptr;
    //2° Creamos un nodo que nos ayudara a recorrer todo la lista
    struct Nodo *recorrer = tad.Cabeza;
    //3° Recorrer hasta tener el ultimo
    while(recorrer != nullptr){
        ultrimo = recorrer;
        recorrer = recorrer->sig;
    }
    return ultrimo;
}
struct Nodo* CrearNodo(struct Personaje elem,struct Nodo *sig){
    struct Nodo* NuevoNodo = new struct Nodo;
    NuevoNodo->elem = elem;
    NuevoNodo->sig = sig;
    return NuevoNodo;
}
void InsertarEnOrden(struct Lista &tad,struct Personaje elem){
    //1° necesito encontrar el nodo ante
    struct Nodo* nodoAnterior = ObtenerNodoAnterior(elem,tad);
    //2° Crear el nuevo nodo donde guardar el elemento
    struct Nodo* NuevoNodo = CrearNodo(elem,nullptr);
    //3° Verificar si hay nodo anterior
    if(nodoAnterior == nullptr){
        NuevoNodo->sig = tad.Cabeza;
        tad.Cabeza = NuevoNodo;
    } else {
        NuevoNodo->sig = nodoAnterior->sig;
        nodoAnterior->sig = NuevoNodo;
    }
    tad.longitud++;
}
struct Nodo* ObtenerNodoAnterior(struct Personaje elem,struct Lista &tad){
    struct Nodo* nodoAnterior = nullptr;
    struct Nodo* recorrido = tad.Cabeza;
    while(( recorrido!=nullptr )and(recorrido->elem.id<elem.id)){
        nodoAnterior = recorrido;
        recorrido = recorrido->sig;
    }
    return nodoAnterior;
}
void InsertarPorArchivo(struct Lista &tad,const char* namefile){
    ifstream arch (namefile,ios::in);
    struct Personaje datosPer;
    while(true){
        arch>>datosPer.id;
        if(arch.eof()) break;
        arch.get();
        datosPer.Nombre = leerNombre(arch);
        arch>>datosPer.poder; arch.get();
        InsertarFinal(tad,datosPer);
    }
}
struct Nodo* EncontrarNodo(const struct Lista &tad, struct Personaje elem){
    struct Nodo* recorrido = tad.Cabeza;
    while((recorrido!=nullptr) and (recorrido->elem.id != elem.id)){
        recorrido = recorrido->sig;
    }
    return recorrido;
}
char * leerNombre(ifstream &arch){
    char nombre[60], *ptrcadena;
    arch.getline(nombre,60,',');
    ptrcadena = new char [strlen(nombre)+1];
    strcpy(ptrcadena,nombre);
    return ptrcadena;
}
/////////////////////////////////////////////////////////////////////// ELIMINAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void EliminarNodo(struct Lista &tad,struct Personaje elem){
   //1° Como quiero eliminar un nodo especifico voy a recorrer hasta obtener uno anterior al de el
    struct Nodo* AnteriorEncontrado = nullptr;
    struct Nodo* recorrido = tad.Cabeza;
    while((recorrido != nullptr) and (recorrido->elem.id != elem.id)){
        AnteriorEncontrado= recorrido;
        recorrido = recorrido->sig;
    }
    //2° Si el recorrido esta en null -> hemos recorrido todo y no ha encontrado elemento, so no elimina,
    //    Si el recorrido no esta en null -> verificamos si es nodo anterior es null
    if( recorrido != nullptr){
        // 3°Si el anterior es null -> el elemento a eliminar esta en la cabeza
        //    Si el anterior no es null ->  Lo encontro en otra posicion
        if(AnteriorEncontrado == nullptr){
            tad.Cabeza = recorrido->sig;
        }
        else{
            AnteriorEncontrado->sig = recorrido->sig;
        }
        delete recorrido;
        tad.longitud--;
    }
    
}
void EliminarCabeza(struct Lista&tad){
    //1° Creas el nodo que apunte a la cabeza pues este sera el q quieres eliminar
    struct Nodo* nodoEliminar = tad.Cabeza;
    //2° si este no es nulo enontonces redireccionas la cabeza al siguiete para omitir el valor eliminado 
    //y eliminas el nodo a eliminar
    if(nodoEliminar != nullptr){
        tad.Cabeza = tad.Cabeza->sig;
        delete nodoEliminar;
        tad.longitud--;
    }
}
//Eliminar el ultimo dato de la lista
void EliminarCola(struct Lista&tad){
    //1° Crear un nodo ultimo y penultimo para luego redireccionar el penultimo y elimnar el ultimo
    struct Nodo* Ultimo = nullptr;
    struct Nodo* Penultimo = nullptr;
    struct Nodo* recorrido = tad.Cabeza;
    
    while( recorrido != nullptr){
        if( Ultimo != nullptr ) Penultimo = Ultimo; // Solo por el primer caso cuadno tiene solo un elemento
        Ultimo  = recorrido;
        recorrido = recorrido->sig;
    }
    if(Ultimo != nullptr){
        //Esto quere decir que no hay penultimo -> solo hay un elemento en la lista
        if(Penultimo == nullptr ) tad.Cabeza = nullptr;
        else Penultimo->sig =nullptr;
        delete Ultimo;
        tad.longitud--;
    }
}
void EliminarRepetidos(struct Lista &tad){
    //1° Tener ambos nodos, para luego comparar sus elementos si tiene repertidos
    struct Nodo* Anterior = tad.Cabeza;
    struct Nodo* recorrido = tad.Cabeza->sig;
    //2° Recorrer toda la lista
    while(recorrido != nullptr){
        //2.1° Recorrer hasta encontrar si hay elemento repetido
        while( Anterior->elem.id != recorrido->elem.id){
            Anterior = Anterior->sig;
            recorrido = recorrido->sig;
            if(recorrido == nullptr) break;
        }
        //2.2 Si hay repetido tenemos que redireccionar para luego eliminar el repetido
        if(recorrido != nullptr){
            Anterior->sig = recorrido->sig;
            delete recorrido;
            tad.longitud--;
            recorrido = Anterior->sig;
        }
    }
    
}
/////////////////////////////////////////////////////////////////////// DESTRUIR LISTA S ///////////////////////////////////////////////////////////////////////
void Destruir(struct Lista &tad){
    //1° crear un nodo para recorrer la lista
    struct Nodo* recorrido = tad.Cabeza;
    //2° recorrer la lista y por cada nodo recorrido le asigno un nodo aux que luego hare delete
    while(recorrido!= nullptr){
        struct Nodo * nodoEliminar = recorrido;
        recorrido = recorrido->sig;
        delete nodoEliminar;
    }
    //3° volver a inicializar la lista
    tad.Cabeza = nullptr;
    tad.longitud =0;
}

/////////////////////////////////////////////////////////////////////// MOSTRAR LISTA S ///////////////////////////////////////////////////////////////////////
void mostrar(const struct Lista &tad){
    if(ListaEstaVacia(tad)){
        cout<<"La lista esta vacia, no hay datos para mostrar"<<endl;
        return;
    } else {
        struct Nodo *recorrido = tad.Cabeza;
        while (recorrido != nullptr) {
            cout<<recorrido->elem.id<<"  "<<recorrido->elem.Nombre<<"    "<<recorrido->elem.poder<<endl;
            recorrido = recorrido->sig;
        }
    }
}

/////////////////////////////////////////////////////////////////////// INVERTIR  LISTA S ///////////////////////////////////////////////////////////////////////
void InvertirIterativo(struct Lista &ptrLista){
    struct Nodo *Pinicio; //Aqui guardare el ultimo nodo, pues este sera el primero en la lista invertida
    struct Nodo * ptrAntCambio; // Con este recorrere hasta esta un nodo anterior al nodo que voy a redireccionar
    int n = ptrLista.longitud;
    //1° Crear un for para cambiar la direcciones e invertir estas
    for(int i=1;i<n;i++){
        //1.1° le damos la cabeza de la lista al ptr con el que voy a recorrer
        ptrAntCambio = ptrLista.Cabeza;
        //1.2° Este recorrera hasta el nodo anterior del q queremos redireccionar
        for(int j=i+1;j<n;j++) ptrAntCambio = ptrAntCambio->sig;
        //1.3 Si es la primera iteracion, habremos llegado al final, entonces asignamos el Pinicio
        if(i == 1) Pinicio = ptrAntCambio->sig;
        //1.4 para acceder al nodo que queremos redireccionar seria con ptrAntCambio->sig, pero como queremos
        // es redireccionar el sig de este nodo, seria asi ptrAntCambio->sig->sig, y ahi es donde le asignamos el anterior
        ptrAntCambio->sig->sig = ptrAntCambio;
    }
    // 2° como donde deje el ptrAntCambio sigue redirecionando a la lista, y este sera nuestro ultimo, pues 
    //lo tenemos que redireccionar a nullptr
    ptrAntCambio->sig = nullptr;
    //3° Finalmente le tenemos que dar a la cabeza la nueva direccion, es decir el nodo Pinicio
    ptrLista.Cabeza = Pinicio;
}
void InvertirRecursivo(struct Lista &ptrLista){
    //1° Crear una funcion recursiva que me va traer el nodo ya invertido
    struct Nodo *PInicio = RecorrerEInvertirRec(ptrLista.Cabeza);
    // 2° darle null al primer elemento para que no sea un bucle
    ptrLista.Cabeza->sig = nullptr;
    //3° dar la direccion del nodo  ya invertido;
    ptrLista.Cabeza = PInicio;
}
struct Nodo* RecorrerEInvertirRec(Nodo *ptrAntCambio){
    //Caso Base
    if(ptrAntCambio == nullptr) return nullptr;
    // Caso que encuentre el ultimo nodo = PrimerNodo de la lista invertida
    if( ptrAntCambio->sig == nullptr) return ptrAntCambio;
    // Creamos el PI y hacemos que recorra hasta que cumpla lo de arriba
    struct Nodo* PInicio = RecorrerEInvertirRec(ptrAntCambio->sig);
    //Una vez ya tengamos el inicio aplicamos el 1.4 del invertir iterativo
    ptrAntCambio->sig->sig = ptrAntCambio;
    //Y lo vamos retornando con esos cambios
    return PInicio;
}
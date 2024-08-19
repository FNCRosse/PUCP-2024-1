/* 
 * File:   ColaConProductos.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 14:43
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ColaGenerica.h"
#include "ColaConProductos.h"
#include "Pregunta02Examen01FuncionesProductos.h"
enum RegCola {CABEZA,COLA,TAMN};
enum RegNodo {DATO,SIG};
enum RegProd {PROD,COLAPED};
enum RedProducto {COD,DESC,PRECIO,STOCK};
enum RegPed {FECHA,DNI,CANTIDAD};

void ProcesarPedidos(int **FechaClienteCantidad,char**CodigoDelProducto,void *Productos){
    for(int i=0;FechaClienteCantidad[i];i++){
        int posCod = BuscarCodigo(CodigoDelProducto[i],Productos);
        if(posCod == -1) continue;
        void **ArrProductos = (void**)Productos;
        if(EsPosibleElPedido(FechaClienteCantidad[i],ArrProductos[posCod])){
            ActualizarStock(FechaClienteCantidad[i],ArrProductos[posCod]);
            void *Dato  = FechaClienteCantidad[i];
            InsertarEnCola(Dato,ArrProductos[posCod]);
        }
    }
}
int BuscarCodigo(char * NomProd,void *Productos){
    void **ArrProductos = (void**)Productos;
    for(int i=0;ArrProductos[i];i++){
        void **Producto = (void**)ArrProductos[i];
        void **DatosProducto = (void**)Producto[PROD];
        char*nomProducto = (char*) DatosProducto[COD];
        if(strcmp(NomProd,nomProducto)==0) return i;
    }
    return -1;
}
bool EsPosibleElPedido(int *FechaClienteCantidad, void *Producto){
    void **ArrProducto = (void**)Producto;
        void **DatosProducto = (void**)ArrProducto[PROD];
        int*stock = (int *) DatosProducto[STOCK];
    if(*stock-FechaClienteCantidad[CANTIDAD]>=0) return true;
    return false;
}
void ActualizarStock(int *FechaClienteCantidad,void *Producto){
     void **DatosProducto = (void**)Producto;
    void **DatosProd = (void**)DatosProducto[PROD];
    int * Stock = (int*)DatosProd[STOCK];
    *Stock = *Stock - FechaClienteCantidad[CANTIDAD];
    DatosProd[STOCK] = Stock;
}
void InsertarEnCola(void *Dato,void *Producto){
    void **DatosProducto = (void**)Producto;
    void *ColaPed = (void*)DatosProducto[COLAPED];
    if(ColaPed == nullptr){
        GeneraCola(ColaPed);
        DatosProducto[COLAPED] = ColaPed;
    }
    Encola(ColaPed,Dato);
}
void reporteDePedidos(void *Productos,const char *namefile){
    ofstream arch (namefile);
    void **ArrProductos = (void **)Productos;
    for(int i=0;ArrProductos[i];i++){
        arch<<"Producto "<<i+1<<":"<<endl;
        imprimirRegistro(arch,ArrProductos[i]);
        ImprimirCola(arch,ArrProductos[i]);
    }
}
void ImprimirCola(ofstream &arch,void *Producto){
    void **DatosProducto = (void**)Producto;
    void *Cola= (void*)DatosProducto[COLAPED];
    if(Cola == nullptr) return;
    void **ColaPed = (void**)Cola;
    while(!ColaVacia(ColaPed[CABEZA])){
        void *nodo = Desencola(ColaPed);
        imprimeColaPedido(arch,nodo);
    }
}
void imprimeColaPedido(ofstream &arch,void *nodo){
    void**NodoAux = (void**)nodo;
    int *DatosCliente = (int*)NodoAux[DATO];
    arch<<left<<setw(15)<<DatosCliente[FECHA]<<setw(15)<<DatosCliente[DNI]<<DatosCliente[CANTIDAD]<<endl;
}
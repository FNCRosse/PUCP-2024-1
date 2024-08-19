/* 
 * File:   ColaConProductos.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 08:03
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pregunta02Examen01PunteroGenerico.h"
#include "ColaConProductos.h"
#include "ColaGenerica.h"
enum RegProd {COD,DESC,PRECIO,STOCK};
enum RegArrProd {DATOS,COLAPED};
enum RegPed {FECHA,DNI,CANTIDAD};
enum RegCola {CABEZA,COLA,TOTAL};
enum RegNodo {DATO,SIG};
void procesarPedidos(int **FechaClienteCantidad,char **CodigoDelProducto,void*Productos){
    void **ArrProductos = (void **)Productos;
    for(int i=0;FechaClienteCantidad[i];i++){
        int PosProd = BuscarProducto (CodigoDelProducto[i],Productos);
        if(PosProd == -1) continue;
        if(EsPosiibleAtenderPedido(FechaClienteCantidad[i],ArrProductos[PosProd])){
            ActualizarStock(FechaClienteCantidad[i],ArrProductos[PosProd]);
            void *Dato=FechaClienteCantidad[i];
            ColocarPedido(ArrProductos[PosProd],Dato);
        }
    }
}
int BuscarProducto (char *codProd,void *Productos){
    void **ArrProductos = (void **)Productos;
    for(int i=0;ArrProductos[i];i++){
        void **ArrProducto = (void **)ArrProductos[i];
        void **DatoProd = (void **)ArrProducto[DATOS];
        char * codigo = (char *)DatoProd[COD];
        if(strcmp(codProd,codigo)==0) return i;
    }
    return -1;
}
bool EsPosiibleAtenderPedido(int *DatosPed, void* Producto){
    void **ArrProducto = (void **)Producto;
    void **DatoProd = (void **)ArrProducto[DATOS];
    int * stock = (int *)DatoProd[STOCK];
    if(*stock-DatosPed[CANTIDAD]>=0) return true;
    else return false;
}
void ActualizarStock(int* DatosPed,void *Producto){
    void **ArrProducto = (void **)Producto;
    void **DatoProd = (void **)ArrProducto[DATOS];
    int * stock = (int *)DatoProd[STOCK];
    *stock = *stock-DatosPed[CANTIDAD];
    DatoProd[STOCK] = stock;
}
void ColocarPedido(void *Producto,void *Dato){
    void **ArrProducto = (void **)Producto;
    void *ColaPed = (void *)ArrProducto[COLAPED];
    if(ColaPed == nullptr){
        GeneraCola(ColaPed);
        ArrProducto[COLAPED] = ColaPed;
    }
    Encola(ColaPed,Dato);
}
void reporteDePedidos(void *Productos,const char* namefile){
    ofstream arch (namefile);
    void **ArrProductos = (void **)Productos;
    for(int i=0;ArrProductos[i];i++){
        arch<<"Producto "<<i+1<<":"<<endl;
        ImprimirProducto(arch,ArrProductos[i]);
        arch<<"Pedidos aceptados"<<endl;
        arch<<left <<setw(10)<<"Fecha"<<setw(15)<<"DNI"<<"Cantidad"<<endl;
        ImprimirColaPedidos(arch,ArrProductos[i]);
        arch<<endl;
    }
}
void ImprimirColaPedidos(ofstream &arch,void *Producto){
    void **ArrProducto = (void **)Producto;
    void *ColaPed = (void *)ArrProducto[COLAPED];
    if(ColaPed == nullptr) return;
    void **Cola = (void **)ColaPed;
    while(!ColaVacia(Cola[CABEZA])){
        void *Nodo = Desencola(ColaPed);
        ImprimirUNPedido(arch,Nodo);
    }
}
void ImprimirUNPedido(ofstream &arch,void *Nodo){
    void **AuxNodo = (void **)Nodo;
    int *DatosCliente = (int*)AuxNodo[DATO];
    arch<<left<<setw(15)<<DatosCliente[FECHA]<<setw(15)<<DatosCliente[DNI]<<DatosCliente[CANTIDAD]<<endl;
}
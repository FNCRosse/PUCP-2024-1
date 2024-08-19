/* 
 * File:   Pregunta02Examen01PunteroGenerico.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 05:37
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;
#include "Pregunta02Examen01PunteroGenerico.h"
enum RegProd {COD,DESC,PRECIO,STOCK};
enum RegArrProd {DATOS,COLA};
void cargaProductos(void *&Productos,const char* namefile){
    ifstream arch(namefile);
    void **ArrProductos, *Buff[200],*Registro;
    int ndatos=0;
    while(true){
        Registro = LeerRegistro(arch);
        if(arch.eof()) break;
        Buff[ndatos] = Registro;
        ndatos++;
    }
    ArrProductos = new void*[ndatos+1]{};
    for(int i=0;i<ndatos;i++){
        ArrProductos[i] = Buff[i];
    }
    Productos = ArrProductos;
}
void PruebaDeCargaProductos(void *Productos,const char* namefile){
    OrdenarProductos(Productos);
    void **ArrProductos = (void **)Productos;
    ofstream arch (namefile);
    for(int i=0;ArrProductos[i];i++){
        ImprimirProducto(arch,ArrProductos[i]);
    }
}
char * LeerCadena(ifstream &arch,char c){
    char cadena[110],*ptrCadena;
    arch.getline(cadena,110,c);
    ptrCadena = new char[strlen(cadena)+1];
    strcpy(ptrCadena,cadena);
    return ptrCadena;
}
void * LeerRegistro(ifstream &arch){
    void **ArrRegistro = new void *[2]{};
    void **Registro = new void *[4]{};
    char *Cod,*Descripcion,c;
    int * numStock = new int;
    double *precio = new double;
    Cod = LeerCadena(arch,',');
    if(arch.eof()) return nullptr;
    Descripcion = LeerCadena(arch,',');
    arch>>*precio>>c>>*numStock;
    arch.get();
    Registro[COD] = Cod;
    Registro[DESC] = Descripcion;
    Registro[PRECIO] = precio;
    Registro[STOCK] = numStock;
    ArrRegistro[DATOS] = Registro;
    ArrRegistro[COLA] = nullptr;
    return ArrRegistro;
}
void ImprimirProducto(ofstream &arch,void *Producto){
    void **ArrProducto = (void **)Producto;
    void **Datos = (void**)ArrProducto[DATOS];
    char* codigo = (char*) Datos[COD];
    char* descripcion = (char*) Datos[DESC];
    double* precio = (double*) Datos[PRECIO];
    int* stock = (int*) Datos[STOCK];
    arch<<left<<setw(14)<<codigo<<descripcion<<endl;
    arch<<"Precio: "<<setw(12)<<*precio<<"Stock: "<<*stock<<endl;
}
void OrdenarProductos(void *Productos){
    void **ArrProductos = (void **)Productos;
    int ndatos=0;
    while(ArrProductos[ndatos])ndatos++;
    qsort(Productos,ndatos,sizeof(void*),cmpCodProd);
}
int cmpCodProd(const void *a, const void*b){
    void **AuxA = (void**)a, **AuxB = (void**)b;
    void **RegA = (void**)(*AuxA), **RegB = (void**)(*AuxB);
    void **ProA = (void**)(RegA[DATOS]), **ProB = (void**)(RegB[DATOS]);
    char *CodA = (char*)ProA[COD], *CodB = (char*)ProB[COD];
    return strcmp(CodA,CodB);
}
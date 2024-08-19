/* 
 * File:   Pregunta02Examen01PunteroGenericos.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 12:22
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pregunta02Examen01PunteroGenericos.h"
#define INCREMENTO 5
enum RedProd {COD,DESC,PRECIO,STOCK};
enum RedArr {DATO,SIG};

void cargarProductos(void *&Productos,const char* namefile){
    ifstream arch (namefile);
    Productos =nullptr;
    void *Registro,**ArrProductos=nullptr;
    int nDatos=0,cap=0;
    while(true){
        Registro = LeerRegistro(arch);
        if(arch.eof()) break;
        if(nDatos == cap) IncrementarEspacios(ArrProductos,nDatos,cap);
        ArrProductos[nDatos-1] = Registro;
        nDatos++;
    }
    Productos = ArrProductos;
}
void * LeerRegistro(ifstream &arch){
    void **ArrRegistro = new void *[2]{};
    void **Registro = new void *[4]{};
    char *cod,*descripcion,c;
    int *stock = new int;
    double *precio = new double ;
    cod = LeerCadena(arch,',');
    if(arch.eof()) return nullptr;
    descripcion = LeerCadena(arch,',');
    arch>>*precio>>c>>*stock;
    arch.get();
    Registro[COD] = cod;
    Registro[DESC] = descripcion;
    Registro[PRECIO] = precio;
    Registro[STOCK] = stock;
    ArrRegistro[DATO] = Registro;
    ArrRegistro[SIG] = nullptr;
    return ArrRegistro;
}
char * LeerCadena(ifstream &arch, char c){
    char Cadena[110],*PtrCadena;
    arch.getline(Cadena,100,c);
    PtrCadena = new char[strlen(Cadena)+1];
    strcpy(PtrCadena,Cadena);
    return PtrCadena;
}
void IncrementarEspacios(void **&Productos,int &nDatos,int &cap){
    void **ArrProd = (void**)Productos;
    cap += INCREMENTO;
    if(Productos == nullptr){
        ArrProd = new void *[cap]{};
        nDatos++;
    }else{
        void **AuxProd = new void *[cap]{};
        for(int i=0;i<nDatos;i++){
            AuxProd[i] = ArrProd[i];
        }
        delete ArrProd;
        ArrProd = AuxProd;
    }
    Productos = ArrProd;
}
void pruebaDeCargaDeProductos(void *Productos){
    void **ArrProductos = (void **)Productos;
    ofstream arch("ReporteProductos.txt");
    arch.precision(2);
    arch<<fixed;
    for(int i=0;ArrProductos[i];i++){
        imprimirRegistro(arch,ArrProductos[i]);
    }
}
void imprimirRegistro(ofstream &arch,void *Producto){
    void **DatosProducto = (void**)Producto;
    void **Datos = (void **) DatosProducto[DATO];
    char *Cod = (char*)Datos[COD];
    char *descripcion = (char*)Datos[DESC];
    double *precio = (double*)Datos[PRECIO];
    int *stock = (int*)Datos[STOCK];
    arch<<left<<setw(10)<<Cod<<setw(65)<<descripcion<<setw(10)<<*precio<<*stock<<endl;
}
int cmpCodProd(const void *a,const void *b){
    void **ai = (void **)a, **bi=(void **)b;
    void **RegA= (void **)(*ai), **RegB=(void **)(*bi);
    void **DatosA= (void **)(RegA[DATO]), **DatosB=(void **)(RegB[DATO]);
    char *CodA = (char*)(DatosA[COD]), *CodB = (char*)(DatosB[COD]);
    return strcmp(CodA,CodB);
}
void OrdenarProductos(void *Productos){
    void **ArrProd = (void**)Productos;
    int ndatos=0;
    while(ArrProd[ndatos])ndatos++;
    qsort(Productos,ndatos,sizeof(void*),cmpCodProd);
}
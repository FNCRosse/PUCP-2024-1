/* 
 * File:   Pregunta01Examen01PunterosMultiples.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 11:16
 */
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pregunta01Examen01PunterosMultiples.h"
#define INCREMENTO 5
enum RegPed {FECHA,DNI,CANTIDAD};

void cargarPedidos (int **&FechaClienteCantidad, char **&CodProducto, const char *namefile){
    ifstream arch (namefile);
    FechaClienteCantidad  = nullptr;
    CodProducto = nullptr;
    int nDatos=0,cap=0;
    char *Codigo;
    while(true){
        Codigo = LeerCadena(arch,',');
        if(arch.eof()) break;
        if(nDatos == cap) aumentarEspacios(FechaClienteCantidad,CodProducto,nDatos,cap);
        FechaClienteCantidad[nDatos-1] = leeRegistro(arch);
        CodProducto[nDatos-1] = Codigo;
        nDatos++;
    }
}
char * LeerCadena(ifstream &arch,char c){
    char Cadena[60],*PtrCadena;
    arch.getline(Cadena,60,c);
    PtrCadena = new char[strlen(Cadena)+1];
    strcpy(PtrCadena,Cadena);
    return PtrCadena;
}
void pruebaDeCargaDePedidos (int **FechaClienteCantidad, char **CodProducto, const char *namefile){
    ofstream arch (namefile);
    arch<<right<<setw(6)<<"FECHA"<<setw(12)<<"DNI"<<setw(17)<<"CODIGO"<<setw(14)<<"CANT"<<endl;
    for(int i=0; CodProducto[i];i++){
        imprimePedido(arch,FechaClienteCantidad[i],CodProducto[i]);
    }
}
int * leeRegistro(ifstream &arch){
    int *Registro = new int [3];
    int dni, cant, dia,mes,anio;
    char c;
    arch>>dni>>c>>cant>>c>>dia>>c>>mes>>c>>anio;
    arch.get();
    Registro[FECHA]=anio*10000+mes*100+dia;
    Registro[DNI] = dni;
    Registro[CANTIDAD] = cant;
    return Registro;
}
void aumentarEspacios(int **&FechaClienteCantidad, char **&CodProducto, int &ndatos, int &cap){
    cap += INCREMENTO;
    if(FechaClienteCantidad == nullptr){
        FechaClienteCantidad = new int*[cap]{};
        CodProducto = new char*[cap]{};
        ndatos =1;
    } else {
        int** AuxFCC = new int*[cap]{};
        char **AuxCodProducto = new char*[cap]{};
        for(int i=0;i<ndatos;i++){
            AuxFCC[i] = FechaClienteCantidad[i];
            AuxCodProducto[i]  = CodProducto[i];
        }
        delete FechaClienteCantidad;
        delete CodProducto;
        FechaClienteCantidad = AuxFCC;
        CodProducto = AuxCodProducto;
    }
}
void imprimePedido(ofstream &arch,int *DatosCliente,char *CodProd){
    arch<<left<<setw(15)<<DatosCliente[FECHA]<<setw(15)<<DatosCliente[DNI]<<setw(15)<<CodProd
            <<DatosCliente[CANTIDAD]<<endl;
}
void OrdenarPedidos(int **FechaClienteCantidad,char **CodigoDelProducto){
    int nDatos=0;
    while(FechaClienteCantidad[nDatos])nDatos++;
    mergesort(FechaClienteCantidad,CodigoDelProducto,0,nDatos-1);
}
void mergesort(int **FechaClienteCantidad,char **CodigoDelProducto,int inicio,int fin){
    if(inicio == fin) return;
    int med = (inicio+fin)/2;
    mergesort(FechaClienteCantidad,CodigoDelProducto,inicio,med);
    mergesort(FechaClienteCantidad,CodigoDelProducto,med+1,fin);
    merge(FechaClienteCantidad,CodigoDelProducto,inicio,med,fin);
}
void merge(int **FechaClienteCantidad,char**CodigoDelProducto,int inicio,int med,int fin){
    int i,p,q;
    int long1 = (med+1)-inicio; 
    int long2 = fin -med;
    int **P1 = new int *[long1+1],**Q1 = new int *[long2+1];
    char **P2 = new char *[long1+1], **Q2= new char *[long2+1];
    AsignarValores(P1[long1],Q1[long2]);
    for(i=inicio;i<med+1;i++){
        P1[i-inicio] = FechaClienteCantidad[i];
        P2[i-inicio] = CodigoDelProducto[i];
    }
    for(i=med+1;i<=fin;i++){
        Q1[i-(med+1)] = FechaClienteCantidad[i];
        Q2[i-(med+1)] = CodigoDelProducto[i];
    }
    p=q=0;
    for(i=inicio;i<=fin;i++){
        if(Mayor(P1[p],Q1[q])){
            FechaClienteCantidad[i] = P1[p];
            CodigoDelProducto[i] = P2[p];
            p++;
        } else {
            FechaClienteCantidad[i] = Q1[q];
            CodigoDelProducto[i] = Q2[q];
            q++;
        }
    }
}
bool Mayor(int *P1, int *Q1){
    if(P1[FECHA]<Q1[FECHA]) return true;
    else return false;
}
void AsignarValores (int *&P1, int *&Q1){
    P1 = new int [3];
    Q1 = new int [3];
    P1[FECHA] = 99999999;
    Q1[FECHA] = 99999999;
}
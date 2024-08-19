/* 
 * File:   Funciones.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de abril de 2024, 21:39
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Funciones.h"
enum Nodo {DATO,SIG};
enum Reg {COD,NOM,SUE};

void CrearLista(const char* namefile,void *&Lista,void *(*lee)(ifstream &),
        int (*cmp)(const void*, const void*)){
    ifstream arch ( namefile);
    void *Dato;
    Lista = nullptr;
    while(true){
        Dato = lee(arch);
        if(arch.eof()) break;
        insertar(Dato,Lista,cmp);
    }
}
void insertar(void *dato, void*&Lista, int(*cmp)(const void*, const void*)){
    void **arrLista = (void**)Lista;
    void **ant = nullptr;
    void **nuevo;
    nuevo = new void*[2];
    nuevo[DATO] = dato;
    while (arrLista) {
        if(cmp(arrLista[DATO],dato)>0) break;
        ant = arrLista;
        arrLista = (void**)(arrLista[SIG]);
    }
    nuevo[SIG] = arrLista;
    if(ant == nullptr){
        Lista = nuevo;
    } else {
        ant[SIG] = nuevo;
    }

}
void ImprimirLista(void *List,void (*imprime)(void*)){
    void **Lista = (void**)List;
    while(Lista){
        imprime(Lista[DATO]);
        Lista = (void**) (Lista[SIG]);
    } 
    cout<<endl;
}
void EliminarLista(void *List,void (*elimina)(void*)){
    void **Lista = (void**)List, **Eliminar;
    while(Lista){
        Eliminar = Lista;
        elimina(Lista[DATO]);
        Lista = (void**) (Lista[SIG]);
        delete Eliminar;
    } 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7777
void *leeReg (ifstream &arch){
    void **Registro = new void*[3];
    int * cod = new int;
    char * nombre, cadena[60];
    double *sueldo = new double;
    arch>>*cod;
    if(arch.eof()) return nullptr;
    arch.get();
    arch.getline(cadena,60,',');
    nombre = new char[strlen(cadena)+1];
    strcpy(nombre,cadena);
    arch>>*sueldo;
    Registro[COD] = cod;
    Registro[NOM] = nombre;
    Registro[SUE] = sueldo;
    return Registro;
}
int regNombCMP(const void* a, const void*b){
    void **regI = (void**)a, **regk = (void**)b;
    char *NombI=(char*)regI[NOM], *NombK = (char*)regk[NOM];
    return strcmp (NombI,NombK);
}
int regCodCMP(const void*a, const void*b){
    void **regI = (void**)a, **regk = (void**)b;
    int *codI=(int*)regI[COD], *CodK = (int*)regk[COD];
    return *codI - *CodK;
}
int regSueldoCMP(const void*a, const void* b){
    void **regI = (void**)a, **regk = (void**)b;
    double*SueldoI=(double*)regI[SUE], *SueldoK = (double*)regk[SUE];
    return *SueldoI - *SueldoK;
}
void ImprimeReg(void*a){
    void **Reg = (void**)a;
    int* codigo = (int*)Reg[COD];
    char*nombre = (char*)Reg[NOM];
    double*sueldo = (double*)Reg[SUE];
    cout.precision(2);
    cout<<fixed;
    cout<<setw(10)<<*codigo<<" "<<left<<setw(50)<<nombre<<right<<setw(10)
    <<*sueldo<<endl;
    }
void EliminaReg(void*a){
    void **reg = (void**)a; //apuntamos al registro
    int* codigo = (int*)reg[COD];
    char*nombre = (char*)reg[NOM];
    double*sueldo = (double*)reg[SUE];
    delete codigo;
    delete nombre;
    delete sueldo;
    delete reg;

}
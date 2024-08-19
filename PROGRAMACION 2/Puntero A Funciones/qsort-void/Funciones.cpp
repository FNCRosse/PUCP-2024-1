/* 
 * File:   Funciones.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de abril de 2024, 18:12
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Funciones.h"
enum Registro {CODIGO,NOMBRE,SUELDO};

void LeerDatos(void *&Personal,int& nd,const char* namefile){
    ifstream arch(namefile);
    void **ArrPersonal,*registro,*Buff[20];
    nd=0;
    while(true){
        registro = LeerRegistro(arch);
        if(arch.eof()) break;
        Buff[nd] = registro;
        nd++;
    }
    ArrPersonal = new void *[nd];
    for(int i=0;i<nd;i++)ArrPersonal[i] = Buff[i];
    Personal = ArrPersonal;
}
void *LeerRegistro(ifstream &arch){
    void **Registro = new void*[3];
    char *nomb;
    int * cod = new int;
    double *sueld = new double;
    arch>>*cod;
    if(arch.eof()) return nullptr;
    arch.get();
    nomb = LeerCadena(arch,',');
    arch>>*sueld;
    arch.get();
    Registro[CODIGO] = cod;
    Registro[NOMBRE] = nomb;
    Registro[SUELDO] = sueld;
    return Registro;
}
char* LeerCadena(ifstream &arch,char c){
    char cadena[100],*ptrcadena;
    arch.getline(cadena,100,c);
    ptrcadena = new char [strlen(cadena)+1];
    strcpy(ptrcadena,cadena);
    return ptrcadena;
}
void ImprimirDatos(void *Personal,int nd){
    void **ArrPer = (void**)Personal;
    for(int i=0;i<nd;i++){
        ImprimirRegistro(ArrPer[i]);
    }
}
void ImprimirRegistro(void *reg){
     void **Datos = (void**)reg;
     int * Codigo = (int*)Datos[CODIGO];
     char * Nombre = (char*)Datos[NOMBRE];
     double * sueldo = (double*)Datos[SUELDO];
     cout.precision(2);
     cout<<fixed;
     cout<<left<<setw(10)<<*Codigo<<setw(45)<<Nombre<<*sueldo<<endl;
}

//Funciones que van ser llamadas para la compraracion del qsort
int voidCMPSueldo(const void *a, const void *b){
    void **ai=(void**)a, **bi = (void**)b;
    void **regA =(void**)(*ai), **regB = (void**)(*bi); //Abrir el registro de ai y bi
    //sacar lo que quiero comparar
    double *SueldoA = (double*) (regA[SUELDO]), *SueldoB = (double*) (regB[SUELDO]);
    return *SueldoA - *SueldoB;
}
int voidCMPCodigo(const void *a, const void *b){
     void **ai=(void**)a, **bi = (void**)b;
    void **regA =(void**)(ai[0]), **regB = (void**)(*bi); //Abrir el registro de ai y bi
    //sacar lo que quiero comparar
    int* codA=(int*)(regA[CODIGO]), *codB = (int*)(regB[CODIGO]);
    return *codA - *codB;
}
int voidCMPNombres(const void *a, const void *b){
     void **ai=(void**)a, **bi = (void**)b;
    void **regA =(void**)(ai[0]), **regB = (void**)(*bi); //Abrir el registro de ai y bi
    //sacar lo que quiero comparar
    char* nombA=(char*)(regA[NOMBRE]), *nombB = (char*)(regB[NOMBRE]);
    return strcmp(nombA,nombB);
}


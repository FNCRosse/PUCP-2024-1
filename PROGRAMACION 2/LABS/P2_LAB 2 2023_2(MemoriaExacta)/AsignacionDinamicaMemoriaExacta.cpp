/* 
 * File:   AsignacionDinamicaMemoriaExacta.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 10 de abril de 2024, 12:54
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

char* LeerCadena(ifstream &arch){
    char cadena[60],*ptrCad;
    arch.getline(cadena,60,',');
    ptrCad = new char [strlen(cadena)+1];
    strcpy(ptrCad,cadena);
    return ptrCad;
}
char** LeerProducto(ifstream &arch){
    char **Producto = new char *[2];
    Producto[0] = LeerCadena(arch);
    Producto[1] = LeerCadena(arch);
    return Producto;
}
void LecturaDeProducto(const char*  namefile,char ***&Producto,int *&Stock,double *&precios){
    ifstream arch(namefile,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    char **BuffProductos[200],extra;
    int BuffStock[200],numDatos=0;
    double BuffPrecios[200];
    while(true){
        BuffProductos[numDatos] = LeerProducto(arch);
        if(arch.eof()) break;
        arch>>BuffPrecios[numDatos]>>extra>>BuffStock[numDatos];
        arch.get();
        numDatos++;
    }
    Producto = new char **[numDatos+1]{};
    Stock = new int [numDatos +1]{};
    precios = new double[numDatos+1]{};
    
    for(int i=0;i<numDatos;i++){
        Producto[i] = BuffProductos[i];
        Stock[i] = BuffStock[i];
        precios[i] = BuffPrecios[i];
    }
}
void pruebaDeLecturaDeProductos(const char*  namefile,char ***Producto,int *Stock,double *precios){
    ofstream arch(namefile,ios::out);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    char **DatosPr;
    for(int i=0; Producto[i];i++){
        DatosPr = Producto[i];
        arch<<left<<setw(10)<<DatosPr[0]<<setw(60)<<DatosPr[1]<<setw(10)<<precios[i]<<Stock[i]<<endl;
    }
}
void LecturaDePedido(const char*  namefile,int *&fechaPedidos,char ***&CodidoPedido,int ***&dniCantPedido){
    ifstream arch(namefile,ios::in);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    int BuffFecha[600]{}, **BuffDCP[600]{},numDatos=0,dni,cant,fecha,PosFecha,numCodP[600]{},numDCP[600]{};
    char **BuffCodP[600]{},*codigo,extra;
    while(true){
        codigo = LeerCadena(arch);
        if(arch.eof()) break;
        arch>>dni>>extra>>cant>>extra;
        fecha = LeerFecha(arch);
        PosFecha = BuscarFecha(BuffFecha,fecha);
        if(PosFecha != -1){// si lo encontro
            BuffFecha[PosFecha] =fecha;
            BuffCodP[PosFecha] = colocarCodigo(codigo,numCodP[PosFecha],BuffCodP[PosFecha]);
            BuffDCP[PosFecha] = colocarDNI(dni,cant,numDCP[PosFecha],BuffDCP[PosFecha]);
        }
        else{//Si es nuevo
            BuffFecha[numDatos] =fecha;
            BuffCodP[numDatos] = colocarCodigo(codigo,numCodP[numDatos],BuffCodP[numDatos]);
            BuffDCP[numDatos] = colocarDNI(dni,cant,numDCP[numDatos],BuffDCP[numDatos]);
            numDatos++;
        }
    }
    fechaPedidos = new int [numDatos+1]{};
    CodidoPedido = new char **[numDatos+1]{};
    dniCantPedido = new int**[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        fechaPedidos[i] = BuffFecha[i];
        CodidoPedido[i] = BuffCodP[i];
        dniCantPedido[i] = BuffDCP[i];
    }
}
int LeerFecha(ifstream &arch){
    char extra;
    int dia,mes, anio;
    arch>>dia>>extra>>mes>>extra>>anio;
    arch.get();
    return anio*10000+mes*100+dia;
}
int BuscarFecha(int *BuffFecha,int fecha){
    for(int i=0;BuffFecha[i];i++){
        if(BuffFecha[i] == fecha) return i;
    }
    return -1;
}
char** colocarCodigo(char *codigo,int &numCodP,char **&BuffCodP){
    char *buff[500]{},**Aux;
    if(numCodP == 0 ){
        buff[0] = new char [strlen(codigo)+1];
        strcpy(buff[0],codigo);
        numCodP++;
    }
    else{
        for(int i=0;i<numCodP;i++){
            buff[i] = BuffCodP[i];
        }
        delete BuffCodP;
        buff[numCodP] = new char [strlen(codigo)+1];
        strcpy(buff[numCodP],codigo);
        numCodP++;
    }
    Aux = new char *[numCodP+1]{};
    for(int i=0;i<numCodP;i++){
        Aux[i] = buff[i];
    }
    return Aux;
}
void AgregarDCP(int *&buff,int dni,int cant){
    buff[0] = dni;
    buff[1] = cant;
}
int ** colocarDNI(int dni,int cant,int &numDCP,int**&BuffDCP){
    int *buff[500]{},**Aux,*buffArreglo;
    if(numDCP == 0 ){
        buff[0] =new int [2];
        AgregarDCP(buff[0],dni,cant);
        numDCP++;
    }
    else{
        for(int i=0;i<numDCP;i++){
            buff[i] = BuffDCP[i];
        }
        delete BuffDCP;
        buff[numDCP] = new int [2];
        AgregarDCP(buff[numDCP],dni,cant);
        numDCP++;
    }
    Aux = new int *[numDCP+1]{};
    for(int i=0;i<numDCP;i++){
        Aux[i] = buff[i];
    }
    return Aux; 
}
void pruebaDeLecturaDePedidos(const char*  namefile,int *fechaPedidos,char ***CodidoPedido,int ***dniCantPedido){
    ofstream arch(namefile,ios::out);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    char **CodPed;
    int **DCP,*arrgloDCP;
    for(int i=0; fechaPedidos[i];i++){
        CodPed = CodidoPedido[i];
        DCP = dniCantPedido[i];
        arch<<fechaPedidos[i]<<endl;
        for(int j=0;CodPed[j];j++){
            arrgloDCP = DCP[j];
            arch<<left<<setw(10)<<CodPed[j]<<setw(15)<<arrgloDCP[0]<<arrgloDCP[1]<<endl;
        }
    }
}
    
void ReporteDeEnvioDePedidos(const char*  namefile,char ***Producto,int *&Stock,double *precios,
        int *fechaPedidos,char ***CodidoPedido,int ***dniCantPedido){
    ofstream arch(namefile,ios::out);
    if(!arch.is_open()){
        cout<<"El archivo "<<namefile<<" no se abrio"<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    double montoIng=0, montoPer=0;
    arch<<right<<setw(60)<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    for(int i=0; fechaPedidos[i];i++){
        HacerLinea(arch,'=',160);
        arch<<"FECHA: "<<fechaPedidos[i]<<endl;
        HacerLinea(arch,'=',160);
        arch<<left<<setw(5)<<"No."<<setw(22)<<"DNI"<<setw(59)<<"Producto"<<setw(14)<<"Cantidad"<<setw(12)
                <<"Precio"<<"Total de ingresos"<<endl;
        HacerLinea(arch,'-',160);
        imprimirPedidos(dniCantPedido[i],CodidoPedido[i],Producto,precios,Stock,arch,montoIng,montoPer);
        HacerLinea(arch,'-',160);
        arch<<"Total ingresado: "<<montoIng<<endl;
        arch<<"Total perdido por falta de stock: "<<montoPer<<endl;
        HacerLinea(arch,'=',160);
    }
}
void imprimirPedidos(int **dniCantPedido,char **CodidoPedido,char ***Producto,double *precios,int *&Stock,
        ofstream &arch,double &montoIng,double &montoPer){
    int *ArrDCP,posProd;
    for(int i=0;dniCantPedido[i];i++){
        ArrDCP = dniCantPedido[i];
        arch<<right<<setw(2)<<i+1<<")"<<setw(10)<<ArrDCP[0];
        posProd = BuscarProducto(Producto,CodidoPedido[i]);
        char **DatosPr = Producto[posProd];
        arch<<setw(12)<<DatosPr[0]<<left<<"  "<<setw(60)<<DatosPr[1]<<right<<setw(3)<<ArrDCP[1]<<setw(16)<<
                precios[posProd]<<setw(18);
        if(Stock[posProd] > 0){
            arch<<ArrDCP[1]*precios[posProd]<<endl;
            montoIng += ArrDCP[1]*precios[posProd];
            Stock[posProd] -=ArrDCP[1];
        }
        else{
            arch<<"SIN STOCK"<<endl;
            montoPer += ArrDCP[1]*precios[posProd];
        }
    }
}
void HacerLinea(ofstream &arch, char letra, int cant){
    for(int i=0;i<cant;i++) arch<<letra;
    arch<<endl;
}
int BuscarProducto(char ***Producto,char *CodidoPedido){
    char **DatosPr;
    for(int i=0;Producto[i];i++){
        DatosPr = Producto[i];
        if(strcmp(CodidoPedido,DatosPr[0])==0) return i;
    }
    return -1;
}


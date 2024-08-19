/* 
 * File:   AsignacionDinamicaMemoriaExacta.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 17 de abril de 2024, 14:44
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"

void LecturaDeLibros(const char *namefile,char ***&Libros,int**&stock){
    ifstream arch(namefile,ios::in);
    int nDatos=0;
    char **BufferLibros[600]{},*codigo;
    int *BufferStock[600]{};
    while(true){
        codigo = LeerCadena(arch);
        if(arch.eof()) break;
        BufferLibros[nDatos] = LeerDatosLibro(arch,codigo);
        BufferStock[nDatos] = LeerDatosStock(arch);
        nDatos++;
    }
    Libros = new char **[nDatos+1]{};
    stock = new int *[nDatos+1]{};
    for(int i=0;i<nDatos;i++){
        Libros[i] = BufferLibros[i];
        stock[i] = BufferStock[i];
    }
}
void PruebaDeLecturaDeLibros(const char *namefile,char***Libros,int **stock){
    ofstream arch(namefile,ios::out);
    char **DatosLibro; int *DatosStock;
    for(int i=0;Libros[i];i++){
        DatosLibro = Libros[i];
        DatosStock = stock[i];
        arch<<left<<setw(10)<<DatosLibro[0]<<setw(60)<<DatosLibro[1]<<setw(40)<<DatosLibro[2]<<setw(5)<<
                DatosStock[0]<<DatosStock[1]<<endl;           
    }
}
    
void AtencionDePedidos(const char *namefile,char ***Libros,int **&stock,int **&PedidosClientes,
                                            char ***&PedidosLibros,bool **&PedidosAtendidos){
    ifstream arch(namefile,ios::in);
    int *BuffClientes[600]{}, nClientes=0,nPedidos=0, numPedido,dni, posCliente,NDCliente[600]{};
    char **BuffLibros[600]{}, coma,**LibroPedidos;
    bool *BuffAtendidos[600]{};
    while(true){
        arch>>numPedido;
        if(arch.eof()) break;
        arch>>coma>>dni;
        LibroPedidos = LeerLibrosDelPedido(arch);
        posCliente = BuscarCliente(BuffClientes,dni);
        if(posCliente != -1){
            BuffClientes[posCliente] = ColocarCliente(dni,numPedido,BuffClientes[posCliente],NDCliente[posCliente]);
        }else{
            BuffClientes[nClientes] = ColocarCliente(dni,numPedido,BuffClientes[nClientes],NDCliente[nClientes]);
            nClientes++;
        }
        BuffLibros[numPedido-1] = LibroPedidos;
        BuffAtendidos[numPedido-1] = ColocarLibrosAtendidos(BuffLibros[numPedido-1],Libros,stock);
        nPedidos++;
    }
    PedidosClientes = new int *[nClientes+1]{};
    PedidosLibros = new char **[nPedidos+1]{};
    PedidosAtendidos = new bool *[nPedidos+1]{};
    for(int i=0;i<nClientes;i++) {
        PedidosClientes[i] =BuffClientes[i];
    }
    for(int i=0;i<nPedidos;i++){
        PedidosLibros[i] = BuffLibros[i];
        PedidosAtendidos[i] = BuffAtendidos[i];
    }
} 

void ReporteDeEnvioDePedidos(const char *namefile,int **PedidosClientes,char ***PedidosLibros,
        bool **PedidosAtendidos){
    ofstream arch(namefile,ios::out);
    arch<<right<<setw(60)<<"REPORE DE ATENCION DE PEDIDOS"<<endl;
    int *DatosCliente;
    for(int i=0;PedidosClientes[i];i++){
        DatosCliente = PedidosClientes[i];
        ImprimirLines(arch,100,'=');
        arch<<setw(9)<<"CLIENTE:"<<DatosCliente[0]<<endl;
        ImprimirLines(arch,100,'=');
        ImprimirPedidos(DatosCliente,PedidosLibros,PedidosAtendidos,arch);
    }
}
char * LeerCadena (ifstream &arch){
    char Cadena[60],*ptrCadena;
    arch.getline(Cadena,60,',');
    ptrCadena = new char [strlen(Cadena)+1];
    strcpy(ptrCadena,Cadena);
    return ptrCadena;
}
char ** LeerDatosLibro (ifstream &arch,char* codigo){
    char ** DatosLibro = new char *[3];
    DatosLibro[0] = codigo;
    DatosLibro[1] = LeerCadena(arch);
    DatosLibro[2] = LeerCadena(arch);
    return DatosLibro;
}
int* LeerDatosStock(ifstream &arch){
    int numStock, *datosStock= new int [2];
    double precio;
    arch>>numStock; arch.get();
    arch>>precio; arch.get();
    datosStock[0] = numStock;
    datosStock[1] = 0;
    return datosStock;
}
char ** LeerLibrosDelPedido(ifstream &arch){
    char**PedLibros,*BuffAux[50]{};
    int numLibros=0;
    while(true){
        BuffAux[numLibros] = LeerCodigoLibros(arch);
        numLibros++;
        if(arch.get() == '\n') break;
    }
    PedLibros = new char*[numLibros+1]{};
    for(int i=0;i<numLibros;i++) PedLibros[i] = BuffAux[i];
    return PedLibros;
}
char * LeerCodigoLibros(ifstream &arch){
    char codigo[8], *ptrCodigo;
    arch>>codigo;
    ptrCodigo =  new char[strlen(codigo)+1];
    strcpy(ptrCodigo,codigo);
    return ptrCodigo;
}
int BuscarCliente(int **BuffClientes,int dni){
    for(int i=0;BuffClientes[i];i++){
        int *DatosCliente = BuffClientes[i];
        if(DatosCliente[0] == dni) return i;
    }
    return -1;
}
int *ColocarCliente(int dni,int numPedido,int *&BuffClientes,int &NDCliente){
    int *PedCliente,BuffAux[100]{};
    if(NDCliente == 0){
        BuffAux[0] = dni;
        BuffAux[1] = 1;
        BuffAux[2] = numPedido;
        NDCliente += 3;
    } else {
        for(int i=0;i<NDCliente;i++){
            BuffAux[i] = BuffClientes[i];
        }
        delete BuffClientes;
        BuffAux[NDCliente] = numPedido;
        BuffAux[1]++;
        NDCliente++;
    }
    PedCliente = new int [NDCliente+1]{};
    for(int i=0;i<NDCliente;i++){
        PedCliente[i] = BuffAux[i];
    }
    return PedCliente;
}
bool *ColocarLibrosAtendidos(char **BuffLibros,char ***Libros,int **&stock){
    int NumAt,posLibro,*DatosStock;
    bool *LibrosAtendidos,BuffAux[100]{};
    for(NumAt=0; BuffLibros[NumAt];NumAt++){
        posLibro = BuscarLibro(Libros,BuffLibros[NumAt]);
        DatosStock = stock[posLibro];
        if(DatosStock[0]>0){
            BuffAux[NumAt] = true;
            DatosStock[0]--;
        }
        else{
            BuffAux[NumAt] = false;
            DatosStock[0]=0;
            DatosStock[1]++;
        }
    }
    LibrosAtendidos = new bool [NumAt+1]{};
    for(int i=0;i<NumAt;i++){
        LibrosAtendidos[i] = BuffAux[i];
    }
    return LibrosAtendidos;
}
int BuscarLibro(char ***Libros,char *nomlibro){
    for(int i=0;Libros[i];i++){
        char **DatosLibros = Libros[i];
        if(strcmp(DatosLibros[0],nomlibro)==0)return i;
    }
    return -1;
}
void  ImprimirLines(ofstream &arch,int cant,char letra){
    for(int i=0;i<cant;i++) arch<<letra;
    arch<<endl;
}
void ImprimirPedidos(int *DatosCliente,char ***PedidosLibros, bool **PedidosAtendidos,ofstream &arch){
    char **DatosPedLibros;
    bool *DatosPedAte;
    int posPedido;
    for(int i=2;DatosCliente[i];i++){
        posPedido = DatosCliente[i]-1;
        DatosPedLibros = PedidosLibros[posPedido];
        DatosPedAte = PedidosAtendidos[posPedido];
        arch<<right<<setw(15)<<"Pedidos No."<<setw(20)<<"Codigo del Libro"<<setw(15)<<"Observacion"<<endl;
        ImprimirLines(arch,100,'-');
        arch<<setw(12)<<DatosCliente[i]<<setw(10)<<" ";
        for(int k=0; DatosPedLibros[k];k++){
            if(k==0) arch<<left<<setw(17)<<DatosPedLibros[k];
            else arch<<left<<setw(22)<<" "<<setw(17)<<DatosPedLibros[k];
            ImprimirObservacion(DatosPedAte[k],arch);
        }
        ImprimirLines(arch,100,'-');
    }
}
void ImprimirObservacion(bool DatosPedAte,ofstream &arch){
    if(DatosPedAte==true) arch<<"ATENDIDO"<<endl;
    else arch<<"NO ATENDIDO"<<endl;
}

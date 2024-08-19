/* 
 * File:   MetodoIncremento.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 17 de abril de 2024, 18:36
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "MetodoIncremento.h"
#define INCREMENTO 5

////////////////////////////////////////////////////////////////////// INICIO LIBROS /////////////////////////////////////////////////////////////////////////////////
void LecturaDeLibros(const char *namefile,char*** &Libros,int **&stock){
    ifstream arch (namefile,ios::in);
    int nDatos=0,Cap=0,*DatosStock;
    char *Codigo,**DatosLibro;
    Libros = nullptr;
    stock = nullptr;
    while(true){
        Codigo =LeerCadena(arch);
        if(arch.eof()) break;
        DatosLibro = LeerDatosLibro(arch,Codigo);
        DatosStock = LeerDatosStock(arch);
        if(nDatos == Cap) IncrementarEspaciosLibros(Libros,stock,nDatos,Cap);
        Libros [nDatos-1] = DatosLibro;
        stock[nDatos-1] = DatosStock;
        nDatos++;
    }
}

void PruebaDeLecturaDeLibros(const char *namefile,char*** Libros,int **stock){
     ofstream arch (namefile,ios::out);
     char **DatosLibro;
     int *DatosStock;
     for(int i=0; Libros[i];i++){
         DatosLibro = Libros[i];
         DatosStock = stock[i];
         arch<<left<<setw(10)<<DatosLibro[0]<<setw(60)<<DatosLibro[1]<<setw(45)<<DatosLibro[2]<<setw(5)<<
                 DatosStock[0]<<DatosStock[1]<<endl;
     }
}
////////////////////////////////////////////////////////////////////// FIN LIBROS/////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////// INICIO PEDIDOS /////////////////////////////////////////////////////////////////////////////////
void AtencionDePedidos(const char *namefile,char***Libros,int **&stock,int**&PedidosClientes,
        char*** &PedidosLibros,bool **&PedidoAtendidos, int *&Pedidos){
     ifstream arch (namefile,ios::in);
     int nClientes=0, CapCliente=0,nPedido=0,CapPedidos=0,*Arr_nPedCli,*Arr_CapPedCli;
     int numPedido,dni,posDni;
     char ** CodigoPedLib;
     PedidosClientes = nullptr;
     PedidosLibros = nullptr;
     PedidoAtendidos = nullptr;
     while(true){
         arch>>numPedido;
         if(arch.eof()) break;
         arch.get(); arch>> dni;
         CodigoPedLib = LeerLibroPedidos(arch);
         posDni = BuscarDni(PedidosClientes,dni);
         if(nClientes == CapCliente) IncrementarEspaciosClientes(PedidosClientes,Arr_nPedCli,Arr_CapPedCli,
                                                                                                        nClientes,CapCliente);
         if(nPedido == CapPedidos) IncrementarEspaciosPedidos(Pedidos,PedidosLibros,PedidoAtendidos,nPedido,CapPedidos);
         ColocarDatos(Pedidos,PedidosClientes,PedidosLibros,PedidoAtendidos,nClientes,nPedido,posDni,dni,numPedido,
                 Arr_nPedCli,Arr_CapPedCli,CodigoPedLib,Libros,stock);
     }
}
////////////////////////////////////////////////////////////////////// FIN PEDIDOS /////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////// INICIO ORDENAR PEDIDOS //////////////////////////////////////////////////////////////////////////////
void OrdenarPedidos(int *Pedidos,char*** PedidosLibros,bool **PedidoAtendidos){
    int n=0;
    while(Pedidos[n]) n++;
    int IndLeft=0,IndRight=n-1;
    Quick_Sort(Pedidos,PedidosLibros,PedidoAtendidos,IndLeft,IndRight);
}
void Quick_Sort(int *Pedidos,char***PedidosLibros, bool **PedidoAtendidos,int izq,int derecha){
    int pos, limite;
    if(izq >= derecha) return;
    pos = (izq + derecha)/2;
    Cambiar (Pedidos[izq],Pedidos[pos],PedidosLibros[izq],PedidosLibros[pos],
                    PedidoAtendidos[izq],PedidoAtendidos[pos]);
    limite = izq;
    for(int i=izq +1; i<=derecha ;i++){
        if (Pedidos[i]<Pedidos[izq]){
            limite++;
            Cambiar (Pedidos[limite],Pedidos[i],PedidosLibros[limite],PedidosLibros[i],
                    PedidoAtendidos[limite],PedidoAtendidos[i]);
        }
    }
    Cambiar (Pedidos[limite],Pedidos[izq],PedidosLibros[limite],PedidosLibros[izq],
                    PedidoAtendidos[limite],PedidoAtendidos[izq]);
    Quick_Sort(Pedidos,PedidosLibros,PedidoAtendidos,izq,limite-1);
    Quick_Sort(Pedidos,PedidosLibros,PedidoAtendidos,limite+1,derecha);
}
void Cambiar(int &PedA,int &PedB,char**&PedLibA,char**&PedLibB,bool *&PedAteA,bool *&PedAteB){
    int AuxPed;
    char **AuxPedLib;
    bool *AuxPedAte;
    AuxPed = PedA;
    PedA = PedB;
    PedB =AuxPed;
    
    AuxPedLib = PedLibA;
    PedLibA = PedLibB;
    PedLibB = AuxPedLib;
    
    AuxPedAte = PedAteA;
    PedAteA = PedAteB;
    PedAteB = AuxPedAte;
}
////////////////////////////////////////////////////////////////////// INICIO ORDENAR PEDIDOS /////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////// INICIO REPORTE PEDIDOS //////////////////////////////////////////////////////////////////////
void ReporteDeEntregaDePedidos(const char *namefile,int**PedidosClientes,char***PedidosLibros,
        bool **PedidoAtendidos){
    ofstream arch (namefile,ios::out);
    arch<<right<<setw(60)<<"REPORTE DE ATENCION DE PEDIDO"<<endl;
    for(int i=0; PedidosClientes[i];i++){
        int* DatosCliente = PedidosClientes[i];
        imprimirLinea(arch,100,'=');
        arch<<left<<setw(10)<<DatosCliente[0]<<endl;
        imprimirLinea(arch,100,'=');
        ImprimirPedidos(arch,DatosCliente,PedidosLibros,PedidoAtendidos);
    }
}
void  imprimirLinea (ofstream &arch,int cant,char letra){
    for(int i=0;i<cant;i++) arch<<letra;
    arch<<endl;
}
void ImprimirPedidos(ofstream &arch,int *DatosCliente,char ***PedidosLibros,bool **PedidoAtendidos){
    int PosPedido;
    for(int i=2;i<DatosCliente[1]+2;i++){
        PosPedido = DatosCliente[i]-1;
        char **DatosLibrosPed = PedidosLibros[PosPedido];
        bool *DatosPedAte = PedidoAtendidos[PosPedido];
        arch<<right<<setw(15)<<"Pedidos No."<<setw(22)<<"Codigo del Libro"<<setw(15)<<"Observacion"<<endl;
        imprimirLinea(arch,100,'-');
        arch<<right<<setw(12)<<DatosCliente[i];
        for(int k=0;DatosLibrosPed[k];k++){
            if(k == 0) arch<<left<<setw(15)<<" "<<setw(15)<<DatosLibrosPed[k];
            else arch<<left<<setw(27)<<" "<<setw(15)<<DatosLibrosPed[k];
            if(DatosPedAte[k] == true) arch<<setw(15)<<"ATENDIDO"<<endl;
            else arch<<setw(15)<<"NO ATENDIDO"<<endl;
        }
        imprimirLinea(arch,100,'-');
    }
}
///////////////////////////////////////////////////////////////// FINAL REPORTE PEDIDOS //////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////// INICIO FUNCIONES LIBROS //////////////////////////////////////////////////////////////////////
char* LeerCadena(ifstream &arch){
    char cadena[60],*ptrCadena;
    arch.getline(cadena,60,',');
    ptrCadena = new char [strlen(cadena)+1];
    strcpy(ptrCadena,cadena);
    return ptrCadena;
}
char **LeerDatosLibro(ifstream &arch,char *&Codigo){
    char **Datos = new char *[3];
    Datos[0] = Codigo;
    Datos[1] = LeerCadena(arch);
    Datos[2] = LeerCadena(arch);
    return Datos;
}
int * LeerDatosStock(ifstream &arch){
    int numStock, *DatosStock = new int [2];
    double precio;
    arch>>numStock; arch.get();
    arch>>precio; arch.get();
    DatosStock[0] = numStock;
    DatosStock[1] =0;
    return DatosStock;
}
void IncrementarEspaciosLibros(char ***&Libros,int **&stock,int &nDatos,int &Cap){
    Cap += INCREMENTO;
    if(Libros == nullptr){
        Libros = new char **[Cap]{};
        stock = new int *[Cap]{};
        nDatos = 1;
    }
    else{
        char ***AuxLibros = new char **[Cap]{};
        int **Auxstock = new int *[Cap]{};
        for(int i=0;i<nDatos;i++){
            AuxLibros[i] = Libros[i];
            Auxstock[i] = stock[i];
        }
        delete Libros;
        delete stock;
        Libros = AuxLibros;
        stock = Auxstock;
    }
}
///////////////////////////////////////////////////////////////// FIN FUNCIONES LIBROS //////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////// INICIO FUNCIONES PEDIDOS //////////////////////////////////////////////////////////////////////
char ** LeerLibroPedidos(ifstream &arch){
    char ** PedidosLibros = nullptr,*codigo;
    int NumLibros=0,CapLibros=0;
    while(true){
        codigo = LeerCodigoTXT(arch);
        if(NumLibros == CapLibros) IncrementarPedidoLibros(PedidosLibros,NumLibros,CapLibros);
        PedidosLibros[NumLibros-1] = codigo;
        NumLibros++;
        if(arch.get() == '\n') break;
    }
    char* buff[10]{};
    for(int i=0;PedidosLibros[i];i++) buff[i] = PedidosLibros[i];
    return PedidosLibros;
}
char * LeerCodigoTXT(ifstream &arch){
    char codigo[8], *ptrCadena;
    arch>>codigo;
    ptrCadena = new char [strlen(codigo)+1];
    strcpy(ptrCadena,codigo);
    return ptrCadena;
}
void IncrementarPedidoLibros(char **&PedidosLibros,int &NumLibros,int &CapLibros){
     CapLibros += INCREMENTO;
     if(PedidosLibros == nullptr){
         PedidosLibros = new char*[CapLibros]{};
         NumLibros =1;
     } else {
         char **AuxPedLibros = new char *[CapLibros]{};
         for(int i=0;i<NumLibros;i++){
             AuxPedLibros[i] = PedidosLibros[i];
         }
         delete PedidosLibros;
         PedidosLibros = AuxPedLibros;
     }
}
int BuscarDni(int **PedidosClientes,int dni){
    if (PedidosClientes == nullptr) return -1;
    for(int i=0;PedidosClientes[i];i++){
        int * DatosClientes = PedidosClientes[i];
        if(DatosClientes[0] == dni) return i;
    }
    return -1;
}
void IncrementarEspaciosClientes(int**&PedidosClientes,int *&Arr_nPedCli,int *&Arr_CapPedCli,
                                                                                                       int & nClientes, int &CapCliente){
    CapCliente += INCREMENTO;
     if(PedidosClientes == nullptr){
         PedidosClientes = new int *[CapCliente]{};
         Arr_nPedCli = new int [CapCliente]{};
         Arr_CapPedCli = new int [CapCliente]{};
         nClientes =1;
     } else {
         int **AuxPedCli = new int *[CapCliente]{};
         int *AuxNum = new int [CapCliente]{};
         int *AuxCap = new int [CapCliente]{};
         for(int i=0;i<nClientes;i++){
             AuxPedCli[i] = PedidosClientes[i];
             AuxNum[i] = Arr_nPedCli[i];
             AuxCap[i] = Arr_CapPedCli[i];
         }
         delete PedidosClientes;
         delete Arr_nPedCli;
         delete Arr_CapPedCli;
         PedidosClientes = AuxPedCli;
         Arr_nPedCli = AuxNum;
         Arr_CapPedCli = AuxCap;
     }
}
void IncrementarEspaciosPedidos(int *&Pedidos,char ***&PedidosLibros,bool **&PedidoAtendidos,int &nPedido,int &CapPedidos){
    CapPedidos +=INCREMENTO;
    if(PedidosLibros == nullptr){
        PedidosLibros = new char **[CapPedidos]{};
        PedidoAtendidos = new bool*[CapPedidos]{};
        Pedidos = new int [CapPedidos]{};
        nPedido =1;
    }
    else{
        char ***AuxLibros = new char **[CapPedidos]{};
        bool **AuxPedAte = new bool*[CapPedidos]{};
        int *AuxPed = new int [CapPedidos]{};
        for(int i=0;i<nPedido;i++){
            AuxLibros[i] =PedidosLibros[i];
            AuxPedAte[i] = PedidoAtendidos[i];
            AuxPed[i] = Pedidos[i];
        }
        delete PedidosLibros;
        delete PedidoAtendidos;
        delete Pedidos;
        PedidosLibros = AuxLibros;
        PedidoAtendidos = AuxPedAte;
        Pedidos = AuxPed;
    }
}
void ColocarDatos(int *&Pedidos,int**&PedidosClientes,char*** &PedidosLibros,bool **&PedidoAtendidos,int &nClientes,
        int &nPedido,int posDni,int dni,int numPedido,int *&Arr_nPedCli,int *&Arr_CapPedCli,
        char **CodigoPedLib,char ***Libros,int **&stock){
    if(posDni != -1){//Si ya hay cliente
         PedidosClientes[posDni] = ColocarPedidosCliente(dni,numPedido,PedidosClientes[posDni],
                                                                    Arr_nPedCli[posDni], Arr_CapPedCli[posDni]);
     }
     else{
         PedidosClientes[nClientes-1] = ColocarPedidosCliente(dni,numPedido,PedidosClientes[nClientes-1],
                                                                    Arr_nPedCli[nClientes-1], Arr_CapPedCli[nClientes-1]);
         nClientes++;
     }
    Pedidos [nPedido-1] = numPedido;
     PedidosLibros[nPedido-1] = CodigoPedLib;
     PedidoAtendidos[nPedido-1] = LeerPedAtendidos(PedidosLibros[nPedido-1],Libros,stock);
     nPedido++;
}
int* ColocarPedidosCliente(int dni,int numPedido,int *&PedidosClientes,int &nPedCli, int &CapPedCli){
    int *PedCliente = PedidosClientes;
    if(nPedCli == CapPedCli) IncrementarPedidoClientes(PedCliente,nPedCli,CapPedCli);
    if(nPedCli-1 == 0){
        PedCliente[0] = dni;
        PedCliente[1] = 1;
        PedCliente[2] = numPedido;
        nPedCli +=2;
    }
    else{
        PedCliente[nPedCli] = numPedido;
        PedCliente[1]++;
        nPedCli++;
    }
    return PedCliente;
}
void IncrementarPedidoClientes(int *&PedCliente,int &nPedCli,int &CapPedCli){
    CapPedCli += INCREMENTO;
    if(PedCliente == nullptr){
        PedCliente = new int [CapPedCli]{};
        nPedCli = 1;
    }
    else{
        int *AuxPedCliente = new int[CapPedCli]{};
        for(int i=0;i<nPedCli;i++){
            AuxPedCliente[i]  = PedCliente[i];
        }
        delete PedCliente;
        PedCliente =AuxPedCliente;
    }
}
bool * LeerPedAtendidos(char **PedidosLibros,char ***Libros,int **&stock){
    bool *PedAte=nullptr;
    int nPed=0,Cap=0, posLibro, *DatosStock;
    while(true){
        if(nPed==Cap)IncrementarPedAtendidos(PedAte,nPed,Cap);
        if(PedidosLibros[nPed-1] == nullptr) break;
        posLibro = BuscarLibro(Libros,PedidosLibros[nPed-1]);
        DatosStock = stock[posLibro];
        if(DatosStock[0] >0){
            PedAte[nPed-1] = true;
            DatosStock[0]--;
        }else{
            PedAte[nPed-1] = false;
            DatosStock[0]=0;
            DatosStock[1]++;
        }
        nPed++;
    }
    return PedAte;
}
void IncrementarPedAtendidos(bool *&PedAte,int &nPed,int &Cap){
    Cap += INCREMENTO;
     if(PedAte == nullptr){
         PedAte = new bool [Cap]{};
         nPed =1;
     } else {
         bool *AuxPedAt = new bool [Cap]{};
         for(int i=0;i<nPed;i++){
             AuxPedAt[i] = PedAte[i];
         }
         delete PedAte;
         PedAte = AuxPedAt;
     }
}
int BuscarLibro(char ***Libros,char *PedLibros){
    for(int i=0;Libros[i];i++){
        char **DatosLibro = Libros[i];
        if(strcmp(DatosLibro[0],PedLibros)==0) return i;
    }
    return -1;
}
///////////////////////////////////////////////////////////////// FIN FUNCIONES PEDIDO //////////////////////////////////////////////////////////////////////
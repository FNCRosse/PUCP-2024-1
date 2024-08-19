/* 
 * File:   PunteroGenerico.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 18:34
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "PunteroGenerico.h"
enum reg_Libros{CODIGO,TITULO,AUTOR,CANTIDAD,PRECIO};
enum reg_Clientes{DNI,NOMBRE};
enum reg_PedidoLibro{CODIGOL,TITULOL};
enum reg_Pedidos{NUMPED,DNICLIENTE,NOMBRECLIENTE,PEDLIBROS,CANTLIBROS};

void LeerLibros(void *&Libros,const char*Namefile){
    ifstream arch (Namefile);
    void **ArrLibros, *Buff[300]{},*Registro;
    int NDatos =0;
    while(true){
        Registro = LeerRegistroLibro(arch);
        if(arch.eof()) break;
        Buff[NDatos]= Registro;
        NDatos++;
    }
    ArrLibros = new void *[NDatos+1]{};
    for(int i=0;i<NDatos;i++) ArrLibros[i] = Buff[i];
    Libros = ArrLibros;
}
void *LeerRegistroLibro(ifstream &arch){
    void **Registro = new void *[5];
    char *Codigo,*Titulo,*Autor,extra;
    int *cantidad=new int;
    double *Precio = new double;
    Codigo = LeerCadena(arch,',');
    if(arch.eof()) return nullptr;
    Titulo = LeerCadena(arch,',');
    Autor = LeerCadena(arch,',');
    arch>>*cantidad>>extra>>*Precio;
    arch.get();
    Registro[CODIGO] = Codigo;
    Registro[TITULO] = Titulo;
    Registro[AUTOR] = Autor;
    Registro[CANTIDAD] = cantidad;
    Registro[PRECIO] = Precio;
    return Registro;
}
char* LeerCadena(ifstream &arch,char letra){
    char cadena[100],*PtrCadena;
    arch.getline(cadena,100,letra);
    PtrCadena = new char [strlen(cadena)+1];
    strcpy(PtrCadena,cadena);
    return PtrCadena;
}
void ImprimirLibros(void *Libros,const char*Namefile){
    ofstream arch (Namefile);
    void **ArrLibros = (void**)Libros;
    for(int i=0;ArrLibros[i];i++){
        ImprmirUnLibro(arch,ArrLibros[i]);
    }
}
void ImprmirUnLibro(ofstream &arch, void* Libro){
    void **DatoLibro = (void**)Libro;
    char* Codigo = (char*)DatoLibro[CODIGO];
    char* Titulo = (char*)DatoLibro[TITULO];
    char* Autor = (char*)DatoLibro[AUTOR];
    int* cantidad = (int*)DatoLibro[CANTIDAD];
    double* precio = (double*)DatoLibro[PRECIO];
    arch<<left<<setw(10)<<Codigo<<setw(70)<<Titulo<<setw(45)<<Autor<<setw(5)<<*cantidad<<*precio<<endl;
}

void LeerClientes(void *&Clientes,const char*Namefile){
    ifstream arch (Namefile);
    void **ArrClientes, *Buff[300]{},*Registro;
    int NDatos =0;
    while(true){
        Registro = LeerRegistroCliente(arch);
        if(arch.eof()) break;
        Buff[NDatos]= Registro;
        NDatos++;
    }
    ArrClientes = new void *[NDatos+1]{};
    for(int i=0;i<NDatos;i++) ArrClientes[i] = Buff[i];
    Clientes = ArrClientes;
}
void *LeerRegistroCliente(ifstream &arch){
    void **Registro = new void *[2];
    char *Nombre;
    int *Dni=new int;
    arch>>*Dni;
    if(arch.eof()) return nullptr;
    arch.get();
    Nombre = LeerCadena(arch,'\n');
    Registro[DNI] = Dni;
    Registro[NOMBRE] = Nombre;
    return Registro;
}
void ImprimirClientes(void *Clientes,const char*Namefile){
    ofstream arch (Namefile);
    void **ArrClientes = (void**)Clientes;
    for(int i=0;ArrClientes[i];i++){
        ImprmirUnCliente(arch,ArrClientes[i]);
    }
}
void ImprmirUnCliente(ofstream &arch, void* Cliente){
    void **DatoCliente = (void**)Cliente;
    int* dni = (int*)DatoCliente[DNI];
    char* Nombre = (char*)DatoCliente[NOMBRE];
    arch<<left<<setw(14)<<*dni<<Nombre<<endl;
}

void LeerPedidos(void*Libros,void *Clientes,void *&Pedidos,const char*Namefile){
     ifstream arch (Namefile);
    void **ArrPedidos, *Buff[300]{},*Registro;
    int NDatos =0;
    while(true){
        Registro = LeerRegistroPedido(arch,Libros,Clientes);
        if(arch.eof()) break;
        Buff[NDatos]= Registro;
        NDatos++;
    }
    ArrPedidos = new void *[NDatos+1]{};
    for(int i=0;i<NDatos;i++) ArrPedidos[i] = Buff[i];
    Pedidos = ArrPedidos;
}
void *LeerRegistroPedido(ifstream &arch,void*Libros,void *Clientes){
    void **Registro = new void *[5],*PedidoLibros;
    int *Numpedido=new int, *DniC=new int,*CantLibros=new int, numLibros;
    char* NombreC;
    arch>>*Numpedido;
    if(arch.eof()) return nullptr;
    arch.get();
    arch>>*DniC;
    PedidoLibros = LeerPedidoLibros(arch,numLibros,Libros);
    NombreC = BuscarNombreCliente(Clientes,DniC);
    *CantLibros = numLibros;
    Registro[NUMPED] = Numpedido;
    Registro[DNICLIENTE] = DniC;
    Registro[NOMBRECLIENTE] = NombreC;
    Registro[PEDLIBROS] = PedidoLibros;
    Registro[CANTLIBROS] = CantLibros;
    return Registro;
}
void * LeerPedidoLibros(ifstream &arch,int &numLibros,void *Libros){
    void **PedidoLibro,*Buff[10]{},*RegPedido;
    numLibros =0;
    while(true){
        RegPedido = LeerUnPedido(arch,Libros);
        Buff[numLibros] = RegPedido;
        numLibros++;
        if(arch.get() == '\n') break;
    }
    PedidoLibro = new void *[numLibros+1]{};
    for(int i=0;i<numLibros;i++) PedidoLibro[i] = Buff[i];
    return PedidoLibro;
}
void *LeerUnPedido(ifstream &arch, void *Libros){
    void **Pedido = new void *[2];
    char* Codigo  = LeerCodigoLibro(arch);
    char * titulo = BuscarTituloLibro(Codigo,Libros);
    Pedido[CODIGOL] = Codigo;
    Pedido[TITULOL] = titulo;
    return Pedido;
}
char * LeerCodigoLibro(ifstream &arch){
    char codigo[8],*ptrCodigo;
    arch>>codigo;
    ptrCodigo = new char[strlen(codigo)+1];
    strcpy(ptrCodigo,codigo);
    return ptrCodigo;
}
char *BuscarTituloLibro(char *codigoLibro,void *Libros){
    void **ArrLibros = (void **)Libros;
    char*TituloLibro;
    for(int i=0;ArrLibros[i];i++){
        if(EncontroLibro(ArrLibros[i],codigoLibro)){
            TituloLibro = ObtenerTituloLibro(ArrLibros[i]);
            break;
        }
    }
    return TituloLibro;
}
bool EncontroLibro(void *Libro,char* CodLibro){
    void **DatosLibro=(void**)Libro;
    char* codigo = (char*)DatosLibro[CODIGO];
    if(strcmp(CodLibro,codigo)==0) return true;
    else return false;
}
char* ObtenerTituloLibro(void *Libro){
    void **DatosLibro=(void**)Libro;
    char* Titulo = (char*)DatosLibro[TITULO];
    return Titulo;
}
char * BuscarNombreCliente(void *Clientes,int *DniC){
    void **ArrClientes = (void **)Clientes;
    char*NombreC = nullptr;
    for(int i=0;ArrClientes[i];i++){
        if(EncontroCliente(ArrClientes[i],DniC)){
            NombreC = ObtenerNombreCliente(ArrClientes[i]);
            break;
        }
    }
    return NombreC;
}
bool EncontroCliente(void *Cliente,int *DniC){
    void **DatosCliente=(void**)Cliente;
    int* DniCliente = (int*)DatosCliente[DNI];
    return *DniCliente == *DniC;
}
char * ObtenerNombreCliente(void *Cliente){
    void **DatosCliente=(void**)Cliente;
    char* Nombre = (char*)DatosCliente[NOMBRE];
    return Nombre;
}
void ImprimirPedidos(void *Pedidos,const char*Namefile){
    ofstream arch (Namefile);
    void **ArrPedidos = (void**)Pedidos;
    for(int i=0;ArrPedidos[i];i++){
        ImprmirUnPedido(arch,ArrPedidos[i]);
    }
}
void ImprmirUnPedido(ofstream &arch,void *Pedido){
     void **DatoPedido = (void**)Pedido;
    int* numPed = (int*)DatoPedido[NUMPED];
    int* DNi = (int*)DatoPedido[DNICLIENTE];
    char* Nombre = (char*)DatoPedido[NOMBRECLIENTE];
    void* PedLibros = (void*)DatoPedido[PEDLIBROS];
    int* CantLibros = (int*)DatoPedido[CANTLIBROS];
    arch<<left<<setw(8)<<*numPed<<setw(14)<<*DNi<<setw(40)<<Nombre<<"Cantidad Libros Pedidos: "
            <<*CantLibros<<endl;
    void **ArrPedLibros = (void**) PedLibros;
    for(int i=0;ArrPedLibros[i];i++){
        ImprimirPedidosLibros(arch, ArrPedLibros[i]);
    }
}
void ImprimirPedidosLibros(ofstream &arch, void *PedLibros){
    void **DatosPedLibros = (void **) PedLibros;
    char *Codigo = (char*)DatosPedLibros[CODIGOL];
    char *Titulo = (char*) DatosPedLibros[TITULOL];
    arch<<setw(10)<<" "<<setw(10)<<Codigo<<Titulo<<endl;
}
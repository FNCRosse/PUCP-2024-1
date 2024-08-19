/* 
 * File:   PunteroGenericos.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de abril de 2024, 14:35
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "PunteroGenericos.h"

void LeerLibro(void *&Libros,const char * namefile){
    ifstream arch (namefile);
    void **ArrLibros, *BuffLibros[300],* Registro;
    int nDatos=0;
    while(true){
        Registro = LeerRegistroLibro(arch);
        if(arch.eof()) break;
        BuffLibros[nDatos] = Registro;
        nDatos++;
    }
    ArrLibros = new void *[nDatos+1]{};
    for(int i=0;i<nDatos;i++){
        ArrLibros[i] = BuffLibros[i];
    }
    Libros = ArrLibros;
}
void *LeerRegistroLibro(ifstream &arch){
    void **Registro = new void*[5];
    char* codigo, *titulo,*autor,extra;
    int*stock = new int;
    double *Precio = new double;
    codigo = LeerCadena(arch,',');
    if(arch.eof()) return nullptr;
    titulo = LeerCadena(arch,',');
    autor = LeerCadena(arch,',');
    arch>>*stock>>extra>>*Precio;
    arch.get();
    Registro[0] = codigo;
    Registro[1] = titulo;
    Registro[2] = autor;
    Registro[3] = stock;
    Registro[4] = Precio;
    return Registro;
}
char * LeerCadena(ifstream &arch,char c){
    char Cadena[100],*PtrCadena;
    arch.getline(Cadena,100,c);
    PtrCadena = new char [strlen(Cadena)+1];
    strcpy(PtrCadena,Cadena);
    return PtrCadena;
}
void ImprimirLibros(void *Libros,const char * namefile){
    ofstream arch(namefile);
    void** ArrLibros = (void **)Libros;
    for(int i=0;ArrLibros[i];i++){
        ImprimirLibro(ArrLibros[i],arch);
    }
}
void ImprimirLibro(void *ArrLibro,ofstream &arch){
    void **DatoLibro = (void**)ArrLibro;
    char* Codigo = (char*) DatoLibro[0];
    char* Titulo = (char*) DatoLibro[1];
    char* Autor = (char*) DatoLibro[2];
    int* stock = (int*) DatoLibro[3];
    double* precio = (double*) DatoLibro[4];
    arch<<left<<setw(10)<<Codigo<<setw(70)<<Titulo<<setw(40)<<Autor<<setw(10)<<*stock<<*precio<<endl;
}
void LeerCliente(void *&ClientesOriginal,const char * namefile){
    ifstream arch(namefile);
    void **ArrCliente,*Registro,*BufferCliente[60]{};
    int NDatos=0;
    while(true){
        Registro = LeerRegistroCliente(arch);
        if(arch.eof()) break;
        BufferCliente[NDatos] = Registro;
        NDatos++;
    }
    ArrCliente = new void *[NDatos+1]{};
    for(int i=0;i<NDatos;i++){
        ArrCliente[i] = BufferCliente[i];
    }
    ClientesOriginal = ArrCliente;
}
void* LeerRegistroCliente(ifstream &arch){
    void **Registro = new void*[2];
    char* Nombre;
    int * Dni= new int;
    arch>>*Dni;
    if(arch.eof()) return nullptr;
    arch.get();
    Nombre = LeerCadena(arch,'\n');
    Registro[0] = Dni;
    Registro[1] = Nombre;
    return Registro;
}
void ImprimirClientes(void *Clientes,const char * namefile){
    ofstream arch(namefile);
    void **ArrCliente = (void**)Clientes;
    for(int i=0;ArrCliente[i];i++){
        ImprimirCliente(ArrCliente[i],arch);
    }
}
void ImprimirCliente(void *Cliente,ofstream &arch){
    void **DatoCliente = (void **)Cliente;
    int *Dni= (int *)DatoCliente[0];
    char *Nombre= (char *)DatoCliente[1];
    arch<<left<<setw(40)<<Nombre<<*Dni<<endl;
}
void LeerPedidos(void *Libros,void *Clientes,void *&Pedidos,const char * namefile){
    ifstream arch(namefile);
    void **ArrPedidos, *registro, *BufferPed[200]{};
    int NPed=0;
    while(true){
        registro = LeerRegistroPedido(arch,Libros,Clientes);
        if(arch.eof()) break;
        BufferPed[NPed]= registro;
        NPed++;
    }
    ArrPedidos = new void *[NPed+1]{};
    for(int i=0;i<NPed;i++) ArrPedidos[i] = BufferPed[i];
    Pedidos = ArrPedidos;
}
void *LeerRegistroPedido(ifstream &arch,void *Libros,void *Clientes){
    void **Registro= new void *[5];
    int *NumPed = new int, *Dni=new int, *numLibros= new int, cantLibros;
    char * Nombre,***PedidoLibro;
    arch>>*NumPed;
    if(arch.eof()) return nullptr;
    arch.get();
    arch>>*Dni;
    LeerPedidosDeLibro(arch,PedidoLibro,cantLibros,Libros);
    Nombre = BuscarNomCliente(Clientes,Dni);
    *numLibros = cantLibros;
    Registro[0] = NumPed;
    Registro[1] = Dni;
    Registro[2] = Nombre;
    Registro[3] = PedidoLibro;
    Registro[4] = numLibros;
    return Registro;
}
void LeerPedidosDeLibro(ifstream &arch,char***&PedidoLibro,int &cantLibros,void *Libros){
    char **BufferPedLibro[10]{};
    cantLibros = 0;
    while(true){
        BufferPedLibro[cantLibros] = LeerDatosPedLibro(arch,Libros);
        cantLibros++;
        if(arch.get() == '\n') break;
    }
    PedidoLibro = new char **[cantLibros+1]{};
    for(int i=0;i<cantLibros;i++){
        PedidoLibro[i] = BufferPedLibro[i];
    }
}
char **LeerDatosPedLibro( ifstream &arch,void *Libros){
    char **DatosPedLibro = new char*[2]{};
    DatosPedLibro[0] = LeerCodLibroPed(arch);
    DatosPedLibro[1] = BuscarNombLibro(DatosPedLibro[0],Libros);
    return DatosPedLibro;
}
char * LeerCodLibroPed(ifstream &arch){
    char codigo[8],*PtrCodigo;
    arch>>codigo;
    PtrCodigo = new char[strlen(codigo)+1];
    strcpy(PtrCodigo,codigo);
    return PtrCodigo;
}
char * BuscarNombLibro(char *CodLibro,void *Libros){
    char *NombLibro=nullptr;
    void **ArrLibros = (void**) Libros;
    for(int i=0; ArrLibros[i];i++){
        if(EncontroLibro(ArrLibros[i],CodLibro)){
            NombLibro = ObtenerNombreLibro(ArrLibros[i]);
        }
    }
    return NombLibro;
}
bool EncontroLibro(void *Libro,char *CodLibro){
    void **DatoLibro = (void**)Libro;
    char *Codigo = (char*) DatoLibro[0];
    if(strcmp(CodLibro,Codigo)==0) return true;
    else return false;
}
char *ObtenerNombreLibro(void *Libro){
    void **DatoLibro = (void**)Libro;
    char *titulo = (char*) DatoLibro[1];
    return titulo;
}
char *BuscarNomCliente(void *Clientes,int *Dni){
    char *NomCliente = nullptr;
    void **ArrClientes = (void**)Clientes;
    for(int i=0;ArrClientes[i];i++){
        if(EncontroCliente(ArrClientes[i],Dni)){
            NomCliente = ObtenerNombreCliente(ArrClientes[i]);
        }
    }
    return NomCliente;
}
bool EncontroCliente(void *Cliente,int *dni){
    void **DatoCliente = (void**)Cliente;
    int *dniCliente = (int*) DatoCliente[0];
    return *dniCliente == *dni;
}
char *ObtenerNombreCliente(void *Cliente){
    void **DatoCliente = (void**)Cliente;
    char *nombre = (char*) DatoCliente[1];
    return nombre;
}
void ImprimirPedidos(void *Pedidos,const char * namefile){
    ofstream arch(namefile);
    void **ArrPedidos = (void**)Pedidos;
    for(int i=0;ArrPedidos[i];i++){
        ImprimirPedido(ArrPedidos[i],arch);
    }
}
void ImprimirPedido(void *Pedido,ofstream &arch){
    void **DatosPedido = (void**)Pedido;
    int *NumPedido = (int*) DatosPedido[0];
    int *Dni = (int*) DatosPedido[1];
    char *Nombre = (char*) DatosPedido[2];
    char ***PedLibros = (char***) DatosPedido[3];
    int *NumLibros = (int*) DatosPedido[4];
    arch<<left<<setw(10)<<*NumPedido<<setw(15)<<*Dni<<Nombre<<endl;
    for(int i=0;PedLibros[i];i++){
        char**DatoPedLibro = PedLibros[i];
        arch<<setw(10)<<" "<<setw(70)<<DatoPedLibro[1]<<setw(10)<<DatoPedLibro[0]<<endl;
    }
}

/* 
 * File:   PunteroGenerico.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 19:57
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "PunteroGenerico.h"
enum reg_Libro{CODIGO,TITULO,AUTOR};
enum reg_Cliente{DNI,NOMBRE,PEDIDOS,NUMPED};
enum reg_PedLibro{CODIGOL,TITULOL};

void LeerLibros(void *&Libros,const char * Namefile){
    ifstream arch(Namefile);
    void **ArrLibros, *Registro,*Buff[300];
    int NDatos=0;
    while(true){
        Registro = LeerRegistroLibro(arch);
        if(arch.eof()) break;
        Buff[NDatos]=Registro;
        NDatos++;
    }
    ArrLibros = new void*[NDatos+1]{};
    for(int i=0;i<NDatos;i++) ArrLibros[i] = Buff[i];
    Libros = ArrLibros;
}
void * LeerRegistroLibro(ifstream &arch){
    void **Registro = new void *[3]{};
    char* Codigo, *Titulo, *Autor;
    Codigo = LeerCadena(arch,',');
    if(arch.eof()) return nullptr;
    Titulo =LeerCadena(arch,',');
    Autor =LeerCadena(arch,',');
    while(arch.get() != '\n');
    Registro[CODIGO]=Codigo;
    Registro[TITULO]=Titulo;
    Registro[AUTOR]=Autor;
    return Registro;
}
char* LeerCadena(ifstream &arch, char c){
    char cadena[100],*ptrCadena;
    arch.getline(cadena,100,c);
    ptrCadena = new char[strlen(cadena)+1];
    strcpy(ptrCadena,cadena);
    return ptrCadena;
}
void ImprimirLibros(void *Libros,const char * Namefile){
    ofstream arch(Namefile);
    void **ArrLibros = (void**)Libros;
    for(int i=0;ArrLibros[i];i++){
        ImprimirUNLibro(arch,ArrLibros[i]);
    }
}
void ImprimirUNLibro(ofstream &arch,void *Libro){
    void **DatoLibro = (void **)Libro;
    char*Codigo =(char*)DatoLibro[CODIGO];
    char*titulo =(char*)DatoLibro[TITULO];
    char*autor =(char*)DatoLibro[AUTOR];
    arch<<left<<setw(14)<<Codigo<<setw(65)<<titulo<<autor<<endl;
}
void LeerClientes(void *&Clientes,const char * Namefile){
    ifstream arch(Namefile);
    void **ArrClientes, *Registro,*Buff[300];
    int NDatos=0;
    while(true){
        Registro = LeerRegistroClientes(arch);
        if(arch.eof()) break;
        Buff[NDatos]=Registro;
        NDatos++;
    }
    ArrClientes = new void*[NDatos+1]{};
    for(int i=0;i<NDatos;i++) ArrClientes[i] = Buff[i];
    Clientes = ArrClientes;
}
void * LeerRegistroClientes(ifstream &arch){
    void **Registro = new void *[4]{};
    int *Dni =new int, *NumPed= new int;
    char * Nombre;
    arch>>*Dni;
    if(arch.eof()) return nullptr;
    arch.get();
    Nombre = LeerCadena(arch,'\n');
    *NumPed = 0;
    Registro[DNI]=Dni;
    Registro[NOMBRE]=Nombre;
    Registro[PEDIDOS]=nullptr;
    Registro[NUMPED]=NumPed;
    return Registro;
}
void ImprimirClientes(void *Clientes, const char * Namefile){
    ofstream arch(Namefile);
    void **ArrClientes = (void**)Clientes;
    for(int i=0;ArrClientes[i];i++){
        ImprimirUNCliente(arch,ArrClientes[i]);
    }
}
void ImprimirUNCliente(ofstream &arch, void *Cliente){
    void **DatoCliente = (void **)Cliente;
    int*dni =(int*)DatoCliente[DNI];
    char*Nombre =(char*)DatoCliente[NOMBRE];
    void *Pedidos =(void *)DatoCliente[PEDIDOS];
    int*numPed =(int*)DatoCliente[NUMPED];
    arch<<left<<setw(14)<<*dni<<setw(40)<<Nombre<<endl;
    if(Pedidos){
        ImprimirPedidos(arch,Pedidos,numPed);
    }
}
void ImprimirPedidos(ofstream &arch,void *Pedidos,int *numPed){
    void **ArrPedidos =(void **)Pedidos;
    for(int i=0;ArrPedidos[i];i++){
        ImprimirUNPedido(arch,ArrPedidos[i]);
    }
    arch<<"Numero de pedidos del cliente: "<<*numPed<<endl<<endl;
}
void ImprimirUNPedido(ofstream &arch,void *Pedido){
    void **DatosPedido=(void**)Pedido;
    char* Codigo = (char*)DatosPedido[CODIGOL];
    char* titulo = (char*)DatosPedido[TITULOL];
    arch<<left<<setw(8)<<" "<<setw(12)<<Codigo<<titulo<<endl;
}
void AgregarPedidos(void *&Clientes,void *Libros,const char * Namefile){
    ifstream arch(Namefile);
    void **ArrClientes = (void **)Clientes;
    int DniCliente, PosCliente;
    char *CodLibro;
    while(true){
        arch>>DniCliente;
        if(arch.eof()) break;
        arch.get();
        CodLibro = LeerCadena(arch,'\n');
        PosCliente = BuscarCliente(Clientes,DniCliente);
        if(PosCliente!=-1){
            //Si lo contro le vamos agregar el codigo 
            ColocarPedidos(ArrClientes[PosCliente],CodLibro,Libros);
        } else {
            while(arch.get() != '\n');
        }
    }
}
int BuscarCliente(void *Clientes,int dni){
    void **ArregloClientes = (void **)Clientes;
    for(int i=0;ArregloClientes[i];i++){
        if(EncontroCliente(ArregloClientes[i],dni)) return i;
    }
    return -1;
}
bool EncontroCliente(void *Cliente,int dni){
    void **DatoCliente = (void **)Cliente;
    int * DniCliente = (int*)DatoCliente[DNI];
    return *DniCliente == dni;
}
void  ColocarPedidos(void *Cliente,char *CodLibro,void *Libros){
    void **DatoCliente = (void **)Cliente;
    void * Pedidos = (void*)DatoCliente[PEDIDOS];
    int * numPed = (int*)DatoCliente[NUMPED];
    int cantPed=*numPed;
    Pedidos = ColocarUnPedido(Pedidos,cantPed,CodLibro,Libros);
    //Actualizo
    DatoCliente[PEDIDOS] = Pedidos;
    *numPed =cantPed;
    DatoCliente[NUMPED] = numPed;
}
void* ColocarUnPedido(void *&Pedidos,int &cantPed,char *CodLibro,void *Libros){
    //Voy a crear un arreglo de void que se lo voy a pasar a pedidos
    void **PedidoOriginal = (void **)Pedidos;
    void **ArrPedidos, *Buff[10]{};
    if(Pedidos ==nullptr){
        Buff[0] = InsertarDatosLibro(CodLibro,Libros);
        cantPed = 1;
    } else {
        for(int i=0;i<cantPed;i++){
            Buff[i] = PedidoOriginal[i];
        }
        delete PedidoOriginal;
        Buff[cantPed] = InsertarDatosLibro(CodLibro,Libros);
        cantPed++;
    }
    ArrPedidos = new void *[cantPed+1]{};
    for(int i=0;i<cantPed;i++){
        ArrPedidos[i] = Buff[i];
    }
    return ArrPedidos;
}
void * InsertarDatosLibro(char *CodLibro,void *Libros){
    void **DatosLibro = new void *[2]{};
    DatosLibro[CODIGOL] = CodLibro;
    DatosLibro[TITULOL] = BuscarTituloLibro(CodLibro,Libros);
    return DatosLibro;
}
char *BuscarTituloLibro(char *CodLibro,void *Libros){
    void **ArrLibros = (void**)Libros;
    char* Titulo = nullptr;
    for(int i=0;ArrLibros[i];i++){
        if(EncontroLibro(ArrLibros[i],CodLibro)){
            Titulo = ObtenerTituloLibro(ArrLibros[i]);
            break;
        }
    }
    return Titulo;
}
bool EncontroLibro(void *Libro,char*CodLibro){
    void **DatoLibro = (void**)Libro;
    char* Codigo = (char*)DatoLibro[CODIGO];
    if(strcmp(Codigo,CodLibro)==0) return true;
    else return false;
}
char * ObtenerTituloLibro(void *Libro){
    void **DatoLibro = (void**)Libro;
    char* titulo = (char*)DatoLibro[TITULO];
    return titulo;
}
/* 
 * File:   MetodoIncremento.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 17 de abril de 2024, 18:35
 */

#ifndef METODOINCREMENTO_H
#define METODOINCREMENTO_H

void LecturaDeLibros(const char *namefile,char*** &Libros,int **&stock);
void PruebaDeLecturaDeLibros(const char *namefile,char*** Libros,int **stock);
char* LeerCadena(ifstream &arch);
char **LeerDatosLibro(ifstream &arch,char *&Codigo);
int * LeerDatosStock(ifstream &arch);
void IncrementarEspaciosLibros(char ***&Libros,int **&stock,int &nDatos,int &Cap);

void AtencionDePedidos(const char *namefile,char***Libros,int **&stock,int**&PedidosClientes,
        char*** &PedidosLibros,bool **&PedidoAtendidos,int *&Pedidos);
char ** LeerLibroPedidos(ifstream &arch);
char * LeerCodigoTXT(ifstream &arch);
void IncrementarPedidoLibros(char **&PedidosLibros,int &NumLibros,int &CapLibros);
int BuscarDni(int **PedidosClientes,int dni);
void IncrementarEspaciosClientes(int**&PedidosClientes,int *&Arr_nPedCli,int *&Arr_CapPedCli,int & nClientes, int &CapCliente);
void IncrementarEspaciosPedidos(int *&Pedidos,char ***&PedidosLibros,bool **&PedidoAtendidos,int &nPedido,int &CapPedidos);
void ColocarDatos(int *&Pedidos,int**&PedidosClientes,char*** &PedidosLibros,bool **&PedidoAtendidos,int &nClientes,
        int &nPedido,int posDni,int dni,int numPedido,int *&Arr_nPedCli,int *&Arr_CapPedCli,
        char **CodigoPedLib,char ***Libros,int **&stock);
int* ColocarPedidosCliente(int dni,int numPedido,int *&PedidosClientes,int &Arr_nPedCli, int &Arr_CapPedCli);
bool * LeerPedAtendidos(char **PedidosLibros,char ***Libros,int **&stock);
void IncrementarPedidoClientes(int *&PedCliente,int &Arr_nPedCli,int &Arr_CapPedCli);
void IncrementarPedAtendidos(bool *&PedAte,int &nPed,int &Cap);
int BuscarLibro(char ***Libros,char *PedLibros);

void OrdenarPedidos(int *Pedidos,char*** PedidosLibros,bool **PedidoAtendidos);
void Quick_Sort(int *Pedidos,char***PedidosLibros, bool **PedidoAtendidos,int IndLeft,int IndRight);
void Cambiar(int &PedA,int &PedB,char**&PedLibA,char**&PedLibB,bool *&PedAteA,bool *&PedAteB);

void ReporteDeEntregaDePedidos(const char *namefile,int**PedidosClientes,char***PedidosLibros,
        bool **PedidoAtendidos);
void  imprimirLinea (ofstream &arch,int cant,char letra);
void ImprimirPedidos(ofstream &arch,int *DatosCliente,char ***PedidosLibros,bool **PedidoAtendidos);

#endif /* METODOINCREMENTO_H */


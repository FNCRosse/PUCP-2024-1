/* 
 * File:   PunteroGenerico.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 18:34
 */

#ifndef PUNTEROGENERICO_H
#define PUNTEROGENERICO_H

void LeerLibros(void *&Libros,const char*Namefile);
void *LeerRegistroLibro(ifstream &arch);
char* LeerCadena(ifstream &arch,char letra);
void ImprimirLibros(void *Libros,const char*Namefile);
void ImprmirUnLibro(ofstream &arch, void* Libro);

void LeerClientes(void *&Clientes,const char*Namefile);
void *LeerRegistroCliente(ifstream &arch);
void ImprimirClientes(void *Clientes,const char*Namefile);
void ImprmirUnCliente(ofstream &arch, void* Cliente);

void LeerPedidos(void*Libros,void *Clientes, void *&Pedidos,const char*Namefile);
void *LeerRegistroPedido(ifstream &arch,void*Libros,void *Clientes);
void * LeerPedidoLibros(ifstream &arch,int &numLibros,void *Libros);
void *LeerUnPedido(ifstream &arch, void *Libros);
char * LeerCodigoLibro(ifstream &arch);
char *BuscarTituloLibro(char *codigoLibro,void *Libros);
bool EncontroLibro(void *Libros,char* CodLibro);
char* ObtenerTituloLibro(void *Libro);
char * BuscarNombreCliente(void *Clientes,int *DniC);
bool EncontroCliente(void *Cliente,int *DniC);
char * ObtenerNombreCliente(void *Cliente);
void ImprimirPedidos(void *Pedidos,const char*Namefile);
void ImprmirUnPedido(ofstream &arch,void *Pedido);
void ImprimirPedidosLibros(ofstream &arch, void *PedLibros);

#endif /* PUNTEROGENERICO_H */


/* 
 * File:   PunteroGenerico.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 19:57
 */

#ifndef PUNTEROGENERICO_H
#define PUNTEROGENERICO_H

void LeerLibros(void *&Libros,const char * Namefile);
void * LeerRegistroLibro(ifstream &arch);
char* LeerCadena(ifstream &arch, char c);
void ImprimirLibros(void *Libros,const char * Namefile);
void ImprimirUNLibro(ofstream &arch,void *Libro);

void LeerClientes(void *&Clientes,const char * Namefile);
void * LeerRegistroClientes(ifstream &arch);
void ImprimirClientes(void *Clientes, const char * Namefile);
void ImprimirUNCliente(ofstream &arch, void *Cliente);
void ImprimirPedidos(ofstream &arch,void *Pedidos,int *numPed);
void ImprimirUNPedido(ofstream &arch,void *Pedido);

void AgregarPedidos(void *&Clientes,void *Libros,const char * Namefile);
int BuscarCliente(void *Clientes,int dni);
bool EncontroCliente(void *Cliente,int dni);
void  ColocarPedidos(void *Cliente,char *CodLibro,void *Libros);
void* ColocarUnPedido(void *&Pedidos,int &numPed,char *CodLibro,void *Libros);
void * InsertarDatosLibro(char *CodLibro,void *Libros);
char *BuscarTituloLibro(char *CodLibro,void *Libros);
bool EncontroLibro(void *Libro,char*CodLibro);
char * ObtenerTituloLibro(void *Libro);

#endif /* PUNTEROGENERICO_H */


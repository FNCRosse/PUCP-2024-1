/* 
 * File:   PunteroGenericos.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 24 de abril de 2024, 14:35
 */

#ifndef PUNTEROGENERICOS_H
#define PUNTEROGENERICOS_H

    void LeerLibro(void *&Libros,const char * namefile);
    void *LeerRegistroLibro(ifstream &arch);
    char * LeerCadena(ifstream &arch,char c);
    void ImprimirLibros(void *Libros,const char * namefile);
    void ImprimirLibro(void *ArrLibros,ofstream &arch);
    
    void LeerCliente(void *&Clientes,const char * namefile);
    void *LeerRegistroCliente(ifstream &arch);
    void ImprimirClientes(void *Clientes,const char * namefile);
    void ImprimirCliente(void *Cliente,ofstream &arch);
    
    void LeerPedidos(void *Libros,void *Clientes,void *&Pedidos,const char * namefile);
    void *LeerRegistroPedido(ifstream &arch,void *Libros,void *Clientes);
    void LeerPedidosDeLibro(ifstream &arch,char***&PedidoLibro,int &cantLibros,void *Libros);
    char **LeerDatosPedLibro( ifstream &arch,void *Libros);
    char * LeerCodLibroPed(ifstream &arch);
    char * BuscarNombLibro(char *CodLibro,void *Libros);
    bool EncontroLibro(void *Libro,char *CodLibro);
    char *ObtenerNombreLibro(void *Libros);
    char *BuscarNomCliente(void *Clientes,int *Dni);
    bool EncontroCliente(void *Cliente,int *dni);
    char *ObtenerNombreCliente(void *Cliente);
    void ImprimirPedidos(void *Pedidos,const char * namefile);
    void ImprimirPedido(void *Pedido,ofstream &arch);
    
#endif /* PUNTEROGENERICOS_H */


/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 17 de abril de 2024, 14:44
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void LecturaDeLibros(const char *namefile,char ***&Libros,int**&stock);
void PruebaDeLecturaDeLibros(const char *namefile,char***Libros,int **stock);
char * LeerCadena (ifstream &arch);
char ** LeerDatosLibro (ifstream &arch,char* codigo);
int* LeerDatosStock(ifstream &arch);
    
void AtencionDePedidos(const char *namefile,char ***Libros,int **&stock,int **&PedidosClientes,
                                            char ***&PedidosLibros,bool **&PedidosAtendidos);
char ** LeerLibrosDelPedido(ifstream &arch);
char * LeerCodigoLibros(ifstream &arch);
int BuscarCliente(int **BuffClientes,int dni);
int *ColocarCliente(int dni,int numPedido,int *&BuffClientes,int &nClientes);
bool *ColocarLibrosAtendidos(char **BuffLibros,char ***Libros,int **&stock);
int BuscarLibro(char ***Libros,char *nomlibro);

void ReporteDeEnvioDePedidos(const char *namefile,int **PedidosClientes,char ***PedidosLibros,
        bool **PedidosAtendidos);
void  ImprimirLines(ofstream &arch,int cant,char letra);
void ImprimirPedidos(int *DatosCliente,char ***PedidosLibros, bool **PedidosAtendidos,ofstream &arch);
void ImprimirObservacion(bool DatosPedAte,ofstream &arch);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */


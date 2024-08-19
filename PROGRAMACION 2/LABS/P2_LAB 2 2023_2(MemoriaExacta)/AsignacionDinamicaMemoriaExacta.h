/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 10 de abril de 2024, 12:54
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void LecturaDeProducto(const char*  namefile,char ***&Producto,int *&Stock,double *&precios);
void pruebaDeLecturaDeProductos(const char*  namefile,char ***Producto,int *Stock,double *precios);
    
void LecturaDePedido(const char*  namefile,int *&fechaPedidos,char ***&CodidoPedido,int ***&dniCantPedido);
void pruebaDeLecturaDePedidos(const char*  namefile,int *fechaPedidos,char ***CodidoPedido,int ***dniCantPedido);
    
void ReporteDeEnvioDePedidos(const char*  namefile,char ***Producto,int *&Stock,double *precios,
        int *fechaPedidos,char ***CodidoPedido,int ***dniCantPedido);

int ** colocarDNI(int dni,int cant,int &numDCP,int**&BuffDCP);
char* LeerCadena(ifstream &arch);
char** LeerProducto(ifstream &arch);
int LeerFecha(ifstream &arch);
int BuscarFecha(int *BuffFecha,int fecha);
char** colocarCodigo(char *codigo,int &numCodP,char **&BuffCodP);
void HacerLinea(ofstream &arch, char letra, int cant);
void imprimirPedidos(int **dniCantPedido,char **CodidoPedido,char ***Producto,double *precios,int *&Stock,
        ofstream &arch,double &montoIng,double &montoPer);
int BuscarProducto(char ***Producto,char *CodidoPedido);

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */


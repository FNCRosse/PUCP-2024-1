/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 16 de abril de 2024, 11:36
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H

void LecturaDeProductos(const char *namefile,char***&producto,int*&stock,double *&precios);
void PruebaDeLecturaDeProductos(const char *namefile,char***producto,int*stock,double *precios);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LecturaDePedidos(const char *namefile,int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos);
void PruebaDeLecturaDePedidos(const char *namefile,int *fechaPedidos,char ***codigoPedidos,
                                        int ***dniCantPedidos);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ReporteDeEnviosDePedidos(const char *namefile,char***producto,int*&stock,double *precios,
                                                 int *fechaPedidos,char ***codigoPedidos, int ***dniCantPedidos);
void ImprimirLinea(ofstream &arch,int cant ,char letra);
void ImprimirPedidos(ofstream &arch,int **dniCantPedidos,char **codigoPedidos,char ***producto,int *&stock,double *precio);
int BuscarProducto(char ***producto,char *codigoPedidos);
void VerificacionStockyCalculoIngreso(ofstream &arch,double precio, int cantidad,int &stock,
        double &montoIngresado,double &montoPerdido);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OrdenarPorFechas(int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos);
void quick_Sort(int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos,int Izq,int der);
void cambiar(int &fechaA,int &fechaB,char **&codPedA,char **&codPedB,int **&DCPA,int **&DCPB);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* LeerCadena(ifstream & arch);
char** LeerDatosProducto(char *codigo,ifstream &arch);
void incrementarCapacidadProducto(int &cap,int &nDatos,char***&producto,int*&stock,double *&precios);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BuscarFecha(int *&fechaPedidos,int fecha);
void IncrementarCapacidadPedidos(int &nDatos,int &cap,int *&fechaPedidos,char ***&codigoPedidos,
                                        int ***&dniCantPedidos,int *&N_CodPed,int *&N_DCP,int *&Cap_CodPed,int *&Cap_DCP);
void ColocarCodPed(char *Codigo,int &N_CodPed,int &Cap_CodPed,char**&codigoPedidos);
void ColocarDCP(int dni,int cant,int &N_DCP,int &Cap_DCP,int **&dniCantPedidos);
void  IncrementarEspacios(char **&codigoPedidos,int &N_CodPed,int &Cap_CodPed);
void  IncrementarEspacios(int  **&dniCantPedidos,int &N_DCP,int &Cap_DCP);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */


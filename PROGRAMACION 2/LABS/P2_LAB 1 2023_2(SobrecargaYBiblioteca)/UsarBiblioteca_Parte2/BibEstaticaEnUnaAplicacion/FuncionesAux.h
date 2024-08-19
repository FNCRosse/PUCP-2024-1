/* 
 * File:   FuncionesAux.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 1 de abril de 2024, 20:42
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void LeerClientes(int &CantCli, struct Cliente *arrClientes,const char* namefile);
void LeerProductos(int &CantProd, struct Producto *ArrProductos,const char* namefile);
void LeerPedidos(int &CantPed, struct Pedido *ArrPedidos,const char* namefile);

void AgregacionPedidoAProducto(int CantPed,struct Pedido *ArrPedidos,struct Producto *ArrProductos);
void AgregacionPedidoACliente(int CantPed,struct Pedido *ArrPedidos,struct Cliente *arrClientes);

void ImprimirReporte(int CantCli,struct Cliente *arrClientes,int CantProd,struct Producto *ArrProductos,const char* namefile);


#endif /* FUNCIONESAUX_H */


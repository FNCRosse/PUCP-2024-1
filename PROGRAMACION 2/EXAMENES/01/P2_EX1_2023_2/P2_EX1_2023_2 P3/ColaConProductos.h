/* 
 * File:   ColaConProductos.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 14:41
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H

void ProcesarPedidos(int **FechaClienteCantidad,char**CodigoDelProducto,void *Productos);
int BuscarCodigo(char * NomProd,void *Productos);
bool EsPosibleElPedido(int *FechaClienteCantidad, void *Producto);
void ActualizarStock(int *FechaClienteCantidad,void *Producto);
void InsertarEnCola(void *Dato,void *Producto);
void reporteDePedidos(void *Productos,const char *namefile);
void ImprimirCola(ofstream &arch,void *Producto);
void  imprimeColaPedido(ofstream &arch,void *nodo);

#endif /* COLACONPRODUCTOS_H */


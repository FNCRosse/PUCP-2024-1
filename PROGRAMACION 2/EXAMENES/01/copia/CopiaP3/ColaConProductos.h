/* 
 * File:   ColaConProductos.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 08:03
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H

void procesarPedidos(int **FechaClienteCantidad,char **CodigoDelProducto,void*Productos);
void reporteDePedidos(void *Productos,const char* namefile);

int BuscarProducto (char *codProd,void *Productos);
bool EsPosiibleAtenderPedido(int *DatosPed, void* Producto);
void ActualizarStock(int* DatosPed,void *Producto);
void ColocarPedido(void *Producto,void *Dato);
void ImprimirColaPedidos(ofstream &arch,void *Producto);
void ImprimirUNPedido(ofstream &arch,void *Nodo);
#endif /* COLACONPRODUCTOS_H */


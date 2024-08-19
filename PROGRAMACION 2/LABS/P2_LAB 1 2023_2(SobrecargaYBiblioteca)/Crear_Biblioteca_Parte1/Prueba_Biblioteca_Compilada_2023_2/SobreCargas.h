/* 
 * File:   SobreCargas.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 1 de abril de 2024, 22:08
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <fstream>
using namespace std;

bool operator >> (ifstream &arch, struct Cliente &cliente);
bool operator >> (ifstream &arch, struct Producto &prod);
bool operator >> (ifstream &arch, struct Pedido &ped);

bool operator += (struct Producto *ArrProd, struct Pedido &ped);
void operator += (struct Cliente *ArrCli, struct Pedido &ped);

void operator <<(ofstream &arch, const struct Cliente &cliente);
void operator <<(ofstream &arch, const struct Producto &prod);

#endif /* SOBRECARGAS_H */


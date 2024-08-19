/* 
 * File:   ColaGenerica.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 14 de mayo de 2024, 07:38
 */

#ifndef COLAGENERICA_H
#define COLAGENERICA_H

void GeneraCola(void *&Cola);
void Encola(void* Cola, void* Dato);
void * Desencola (void* Cola);
bool ColaVacia(void* Cola);

#endif /* COLAGENERICA_H */


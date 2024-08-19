/* 
 * File:   FuncionesCola.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 25 de abril de 2024, 15:21
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & cola);
bool esColaVacia(const struct Cola & cola);
int longitud(struct Cola cola);
void encolar(struct Cola & cola,struct Cliente cliente);
void encolarConPrioridad(struct Cola &cola,const struct Cliente &Cliente);
int desencolar(struct Cola & cola);

void imprime(const struct Cola & cola);

void destruirCola(struct Cola & cola);
void OrdenarCola(struct Cola &cola, int n);
#endif /* FUNCIONESCOLA_H */


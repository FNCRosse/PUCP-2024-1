/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 18 de abril de 2024, 10:28 AM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

void construir(struct Cola & );       
bool esColaVacia(const struct Cola & cola);
void imprimir(const struct Cola & cola);
void encolarConPrioridad(struct Cola & cola, const struct Cliente & cliente);

#endif /* FUNCIONESCOLA_H */


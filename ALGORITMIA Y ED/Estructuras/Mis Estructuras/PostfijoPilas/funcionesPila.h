/* 
 * File:   funcionesPila.h
 * Author: ANA RONCAL
 * Created on 6 de septiembre de 2023, 12:49 PM
 */

#ifndef FUNCIONESPILA_H
#define FUNCIONESPILA_H

void construir(struct Pila & );
int longitud(struct Pila );
bool esPilaVacia(struct Pila);
void apilar(struct Pila &, int ); 
int desapilar(struct Pila &);
int cima(const struct Pila &);
void destruirPila(struct Pila &);
void imprime(struct Pila );


int esOperador(char  c);
int opera(char c, int operando1, int operando2);
void notacionPostfija(struct Pila &);

#endif /* FUNCIONESPILA_H */


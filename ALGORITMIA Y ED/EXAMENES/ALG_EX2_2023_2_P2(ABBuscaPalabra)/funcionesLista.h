/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
bool esListaVacia(const struct Lista & lista);
int longitud(struct Lista tad );
struct Nodo * crearNodo(char* elemento, struct Nodo * siguiente);
void insertarAlFinal(struct Lista & lista, char* elemento);
void imprime(const struct Lista & lista);
void eliminaCabeza(struct Lista  & lista);
char* retornaCabeza(const struct Lista & lista);
void destruirLista(struct Lista & lista);

bool EliminarLetra(struct Lista &tad, char *letra);
bool BuscaLetra(struct Lista &tad,char* letra);
#endif /* FUNCIONESLISTA_H */


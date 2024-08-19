/* 
 * File:   Funciones.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de abril de 2024, 19:51
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void CrearLista(const char* namefile,void *&Lista,void *(*lee)(ifstream &),
        int (*cmp)(const void*, const void*));
void insertar(void *dato, void*&Lista, int(*cmp)(const void*, const void*));
void ImprimirLista(void *Lista,void (*imprime)(void*));
void EliminarLista(void *Lista,void (*elimina)(void*));

void *leeReg (ifstream &arch);
int regNombCMP(const void*, const void*);
int regCodCMP(const void*, const void*);
int regSueldoCMP(const void*a, const void*b);
void ImprimeReg(void*);
void EliminaReg(void*);





#endif /* FUNCIONES_H */


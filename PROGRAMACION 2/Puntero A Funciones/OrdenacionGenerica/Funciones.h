/* 
 * File:   Funciones.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de abril de 2024, 19:07
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void LeerDatos(void *&Personal,int &nd,const char* namefile);
void *LeerRegistro(ifstream &arch);
char* LeerCadena(ifstream &arch,char c);
void ImprimirDatos(void *Personal,int nd);
void ImprimirRegistro(void *reg);

//Funciones que van ser llamadas para la compraracion del ordenar generico
void OrdenarGenerico(void *Personal,int izq,int der, int (*cmp)(const void*,const void*));
void CambiarGen(void *&arrI, void*& arrk);

int voidCMPSueldo(const void *a, const void *b);
int voidCMPCodigo(const void *a, const void *b);
int voidCMPNombres(const void *a, const void *b);
#endif /* FUNCIONES_H */


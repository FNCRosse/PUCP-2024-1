
/* 
 * File:   Funciones.h
 * Author: alulab14
 *
 * Created on 4 de noviembre de 2023, 08:17 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void Insertar(struct ArbolBinario &Arbol_token,int Codigo);
void plantarABBnew(struct NodoArbol *&Arbol,struct NodoArbol *arbolIzq,
                    int Codigo, struct NodoArbol *arbolDer);
void InsertarRecursivo(struct NodoArbol *&Arbol,int Codigo);
struct NodoArbol* busca_primer_ancestro_comun(NodoArbol *Raiz,int num1, int num2);
bool suma_parcial_arboles(struct ArbolBinario *Arbol_token,
                        struct ArbolBinario *Arbol_SIS, NodoArbol* PrimerAncestroC);
bool suma_parcial_arboles_Nodos(struct NodoArbol *Arbol_token,
                        struct NodoArbol *Arbol_SIS, NodoArbol* PrimerAncestroC);
bool EsArbolBB (struct NodoArbol *arboltoken);
int CompararABB(int a, int b);

#endif /* FUNCIONES_H */


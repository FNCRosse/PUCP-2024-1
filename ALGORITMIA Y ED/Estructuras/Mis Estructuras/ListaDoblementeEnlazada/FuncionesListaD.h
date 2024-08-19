/* 
 * File:   FuncionesListaD.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de abril de 2024, 14:26
 */

#ifndef FUNCIONESLISTAD_H
#define FUNCIONESLISTAD_H

///////////////////////////////////////////////////////////CREACION Y DATOS DE LISTA S ////////////////////////////////////////////////////////////////
void Construir (struct ListaD &tad);
bool ListaEstaVacia(const struct ListaD &tad);
int LongitudLista(const struct ListaD &tad);

/////////////////////////////////////////////////////////////////////// INSERTAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void InsertarInicio(struct ListaD &tad,struct Equipo elem);
void InsertarFinal(struct ListaD &tad,struct Equipo elem);
void InsertarEnOrden(struct ListaD &tad,struct Equipo elem);

struct Nodo* CrearNodo(struct Equipo elem,struct Nodo *sig,struct Nodo *Ant);
struct Nodo* ObtenerNodoAnterior(struct Equipo elem,struct ListaD &tad);
struct Nodo* EncontrarNodo(const struct ListaD &tad, struct Equipo elem);
/////////////////////////////////////////////////////////////////////// ELIMINAR EN LISTA S ///////////////////////////////////////////////////////////////////////
void EliminarNodo(struct ListaD &tad,struct Equipo elem);
void EliminarCabeza(struct ListaD&tad);
void EliminarCola(struct ListaD&tad);
void EliminarRepetidos(struct ListaD &tad);
/////////////////////////////////////////////////////////////////////// DESTRUIR LISTA S ///////////////////////////////////////////////////////////////////////
void Destruir(struct ListaD &tad);

/////////////////////////////////////////////////////////////////////// MOSTRAR LISTA S ///////////////////////////////////////////////////////////////////////
void mostrar(const struct ListaD &tad);
void MostrarDesdeFinal(const struct ListaD &tad);
/////////////////////////////////////////////////////////////////////// INVERTIR  LISTA S ///////////////////////////////////////////////////////////////////////
void InvertirIterativo(struct ListaD &ptrLista);
void InvertirRecursivo(struct ListaD &ptrLista);//Me falta
struct Nodo* RecorrerEInvertirRec(Nodo *ptrAntCambio);

#endif /* FUNCIONESLISTAD_H */


/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: USER
 *
 * Created on 6 de octubre de 2023, 11:06 PM
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
#include <fstream>
using namespace std;

void ingresoDeFecha(int &fechaSolicitada);
void emitirReporte(int fechaSolicitada,const char *,const char *,const char *,
        const char *,const char *);
void imprimirEncabezado(ofstream &archReporte,int fechaSolicitada);
void imprimirLinea(ofstream &archReporte,char carac,int cant);
void leerNombre(ifstream &archPeli,ofstream &archReporte);
void cambiarCaracter(char &c);
void buscarResto(int fechaSol,int codPelicula,ifstream &archFunc,ifstream &archSalas,
        ifstream &archVentas,ofstream &archReporte,int &cantFunc,int &totButDisp,
        int &totButVend,int &totButOcup,double &totRecau);
void buscarTotButDisp(int sala,ifstream &archSalas,int &totButDisp);
void leerVentas(int sala,int hh,int mm,int fechaSol,ifstream &archVentas,int &totButOcup,
                                              int &totButVend,double &totRecau);
void buscarButOcup(ifstream &archVentas,int &totButOcup);
void imprimirFinal(ofstream &archReporte,double totRecau,int totBut,int totVend,
        int totOcup,int cantPeli);
#endif /* FUNCIONESAUXILIARES_H */


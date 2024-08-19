/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: Joshua Haro
 *
 * Created on May 16, 2023, 8:32 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void construir(ABB *);
NodoAlumno *crearNuevoNodoAlumno(char []);
NodoAlumno *ubicarAlumno(nodoAlumno *, char [20]);
void registrarAlumno( ABB *, char []);
void registrarNota(ABB *,char [20], int , char [10]);
void mostrarNotasCurso(NodoAlumno * );
void mostrarNotasAlumno(ABB ,char [20]);
int obtenerCursoMejorNota(NodoAlumno *,char [20]);
void aprobadosDesaprobados(NodoAlumno *,char [10], int *, int *);

#endif /* FUNCIONES_H */


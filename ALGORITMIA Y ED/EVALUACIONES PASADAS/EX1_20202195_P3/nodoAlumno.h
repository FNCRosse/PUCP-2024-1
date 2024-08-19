/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   nodoAlumno.h
 * Author: Joshua Haro
 *
 * Created on May 16, 2023, 8:30 AM
 */

#ifndef NODOALUMNO_H
#define NODOALUMNO_H

#include "nodoCurso.h"

typedef struct nodoAlumno
{
    char alumno[20]; // nombre del alumno
    NodoCurso *pcur; // puntero a la lista de cursos que lleva el alumno
    struct nodoAlumno *hizq;
    struct nodoAlumno *hder;
} NodoAlumno;


#endif /* NODOALUMNO_H */


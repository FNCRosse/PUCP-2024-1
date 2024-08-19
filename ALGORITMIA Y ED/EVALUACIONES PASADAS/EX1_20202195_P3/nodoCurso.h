/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   nodoCurso.h
 * Author: Joshua Haro
 *
 * Created on May 16, 2023, 8:30 AM
 */

#ifndef NODOCURSO_H
#define NODOCURSO_H

typedef struct nodoCurso
{
    char curso[10]; // nombre del curso
    int nota; // nota obtenida en el curso
    struct nodoCurso *sig;
} NodoCurso;

#endif /* NODOCURSO_H */


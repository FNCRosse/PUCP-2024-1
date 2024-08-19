/* 
 * File:   MetodoDinamicoExacto.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 11 de abril de 2024, 20:24
 */

#ifndef METODODINAMICOEXACTO_H
#define METODODINAMICOEXACTO_H


void LecturaAlumnos(const char * namefile,int *&alumno_Codigo,char **&alumno_nombre,
        char *&alumno_Modalidad,int *&alumno_porcentaje,int *&alumno_escala);
void PruebaLecturaAlumnos(const char * namefile,int *alumno_Codigo,char **alumno_nombre,
        char *alumno_Modalidad,int *alumno_porcentaje,int *alumno_escala);
    
void LecturaCursos(const char * namefile,int *alumno_Codigo,int *alumno_escala,char **&curso_Nombre,
        double *&curso_credito,int **&curso_Alumnos);
void PruebaLecturaCursos(const char * namefile,char **curso_Nombre,
        double *curso_credito,int **curso_Alumnos);
    
void ReporteDeRecaudacionPorModalidad(const char * namefile,int  *alumno_Codigo,char *alumno_Modalidad,
            int *alumno_porcentaje,char **alumno_nombre,char **curso_Nombre,double *curso_credito
            ,int **curso_Alumnos);

char * LeerCadena(ifstream &arch); 
void LeerMod_Por_Esc(ifstream &arch,char &buffMod,int &buffPor,int &buffEsc);
int BuscarAlumno(int *alumno_Codigo,int cod);
int BuscarCurso(char **BuffNomb,char *nombre);
int* ColocarAlumno(int *&buffCurAlu,int &numCurA,int cod,int posAlumno,int *alumno_escala);
 void ImprimirAlumnos(int *curso_Alumnos,ofstream &arch);
#endif /* METODODINAMICOEXACTO_H */


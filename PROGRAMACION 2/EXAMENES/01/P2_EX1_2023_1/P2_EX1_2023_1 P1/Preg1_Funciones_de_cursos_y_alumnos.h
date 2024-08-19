/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 17:40
 */

#ifndef PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H
#define PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H

void cargasCursosYEscalas (char***&Cursos,double *&Cursos_cred,double *escalas,const char* namefile,
        const char* namefile2);
void pruebaDeCargaDeCursos(char ***Cursos,double *Cursos_cred,const char* namefile);

void CargaAlumnos(int *&alumnos_cod,int **&Alumnos,char***&Alumnos_nom_mod,const char* namefile);
void pruebaDeCargaAlumnos(int *alumnos_cod,int **Alumnos,char***Alumnos_nom_mod,const char* namefile);


char *LeerCadena(ifstream &arch,char c);
void IncrementarEspacios(char***&Cursos,double *&Cursos_cred,int &ndatos,int &cap);
char ** ColocarDatosCurso(char *codigo,char *nomCurso,char* nomProfe);
void IncrementarEspaciosAlumnos(int *&alumnos_cod,int **&Alumnos,char***&Alumnos_nom_mod,int &ndatos,int &cap);
int *ColocarDatosAlumno(int codAlumno,int escala,int porcentaje);
char ** ColocarNombYModAlumno(char *nombAlumno,char* modalidad);
#endif /* PREG1_FUNCIONES_DE_CURSOS_Y_ALUMNOS_H */


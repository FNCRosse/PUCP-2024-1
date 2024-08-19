/* 
 * File:   funcionesAux.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 10 de abril de 2024, 08:57
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void LeerAlumnos_Cursos(int *&codigo, char **&nombres,char*** &cursos,const char* namefile);
void MostrarAlumnos_Cursos(int *codigo, char **nombres,char*** cursos,const char* namefile);
char* LeerCadena(ifstream &arch);
char** LeerCursos (ifstream &arch);
char* LeerCadenaCurso(ifstream &arch);
void MostrarCursos(char** cursos,ofstream &arch);

void LeerDatosAlumnos(int *&codigos2,char **&nombres2,const char* namefile);
char * LeerNombre(ifstream &arch);
void LeerDatosCursos(int*codigos2,char ***&Cursos2,const char* namefile);
int BuscarAlumno(int cod,int *codigos2);
void ColocarCurso(ifstream &arch,char **Cursos2,int &nd);
void espaciosExactos(char **&Cursos2,int nd);

#endif /* FUNCIONESAUX_H */


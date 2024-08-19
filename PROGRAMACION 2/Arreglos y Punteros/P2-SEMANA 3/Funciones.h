/* 
 * File:   Funciones.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 5 de abril de 2024, 16:00
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void LeerDatos(const char* namefile,char**  Codigos,char** &Nombres,char*** &Cursos);
void MostrarDatos(char** Codigos,char** Nombres,char*** Cursos);
char* leerCadena(ifstream& arch,const char);
char** separarCursos(char *bufferCursos);

#endif /* FUNCIONES_H */


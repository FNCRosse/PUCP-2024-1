/* 
 * File:   FuncionesAux.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 3 de abril de 2024, 22:30
 */

#ifndef FUNCIONESAUX_H
#define FUNCIONESAUX_H

void LeerCursos(struct StCurso *ArrCursos, const char* namefile);
void LeerAlumnos(struct StAlumno * ArrAlumnos, const char* namefile);

void AsignacionMatricula(struct StCurso * ArrCursos, struct StAlumno * ArrAlumno, const char* namefile);

void ImprimirReportes(const struct StCurso * ArrCursos, const struct StAlumno * ArrAlumno,
                                    const char* RepClienteName,const char* RepCursosName);
#endif /* FUNCIONESAUX_H */


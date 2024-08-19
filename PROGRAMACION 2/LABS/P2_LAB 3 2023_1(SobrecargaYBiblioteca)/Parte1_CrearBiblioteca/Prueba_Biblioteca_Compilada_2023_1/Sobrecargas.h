/* 
 * File:   SobreCarga.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de abril de 2024, 11:29
 */

#ifndef SOBRECARGA_H
#define SOBRECARGA_H
#include <fstream>
using namespace std;

bool operator >> (ifstream &arch, struct StCurso &curso);
bool operator >> (ifstream &arch, struct StAlumno &alumno);
bool operator >> (ifstream &arch, struct StRegistroDeMatricula &reg);

void operator += (struct StCurso *ArrCurso, const StCurso &curso);
void operator += (struct StAlumno *ArrAlumno, const StAlumno &alumno);
void operator *=(struct StCurso * curso, const StRegistroDeMatricula &RegMat);
void operator *=(struct StAlumno *ArrAlumno, const StRegistroDeMatricula &RegMat);

void operator << (ofstream &arch, const struct StCurso &curso);
void operator << (ofstream &arch, const struct StAlumno &alumno);

#endif /* SOBRECARGA_H */


/* 
 * File:   Sobrecargas.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 4 de abril de 2024, 15:19
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <fstream>
#include "Estructuras.h"
using namespace std;

bool operator >>(ifstream &arch, struct StMedico &medico);
bool operator >>(ifstream &arch, struct StPaciente &pac);
int operator >>(ifstream &arch, struct StCita &cita);

bool operator <=(struct StCita &cita, const struct StMedico *ArrMedicos);
void operator += (struct StPaciente &Paciente, const struct StCita cita);
StPaciente& operator ++(struct StPaciente &pac);

void operator <<(ofstream &arch, const struct StPaciente &pac);

#endif /* SOBRECARGAS_H */


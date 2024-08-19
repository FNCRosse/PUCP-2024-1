/* 
 * File:   OperadoresSobreCargados.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de marzo de 2024, 09:59
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H
#include <fstream>
using namespace std;

void operator >>(ifstream &arch, struct Persona &p);
ostream& operator <<(ostream &out, const struct Persona &p);
bool operator ==(int,const struct Persona &p);
Persona operator ++(Persona &p);
Persona operator ++(Persona &p,int);
Persona operator --(Persona &p);
Persona operator --(Persona &p,int);
Persona operator +(const Persona &p1, const Persona &p2);
Persona operator -(const Persona &p1, const Persona &p2);
Persona operator *(const Persona &p1, const Persona &p2);
Persona operator /(const Persona &p1, const Persona &p2);
Persona operator %(const Persona &p1, const int Porcentaje);


#endif /* OPERADORESSOBRECARGADOS_H */


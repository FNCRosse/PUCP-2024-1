/* 
 * File:   Virtual.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 20:02
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Virtual.h"

Virtual::Virtual(){
    total =0;
    Licencia = nullptr;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(const char* cad) {
    if(Licencia != nullptr) delete Licencia;
    Licencia = new char[strlen(cad)+1];
    strcpy(Licencia,cad);
}

void Virtual::GetLicencia(char *&cad) const {
    if(Licencia == nullptr) cad[0]=0;
    cad = new char[strlen(cad)+1];
    strcpy(cad,Licencia);
}
void Virtual::LeerDatos(ifstream &arch){
    char Buff[30];
    Alumno::LeerDatos(arch);
    arch.getline(Buff,20,'\n');
    SetLicencia(Buff);
}
void Virtual::Actualiza(double monto){
    Alumno::SetTotal(monto+total);
}
void Virtual::Imprimir(ofstream &arch){
    Alumno::Imprime(arch);
    arch<<left<<setw(20)<<Licencia<<Alumno::GetTotal()<<endl;
}
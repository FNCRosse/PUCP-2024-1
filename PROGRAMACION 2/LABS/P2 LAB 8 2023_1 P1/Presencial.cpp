/* 
 * File:   Presencial.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:55
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Presencial.h"

Presencial::Presencial(){
    total =0;
    recargo =0;
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::LeerDatos(ifstream &arch){
    Alumno::LeerDatos(arch);
    arch>>recargo;
    arch.get();
}
void Presencial::Actualiza(double monto){
    total = monto * GetRecargo()/100;
    Alumno::SetTotal(monto+total);
}
void Presencial::Imprimir(ofstream &arch){
    Alumno::Imprime(arch);
    arch<<left<<setw(20)<<" "<<Alumno::GetTotal()<<endl;
}
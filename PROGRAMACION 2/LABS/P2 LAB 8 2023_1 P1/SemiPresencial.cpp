/* 
 * File:   SemiPresencial.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:58
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "SemiPresencial.h"

SemiPresencial::SemiPresencial(){
    total =0;
    descuento=0;
}

void SemiPresencial::SetTotal(double total) {
    this->total = total;
}

double SemiPresencial::GetTotal() const {
    return total;
}

void SemiPresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double SemiPresencial::GetDescuento() const {
    return descuento;
}
void SemiPresencial::LeerDatos(ifstream &arch){
    Alumno::LeerDatos(arch);
    arch>>descuento;
    arch.get();
}
void SemiPresencial::Actualiza(double monto){
    total = monto * GetDescuento()/100;
    Alumno::SetTotal(monto-total);
}
void SemiPresencial::Imprimir(ofstream &arch){
    Alumno::Imprime(arch);
    arch<<left<<setw(20)<<" "<<Alumno::GetTotal()<<endl;
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Rosse
 * 
 * Created on 20 de junio de 2024, 14:43
 */
#include "Util.h"
#include "Vehiculo.h"
#include "Camion.h"
#include "NPedidos.h"
Camion::Camion(){
    
}
void Camion::leer(ifstream &arch) {
    Vehiculo::leer(arch);
    arch>>ejes;
    arch.get();
    arch>>llantas;
    arch.get();
}

void Camion::imprime(ofstream &arch) {
    Vehiculo::imprime(arch);
    arch<<left<<setw(20)<<"#Ejes:"<<ejes<<endl;
    arch<<left<<setw(20)<<"#Llantas:"<<llantas<<endl;
    arch<<"Lista de Pedidos:"<<endl;
    if(mdeposito.empty()){
        arch<<"No hay pedidos para el cliente"<<endl<<endl;
    } else{
        NPedidos aux;
        for(int i=0;i<mdeposito.size();i++){
            aux = mdeposito[i];
            arch<<right<<setw(5)<<i+1<<left<<setw(3)<<" ";
            aux.imprime(arch);
        }
    }
    
}
void Camion::CargaDeposito(NPedidos &ped){
    if(ped.GetPeso()+GetActcarga() <= GetMaxcarga() and mdeposito.size()<5){
        int i =mdeposito.size();
        mdeposito[i] = ped;
        SetActcarga(GetActcarga()+ped.GetPeso());
    }
}
void Camion::SetLlantas(int llantas) {
    this->llantas = llantas;
}

int Camion::GetLlantas() const {
    return llantas;
}

void Camion::SetEjes(int ejes) {
    this->ejes = ejes;
}

int Camion::GetEjes() const {
    return ejes;
}
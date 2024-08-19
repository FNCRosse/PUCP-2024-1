/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   Camion.cpp
 * Author: Rosse
 * 
 * Created on 21 de junio de 2024, 05:05
 */
#include "Util.h"
#include "Camion.h"
#include "Vehiculo.h"

Camion::Camion() {

}

void Camion::lee(ifstream &arch) {
    Vehiculo::lee(arch);
    arch>>ejes;
    arch. get();
    arch>>llantas;
    arch.get();
}

void Camion::imprime(ofstream &arch) {
    Vehiculo::imprime(arch);
    arch << left << setw(22) << "#Ejes:" << ejes << endl;
    arch << left << setw(22) << "#Llantas:" << llantas << endl;
    arch << "Lista de pedidos: " << endl;
    if (mdeposito.empty()) {
        arch << "No hay pedidos" << endl << endl;
    } else{
        int i=0;
        for(auto x: mdeposito){
            arch<<right<<setw(4)<<i+1<<left<<setw(4)<<" ";
            x.second.imprime(arch);
            i++;
        }
    }
}
void Camion::cargadeposito(NPedidos &pedido){
    if(pedido.GetPeso() + GetActCarga() <= GetMaxCarga()){
        int key =mdeposito.size();
        mdeposito[key]=pedido;
        double act = GetActCarga();
        act+=pedido.GetPeso();
        SetActCarga(act);
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
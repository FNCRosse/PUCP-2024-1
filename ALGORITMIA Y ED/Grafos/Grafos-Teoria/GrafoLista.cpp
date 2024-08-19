/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   GrafoLista.cpp
 * Author: Rosse
 * 
 * Created on 28 de junio de 2024, 11:11
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include "GrafoLista.h"

GrafoLista::GrafoLista(int ver) {
    lista.resize(ver);
}

void GrafoLista::AgregarArista(int u, int v) {
    lista[u].push_back(v);
    lista[v].push_back(u);
}

void GrafoLista::imprimirGrafo() {
    for(int i=0;i<lista.size();i++){
        cout<<i<<"->";
        for(int j=0; j<lista[i].size();j++){
            cout<<lista[i][j]<<" ";
        }
        cout<<endl;
    }
}
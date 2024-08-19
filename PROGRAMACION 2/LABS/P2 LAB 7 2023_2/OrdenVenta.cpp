/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.cc to edit this template
 */

/* 
 * File:   OrdenVenta.cpp
 * Author: Rosse
 * 
 * Created on 30 de mayo de 2024, 15:45
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "OrdenVenta.h"
#include "PrioridadAlta.h"

OrdenVenta::OrdenVenta(){
    ptr_orden = nullptr;
}
void OrdenVenta::LeerDatos(ifstream &arch,char tipo){
    if(tipo=='A'){
        ptr_orden = new PrioridadAlta;
        
    }else if(tipo=='M'){
        
    } else if(tipo=='B'){
        
    }
}

/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 15:11
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Libro.h"
#include "LibroSolicitados.h"
#include "Cliente.h"

int BuscarCliente(int dni,Cliente *ArrClientes,int nclientes){
    for(int i=0;i<nclientes;i++){
        if(dni == ArrClientes[i].GetDNI()) return i;
    } 
    return -1;
}
int main(int argc, char** argv) {
    int nLibros=0,nClientes=0;
    class Libro ArrLibros[500]{};
    class Cliente ArrClientes[500]{};
    class LibroSolicitado LibSol;
    ifstream archLibro; ofstream RepLibro;
    ifstream archCliente; ofstream RepCliente;
    ifstream archPed; ofstream RepFinal;
    AperturaDeUnArchivoDeTextosParaLeer(archLibro,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(RepLibro,"ReporteLibro.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archCliente,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(RepCliente,"PruebaCliente.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(RepFinal,"ReporteFinal.txt");
    
    while(true){
        archLibro>>ArrLibros[nLibros];
        if(archLibro.eof()) break;
        nLibros++;
    }
    while(true){
        archCliente>>ArrClientes[nClientes];
        if(archCliente.eof()) break;
        nClientes++;
    }
    int NumPedido,dni,posCliente;
    char c,Codigo[8];
    while(true){
        archPed>>NumPedido;
        if(archPed.eof()) break;
        archPed>>c>>dni>>c;
        posCliente = BuscarCliente(dni,ArrClientes,nClientes);
        if(posCliente != -1){
            while(true){
                archPed>>Codigo;
                LibSol.SetNumPedido(NumPedido);
                LibSol.SetCodigoLibro(Codigo);
                //Si puede atender o no el libro
                LibSol>>ArrLibros;
                //Colocar los libros en los clientes
                ArrClientes[posCliente]<<LibSol;
                if(archPed.get() == '\n') break;
            }
        } else{
            while(archPed.get() != '\n');
        }
    }
    //Imprimir
    for(int i=0;i<nLibros;i++){RepLibro<<ArrLibros[i];}
    for(int i=0;i<nClientes;i++){
        ++ArrClientes[i];
        RepFinal<<ArrClientes[i];
    }
    
    return 0;
}


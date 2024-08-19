/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 19:51
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Libro.h"
#include "LibroSolicitado.h"
#include "Cliente.h"
int BuscarCliente(int dni,Cliente *ArrClientes){
    for(int i=0;ArrClientes[i].GetDNI() != 0;i++){
        if(dni == ArrClientes[i].GetDNI()) return i;
    }
    return -1;
}
int main(int argc, char** argv) {
    int NLibros=0,NClientes=0;
    class Libro ArrLibros[500]{};
    class Cliente ArrClientes[500]{};
    class LibroSolicitado LibSol;
    ifstream ArchL,ArchC,ArchP;
    ofstream RepLibro,RepClientes;
    AperturaDeUnArchivoDeTextosParaLeer(ArchL,"Libros.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(RepLibro,"Reporte_Libros.txt");
    AperturaDeUnArchivoDeTextosParaLeer(ArchC,"Cientes.csv");
    AperturaDeUnArchivoDeTextosParaEscribir(RepClientes,"Reporte_Clientes.txt");
    AperturaDeUnArchivoDeTextosParaLeer(ArchP,"Pedidos.txt");
    while(true){
        ArchL>>ArrLibros[NLibros];
        if(ArchL.eof())  break;
        NLibros++;
    }
    while(true){
        ArchC>>ArrClientes[NClientes];
        if(ArchC.eof())  break;
        NClientes++;
    }
    int PosCliente,numPed,dni;
    char Codigo[8],c;
    while(true){
        ArchP>>numPed;
        if(ArchP.eof())  break;
        ArchP>>c>>dni>>c;
        PosCliente =BuscarCliente(dni,ArrClientes);
        if(PosCliente != -1){
            while(true){
                ArchP>>Codigo;
                if(ArchP.get() == '\n') break;
                LibSol.SetNumPedido(numPed);
                LibSol.SetCodigoLib(Codigo);
                LibSol>>ArrLibros;
                ArrClientes[PosCliente]<<LibSol;
            }
        } else {
            while(ArchP.get() != '\n');
        }
    }
    for(int i=0;i<NLibros;i++) RepLibro<<ArrLibros[i];
    for(int i=0;i<NClientes;i++) {
        ++ArrClientes[i];
        RepClientes<<ArrClientes[i];
    }
    return 0;
}


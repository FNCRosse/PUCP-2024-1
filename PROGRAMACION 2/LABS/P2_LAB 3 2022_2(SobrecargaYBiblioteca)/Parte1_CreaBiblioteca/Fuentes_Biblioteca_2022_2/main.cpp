/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 4 de abril de 2024, 09:29
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
#include "Sobrecargas.h"

int main(int argc, char** argv) {
    ifstream ArchM, ArchP, ArchC;
    ofstream ArchRep;
    AperturaDeUnArchivoDeTextosParaLeer(ArchM,"MedicosLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(ArchP,"PacientesLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(ArchC,"ConsultasLab3.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(ArchRep,"Prueba.txt");
     int cant=5;
    StMedico ArrMedico[cant];
    StPaciente ArrPaciente[cant];
    StCita cita;
    
    for(int i=0;i<cant;i++){
        ArchM>>ArrMedico[i];
        ArchP>>ArrPaciente[i];
    }
    ArrMedico[cant].codigo=0;
    
    while (true){
        int dni = ArchC>>cita;
        if(dni == -1) break;
        if( !(cita <= ArrMedico)) continue;
        int i=0;
        for(i=0; ArrPaciente[i].dni != dni and i<cant;i++ );
        if(i == cant) continue;
        ArrPaciente[i] += cita;
    }
    for(int i=0; i<cant;i++){
        ++ArrPaciente[i];
        ArchRep<<ArrPaciente[i];
    }
    return 0;
}


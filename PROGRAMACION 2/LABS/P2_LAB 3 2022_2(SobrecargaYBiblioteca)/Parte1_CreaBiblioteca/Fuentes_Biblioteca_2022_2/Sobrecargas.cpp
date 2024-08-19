/* 
 * File:   Sobrecargas.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 4 de abril de 2024, 15:19
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Estructuras.h"
#include "Sobrecargas.h"

bool operator >>(ifstream &arch, struct StMedico &medico){
    char nombEsp[150];
    arch>>medico.codigo;
    if(arch.eof()) return false;
    arch>>nombEsp>>medico.tarifaPoxConsulta;
    
    int i=0; //iterar hasta encontrar un _ y guardarlo si todas estas tienen mayus en nombre
    while((nombEsp[i] >= 'A' and nombEsp[i] <= 'Z' ) or (nombEsp[i] == '_')) i++;
    strncpy(medico.nombre,nombEsp,i-2);
    medico.nombre[strlen(medico.nombre)+1] = '\0';
    strncpy(medico.especialidad, nombEsp + i-1,strlen(nombEsp) - i+1);
    medico.especialidad[strlen(medico.especialidad)+1]  = '\0';
    return true;
}
bool operator >>(ifstream &arch, struct StPaciente &pac){
    char Nombre[60];
    arch>>pac.dni;
    if(arch.eof()) return false;
    arch>>Nombre>>pac.telefono;
    strcpy(pac.nombre,Nombre);
    pac.numeroDeCitas=0;
    pac.totalGastado=0;
    return true;
}
int operator >>(ifstream &arch, struct StCita &cita){
    int dni,anio,mes,dia;
    char c;
    arch>>dni;
    if(arch.eof()) return -1;
    arch>>cita.codigoDelMedico>>dia>>c>>mes>>c>>anio;
    cita.fecha = anio*10000+mes*100+dia;
    cita.tarifaPorConsulta = 0;
    return dni;
}

bool operator <=(struct StCita &cita, const struct StMedico *ArrMedicos){
    int i=0;
    while(ArrMedicos[i].codigo != 0){
        if(ArrMedicos[i].codigo == cita.codigoDelMedico){
            cita.tarifaPorConsulta = ArrMedicos[i].tarifaPoxConsulta;
            strcpy(cita.especialidad,ArrMedicos[i].especialidad);
            return true;
        }
        i++;
    }
    return false;
}
void operator += (struct StPaciente &Paciente, const struct StCita cita){
    Paciente.citas[Paciente.numeroDeCitas] = cita;
    Paciente.numeroDeCitas++;
}
StPaciente& operator ++(struct StPaciente &pac){
    for(int i=0;i<pac.numeroDeCitas;i++){
        pac.totalGastado += pac.citas[i].tarifaPorConsulta;
    }
}

void operator <<(ofstream &arch, const struct StPaciente &pac){
    arch.precision(2);
    arch<<fixed;
    arch<<right<<setw(5)<<"DNI"<<setw(20)<<"NOMBRE"<<setw(30)<<"TELEFONO"<<endl;
    arch<<left<<setw(15)<<pac.dni<<setw(30)<<pac.nombre<<pac.telefono<<endl;
    arch<<"RELACION DE CITAS"<<endl;
    arch<<"No."<<right<<setw(7)<<"FECHA"<<setw(20)<<"CODIGO DEL MEDICO"<<setw(18)
            <<"ESPECIALISTA"<<setw(10)<<"TARIFA"<<endl;
    for(int i=0;i<pac.numeroDeCitas;i++){
        arch<<i+1<<")   "<<left<<setw(20)<<pac.citas[i].fecha<<setw(15)<<pac.citas[i].codigoDelMedico<<setw(15)
        <<pac.citas[i].especialidad<<setw(25)<<pac.citas[i].tarifaPorConsulta<<endl;
    }
    arch<<"Monto Total Gastado: "<<pac.totalGastado<<endl;
}
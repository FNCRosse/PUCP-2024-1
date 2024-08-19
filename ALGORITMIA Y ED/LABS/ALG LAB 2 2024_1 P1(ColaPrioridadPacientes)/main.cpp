/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 27 de abril de 2024, 08:07 AM
 */

#include <iostream>
#include <fstream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

void CargarPacientesConPrioridad(Cola &colaPrio,const char*namefile){
    ifstream arch (namefile);
    struct Paciente paciente;
    int Fecha,dia, mes, anio;
    char extra;
    while(true){
        arch>>dia;
        if(arch.eof()) break;
        arch>>extra>>mes>>extra>>anio>>paciente.codigo;
        arch.get();
        Fecha = anio*10000+mes*100+dia;
        paciente.fecha = Fecha;
        //Esta funcion esta en funcionesCola.cpp
        encolarConPrioridad(colaPrio,paciente);
    }
}
int main(int argc, char** argv) {
    //Parte a
    //El struct Pacientes que he creado para manejar los datos se llama en la
    //funcion CargarPacientesConPrioridad
    /* Los cambios en el struct Lista
    struct Nodo * cola; //Este apuntara al final de la lista
    struct Nodo * colaMay; //Este apuntara al ultimo paciente mayor de 80 años
    struct Nodo * colaMen; //Este apuntara al ultimo paciente menor de 10 años
     */
    struct Cola colaPrio;//Cola de Pacientes con prioridad
    construir(colaPrio); 

    //Parte B
    CargarPacientesConPrioridad(colaPrio,"Datos.txt");
    imprime(colaPrio);
    return 0;
}


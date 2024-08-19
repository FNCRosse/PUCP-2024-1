/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 28 de marzo de 2024, 09:54
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "Personas.h"
#include "OperadoresSobreCargados.h"
#include "Templates.h"

int main(int argc, char** argv) {
    struct Persona empleados[100];
    int cantEmpleados=0;
    
    LeerDatos(empleados,cantEmpleados,"personas.csv");// >>
    MostrarDatos(empleados,cantEmpleados);// <<
    //Buscar un empleado
    int PosE, DniE = 18460279;
    PosE = Buscar(DniE,empleados,cantEmpleados); // ==
    if(PosE != -1){
        cout<<"Se ha encontrado el empleado con dni "<<DniE<<endl;
        cout<<empleados[PosE]<<endl;
    }
    else{
        cout<<endl<<"No se ha encontrado el empleado con dni "<<DniE<<endl;
    }
    //Las sobrecargas se aplican en el sueldo
    cout<<"++: ";
    empleados[0]++;
    ++empleados[0];
    cout<<empleados[0];
    
    cout<<"--: ";
    empleados[1]--;
    --empleados[1];
    cout<<empleados[1];
    
    cout<<"+:    "<<empleados[0].nombre<<" + "<<empleados[1].nombre<<" = ";
    Persona newEmpleado = empleados[0] + empleados[1];
    cout<<setw(37)<<newEmpleado.sueldo<<endl;
    
    cout<<"-:    "<<empleados[0].nombre<<" - "<<empleados[1].nombre<<" = ";
    Persona newEmpleado2 = empleados[0] - empleados[1];
    cout<<setw(37)<<newEmpleado2.sueldo<<endl;
    
    cout<<"*:    "<<empleados[0].nombre<<" * "<<empleados[1].nombre<<" = ";
    Persona newEmpleado3 = empleados[0] * empleados[1];
    cout<<setw(37)<<newEmpleado3.sueldo<<endl;
    
    cout<<"/:    "<<empleados[0].nombre<<" / "<<empleados[1].nombre<<" = ";
    Persona newEmpleado4 = empleados[0] / empleados[1];
    cout<<setw(37)<<newEmpleado4.sueldo<<endl;
    
    int porcetaje=20;
    cout<<"%:    "<<empleados[0].nombre<<" % "<<porcetaje<<" = ";
    Persona restante = empleados[0] % porcetaje;
    cout<<setw(49)<<restante.sueldo<<endl;
    

    
    

    return 0;
}


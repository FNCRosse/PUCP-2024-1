/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de abril de 2024, 14:23
 */

#include <iostream>
using namespace std;
#include "ListaDoble.h"
#include "FuncionesListaD.h"

int main(int argc, char** argv) {
    ListaD Equipos;
    Construir(Equipos);
    
    InsertarInicio(Equipos,{"GutterBall",9});
    InsertarInicio(Equipos,{"GutterBall",9});
    InsertarFinal(Equipos,{"KingPins",8});
    InsertarEnOrden(Equipos,{"Scorecards",7});
    InsertarEnOrden(Equipos,{"Scorecards",7});
    InsertarEnOrden(Equipos,{"Woodsplitters",10});
    InsertarEnOrden(Equipos,{"Woodsplitters",10});
    InsertarEnOrden(Equipos,{"Lions",4});
    mostrar(Equipos);
    cout <<endl;
    
//    EliminarNodo(Equipos,{"KingPins",5});
////    EliminarCabeza(Equipos);
//    EliminarCola(Equipos);
    EliminarRepetidos(Equipos);
    mostrar(Equipos);
    cout <<endl;
//    MostrarDesdeFinal(Equipos);
    
    InvertirIterativo(Equipos);
     mostrar(Equipos);
     cout <<endl;
     MostrarDesdeFinal(Equipos);
    return 0;
}


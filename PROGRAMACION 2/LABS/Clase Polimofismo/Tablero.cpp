
/* 
 * File:   Tablero.cpp
 * Author: Rosse
 * 
 * Created on 12 de junio de 2024, 09:09
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Ficha.h"
#include "Tablero.h"
#include "A.h"
#include "B.h"
#include "C.h"

Tablero::Tablero(){
    numFichas=0;
}
Tablero::~Tablero(){
    for(int i=0;i<numFichas;i++){
        delete ficha[i];
    }
}
void Tablero::leerFichas(ifstream&archF){
    char id[10],tipo;
    int fil, col;
    while(true){
        archF>>id;
        if(archF.eof()) break;
        archF>>tipo>>fil>>col;
        ColocarFicha(id,tipo,fil,col);
    }
}
void Tablero::ColocarFicha(char*id, char tipo, int fil, int col){
    switch(tipo){
        case 'A':
            ficha[numFichas]=new A;
            break;
        case 'B':
            ficha[numFichas] =  new B;
            break;
        case 'C':
            ficha[numFichas] = new C;
            break;
    }
    //Aqui no hay polimorfismo, por que no accedes al virtual de la ficha
    ficha[numFichas]->Asignar(id,fil,col);
    numFichas++;
}
void Tablero::leerMovimiento(ifstream &archM){
    char id[10],dir;
    int cant;
    while(true){
        archM>>id;
        if(archM.eof()) break;
        archM>>dir>>cant;
        MoverFicha(id,dir,cant);
    }
}
void Tablero::MoverFicha(char *id, char dir, int cant){
    char idTab[10];
    //Buscar la ficha en el tablero para moverla
    for(int fil=0; fil<numFichas;fil++){
        ficha[fil]->GetID(idTab);
        if(strcmp(id,idTab)==0){
            //Aplicamos polimorfismo
            ficha[fil]->mover(dir,cant);
            return;
        }
    }
}
void Tablero::imprimirDatos(ofstream &arch){
     for(int fil=0; fil<numFichas;fil++){
         ficha[fil]->imprime(arch);
     }
}
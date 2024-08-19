/* 
 * File:   FuncionesAux.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 26 de marzo de 2024, 16:54
 */
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#include "Controles.h"
#include "FuncionesAux.h"

void LeerDatos(Controles *controles,int CantControles){
    ifstream arch("Datos.txt",ios::in);
    int req;
    for(int i=0;i<CantControles;i++){
        int j=0;
        arch>>controles[i].id>>controles[i].inversion>>controles[i].Beneficio;
        while(true){
            arch>>req;
            if(req == 0) break;
            controles[i].Requisito[j]=req;
            j++;
        }
        controles[i].CantReq = j;
    }
    arch.close();
}
void CargaCombinaciones(int num,int *Combinaciones){
    int i=0;
    while (num>0) {
        Combinaciones[i++] = num %2;
        num = num/2;
    }
}
bool CumpleRequisitos(int *Combinaciones, Controles *controles,int CantControles,int pos){
    //Si no tiene requisitos pues pasa normal
    if(controles[pos].CantReq == 0) return true;
    //Si es que si tiene requisitos tengo ver que esos requisitos esten presentes
    int ReqEncontrados=0;
    for(int i=0;i<controles[pos].CantReq;i++){
        for(int j=0;j<CantControles;j++){
            int a = controles[pos].Requisito[i];
            int b = Combinaciones[j]*controles[j].id;
            int c= controles[j].id;
            if(controles[pos].Requisito[i] == Combinaciones[j]*controles[j].id) ReqEncontrados++;
        }
    }
    if(ReqEncontrados == controles[pos].CantReq) return true;
    else return false;
}
void ImprimirResultados(int *Combinaciones,Controles *controles,int CantControles,int Beneficio,int solucion){
    cout<<"La solucion es: "<<solucion<<endl;
    for(int i=0;i<CantControles;i++){
        if(Combinaciones[i] == 0) continue;
        cout<<"ID "<<controles[i].id<<" Inversion: "<<controles[i].inversion<<" Beneficio: "<<controles[i].Beneficio<<endl;
    }
    cout<<"El beneficio total de la solucion es: "<<Beneficio<<endl<<endl;
}
void Soluciones(Controles *controles,int CantControles,int Presupuesto){
    int Combinaciones[CantControles]={};
    int opciones = (int) pow(2,CantControles);
    int MaxBeneficio=0, IndiceBeneficioMax;
    int requisitosNoCumplidos=0;
    for(int i=0; i<opciones; i++){
        int PresupuestoParcial=0, GananciaParcial=0;
        CargaCombinaciones(i,Combinaciones);
        for(int j=0;j<CantControles;j++){
            if(Combinaciones[j] == 0) continue;
            if(!CumpleRequisitos(Combinaciones,controles,CantControles,j)) requisitosNoCumplidos++;
            PresupuestoParcial += controles[j].inversion;
            GananciaParcial += controles[j].Beneficio;
        }
        
        if(Presupuesto == PresupuestoParcial && requisitosNoCumplidos ==0){
            ImprimirResultados(Combinaciones,controles,CantControles,GananciaParcial,i);
        }
        if(MaxBeneficio<GananciaParcial && PresupuestoParcial<=Presupuesto){
            MaxBeneficio = GananciaParcial;
            IndiceBeneficioMax = i;
        }
    }
    
    cout<<"Mayor beneficio "<<endl;
    CargaCombinaciones(IndiceBeneficioMax,Combinaciones);
    ImprimirResultados(Combinaciones,controles,CantControles,MaxBeneficio,IndiceBeneficioMax);
    cout<<"Tiene un beneficio total de "<<MaxBeneficio<<endl;
}
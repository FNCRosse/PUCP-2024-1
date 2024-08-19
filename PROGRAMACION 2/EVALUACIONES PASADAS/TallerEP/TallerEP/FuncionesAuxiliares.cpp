/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"
#define MAX_LINE 120
void ingresoDeFecha(int &fechaSolicitada){
    int dd,mm,aa;
    char c;
    cout<<"Ingrese una fecha en formato dd/mm/aaaa "<<endl;
    cin>>dd>>c>>mm>>c>>aa;
    fechaSolicitada = aa*10000 + mm*100 + dd;
    
//    fechaSolicitada = 20190527;
    //27.05.2019
}
void emitirReporte(int fechaSolicitada,const char *nombArchFunc,const char *nombArchPeli,
        const char *nombArchSalas,const char *nombArchVentas,const char *nombArchReporte){
    ifstream archFunc(nombArchFunc,ios::in);
    if(not archFunc.is_open()){
        cout<<"ERROR: No se encontro el archivo"<<nombArchFunc;
        exit(1);
    }
    ifstream archPeli(nombArchPeli,ios::in);
    if(not archPeli.is_open()){
        cout<<"ERROR: No se encontro el archivo"<<nombArchPeli;
        exit(1);
    }
    ifstream archSalas(nombArchSalas,ios::in);
    if(not archSalas.is_open()){
        cout<<"ERROR: No se encontro el archivo"<<nombArchSalas;
        exit(1);
    }
    ifstream archVentas(nombArchVentas,ios::in);
    if(not archVentas.is_open()){
        cout<<"ERROR: No se encontro el archivo"<<nombArchVentas;
        exit(1);
    }
    ofstream archReporte(nombArchReporte,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se encontro el archivo"<<nombArchReporte;
        exit(1);
    }
    archReporte.precision(2);
    archReporte<<fixed;
    int codPelicula,ddIni,mmIni,aaIni,ddFin,mmFin,aaFin;
    int fechaIni,fechaFin,cantPeli=0;
    int cantFunc=0,totButDisp=0,totButVend=0,totButOcup=0;
    int totBut=0,totVend=0,totOcup=0;
    char c;
    double totRecau=0,porVent,porOcup;
    imprimirEncabezado(archReporte,fechaSolicitada);
    while(true){
        archPeli>>codPelicula;
        if(archPeli.eof())break;
        archPeli>>ddIni>>c>>mmIni>>c>>aaIni>>ddFin>>c>>mmFin>>c>>aaFin;
        fechaIni = aaIni*10000+mmIni*100+ddIni;
        fechaFin = aaFin*10000+mmFin*100+ddFin;
        if(fechaSolicitada>fechaIni and fechaFin>fechaSolicitada){
            archReporte<<"Pelicula: "<<codPelicula<<" - ";
            leerNombre(archPeli,archReporte);
            archReporte<<endl;
            imprimirLinea(archReporte,'-',MAX_LINE);
            archReporte<<"Cant.Funciones  Tot.Butacas.Disp   Tot.Butacas.Vend"
                    <<"   Tot.Butacas.Ocup.     %Venta     %Ocupacion"<<endl;
            buscarResto(fechaSolicitada,codPelicula,archFunc,archSalas,archVentas,archReporte,
                    cantFunc,totButDisp,totButVend,totButOcup,totRecau);
            porVent = ((double)totButVend/(double)totButDisp)*100;
            porOcup = ((double)totButOcup/(double)totButDisp)*100;
            archReporte<<"       "<<cantFunc<<setw(15)<<" "<<totButDisp<<setw(15)
                    <<" "<<totButVend<<setw(17)<<" "<<totButOcup<<setw(12)
                    <<" "<<porVent<<"%"<<setw(8)<<" "<<porOcup<<"%";
            totBut += totButDisp;
            totVend += totButVend;
            totOcup += totButOcup;
            cantPeli++;
            archReporte<<endl;
            imprimirLinea(archReporte,'-',MAX_LINE);
        }
        else{
            while(archPeli.get()!='\n');
        }
        
    }
    imprimirFinal(archReporte,totRecau,totBut,totVend,totOcup,cantPeli);
}
void imprimirLinea(ofstream &archReporte,char carac,int cant){
    for(int i=1;i<=cant;i++)
        archReporte.put(carac);
    archReporte<<endl;
}
void leerNombre(ifstream &archPeli,ofstream &archReporte){
    char c;
    archPeli>>ws;
    while(true){
        c = archPeli.get();
        if(c == '\n'){
            archPeli.unget();
            break;
        }
        cambiarCaracter(c);
        archReporte.put(c);
    }
}
void cambiarCaracter(char &c){
    if(c=='/') c=' '; 
}
void imprimirEncabezado(ofstream &archReporte,int fechaSolicitada){
    int dd,mm,aa;
    archReporte<<right<<setw(50)<<" "<<"REPORTE DE VENTAS Y OCUPACION DE SALAS"<<endl;
    archReporte<<setw(60)<<" "<<"Fecha: ";
    aa= fechaSolicitada/10000;
    mm = (fechaSolicitada%10000)/100;
    dd = (fechaSolicitada%10000)%100;
    archReporte<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa
            <<setfill(' ')<<endl;
    imprimirLinea(archReporte,'=',MAX_LINE);
}
void buscarResto(int fechaSol,int codPelicula,ifstream &archFunc,ifstream &archSalas,
        ifstream &archVentas,ofstream &archReporte,int &cantFunc,int &totButDisp,
        int &totButVend,int &totButOcup,double &totRecau){
    archFunc.clear();
    archFunc.seekg(0,ios::beg);
    int codPelRep,sala,hh,mm;
    char c;
    cantFunc=0;
    totButDisp = 0;
    totButOcup = 0;
    totButVend = 0;
    while(true){
        archFunc>>codPelRep;
        if(archFunc.eof())break;
        archFunc>>sala>>hh>>c>>mm;
        if(codPelRep == codPelicula){
            cantFunc++;
            buscarTotButDisp(sala,archSalas,totButDisp);
            leerVentas(sala,hh,mm,fechaSol,archVentas,totButOcup,totButVend,totRecau);
        }
    }
    
}
void buscarTotButDisp(int sala,ifstream &archSalas,int &totButDisp){
    archSalas.clear();
    archSalas.seekg(0,ios::beg);
    int salaRep,cantBut;
    while(true){
        archSalas>>salaRep;
        if(archSalas.eof())break;
        archSalas>>cantBut;
        if(salaRep == sala){
            totButDisp+=cantBut;
            break;
        }
        while(archSalas.get()!='\n');
    }
}
void leerVentas(int sala,int hor,int min,int fechaSol,ifstream &archVentas,int &totButOcup,
                                              int &totButVend,double &totRecau){
    archVentas.clear();
    archVentas.seekg(0,ios::beg);
    int salaRep,dia,mes,aa,fecha,hh,mm,butVend;
    double montRecau;
    char c;
    while(true){
        archVentas>>salaRep;
        if(archVentas.eof())break;
        archVentas>>dia>>c>>mes>>c>>aa;
        archVentas>>hh>>c>>mm;
        fecha = aa*10000 + mes*100 + dia;
        if(salaRep == sala and fecha == fechaSol and hh == hor and mm == min){
            archVentas>>montRecau>>butVend;
            totRecau += montRecau;
            totButVend += butVend;
            buscarButOcup(archVentas,totButOcup);
        }
        else{
            while(archVentas.get()!='\n');
        }
    }
}
void buscarButOcup(ifstream &archVentas,int &totButOcup){
    int num;
    char c;
    archVentas>>ws;
    while(true){
        archVentas>>c>>num;
        totButOcup++;
        
        if(archVentas.get()=='\n')break;
    }
    
}
void imprimirFinal(ofstream &archReporte,double totRecau,int totBut,int totVend,
        int totOcup,int cantPeli){
    double porVent,porOcup;
    porVent = ((double)totVend/(double)totBut)*100;
    porOcup = ((double)totOcup/(double)totBut)*100;
    imprimirLinea(archReporte,'=',MAX_LINE);
    archReporte<<"Cantidad de peliculas: "<<cantPeli<<endl;
    archReporte<<"Total Recaudacion ($/.): "<<totRecau<<endl;
    archReporte<<"% Venta total: "<<porVent<<"%"<<endl;
    archReporte<<"% Ocupacion total: "<<porOcup<<"%"<<endl;
}
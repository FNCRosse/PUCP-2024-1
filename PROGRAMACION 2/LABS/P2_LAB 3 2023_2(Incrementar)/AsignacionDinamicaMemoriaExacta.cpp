/* 
 * File:   AsignacionDinamicaMemoriaExacta.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 16 de abril de 2024, 11:36
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define INCREMENTO 5

void LecturaDeProductos(const char *namefile,char***&producto,int*&stock,double *&precios){
    ifstream arch (namefile,ios::in);
    int nDatos=0,cap=0,numstock;
    double precio;
    char ** DatosProd,*codigo,extra;
    producto = nullptr;
    stock = nullptr;
    precios = nullptr;
    while(true){
        codigo = LeerCadena(arch);
        if(arch.eof()) break;
        DatosProd = LeerDatosProducto(codigo,arch);
        arch>>precio>>extra>>numstock;
        arch.get();
        if(nDatos == cap) incrementarCapacidadProducto(cap,nDatos,producto,stock,precios);
        producto[nDatos-1] = DatosProd;
        stock[nDatos-1] = numstock;
        precios[nDatos-1] = precio;
        nDatos++;
    }
}
void PruebaDeLecturaDeProductos(const char *namefile,char***producto,int*stock,double *precios){
    ofstream arch (namefile,ios::out);
    char** datosProd;
    arch.precision(2);
    arch<<fixed;
    arch<<right<<setw(60)<<"REPORTE DE PRODUCTOS"<<endl;
    for(int i=0;producto[i];i++){
        datosProd = producto[i];
        arch<<left<<setw(10)<<datosProd[0]<<setw(60)<<datosProd[1]<<setw(5)<<stock[i]<<precios[i]<<endl;
    }
}

void LecturaDePedidos(const char *namefile,int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos){
    ifstream arch (namefile,ios::in);
    int nDatos=0,Cap=0,*N_CodPed,*Cap_CodPed,*N_DCP,*Cap_DCP;
    int dni,cant,fecha, dia,mes,anio,posFecha;
    char *Codigo,coma;
    fechaPedidos = nullptr;
    codigoPedidos = nullptr;
    dniCantPedidos = nullptr;
    while(true){
        Codigo = LeerCadena(arch);
        if(arch.eof()) break;
        arch>>dni>>coma>>cant>>coma>>dia>>coma>>mes>>coma>>anio;
        arch.get();
        fecha = anio * 10000 + mes*100+dia;
        posFecha = BuscarFecha(fechaPedidos,fecha);
        if(nDatos == Cap) IncrementarCapacidadPedidos(nDatos,Cap,fechaPedidos,codigoPedidos,dniCantPedidos,
                                                                                        N_CodPed,N_DCP,Cap_CodPed,Cap_DCP);
        if(posFecha != -1){
             ColocarCodPed(Codigo,N_CodPed[posFecha],Cap_CodPed[posFecha],codigoPedidos[posFecha]);
             ColocarDCP(dni,cant,N_DCP[posFecha],Cap_DCP[posFecha],dniCantPedidos[posFecha]);
        } else{
            fechaPedidos[nDatos-1] = fecha;
            ColocarCodPed(Codigo,N_CodPed[nDatos-1],Cap_CodPed[nDatos-1],codigoPedidos[nDatos-1]);
            ColocarDCP(dni,cant,N_DCP[nDatos-1],Cap_DCP[nDatos-1],dniCantPedidos[nDatos-1]);
            nDatos++;
        }
    }
    
}
void OrdenarPorFechas(int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos){
    int n=0;
    while(fechaPedidos[n]) n++;
    int Izq = 0,der =n-1;
    quick_Sort(fechaPedidos,codigoPedidos,dniCantPedidos,Izq,der);
}
void quick_Sort(int *fechaPedidos,char ***codigoPedidos,int ***dniCantPedidos,int Izq,int der){
    int Limite, pos;
    if( Izq > der ) return;
    pos = ( Izq + der)/2;
    cambiar(fechaPedidos[Izq],fechaPedidos[der],codigoPedidos[Izq],codigoPedidos[der],
                    dniCantPedidos[Izq],dniCantPedidos[der]);
    Limite = Izq;
    for(int i= Izq+1;i<=der;i++){
        if(fechaPedidos[i]<fechaPedidos[Izq]){
            Limite++;
            cambiar(fechaPedidos[Limite],fechaPedidos[i],codigoPedidos[Limite],codigoPedidos[i],
                    dniCantPedidos[Limite],dniCantPedidos[i]);
        }
    }
    cambiar(fechaPedidos[Limite],fechaPedidos[Izq],codigoPedidos[Limite],codigoPedidos[Izq],
                    dniCantPedidos[Limite],dniCantPedidos[Izq]);
    quick_Sort(fechaPedidos,codigoPedidos,dniCantPedidos,Izq,Limite-1);
    quick_Sort(fechaPedidos,codigoPedidos,dniCantPedidos,Limite+1,der);
}
void cambiar(int &fechaA,int &fechaB,char **&codPedA,char **&codPedB,int **&DCPA,int **&DCPB){
    int AuxFecha, **AuxDCP;
    char **AuxCod;
    AuxFecha = fechaA;
    fechaA = fechaB;
    fechaB = AuxFecha;
    
    AuxCod = codPedA;
    codPedA = codPedB;
    codPedB = AuxCod;
    
    AuxDCP = DCPA;
    DCPA = DCPB;
    DCPB = AuxDCP;
}
void PruebaDeLecturaDePedidos(const char *namefile,int *fechaPedidos,char ***codigoPedidos,
                                        int ***dniCantPedidos){
    ofstream arch (namefile,ios::out);
    char**DatosCodPed;
    int **DatosDCP,*DCP;
    for(int i=0;fechaPedidos[i];i++){
        DatosCodPed = codigoPedidos[i];
        DatosDCP =dniCantPedidos[i];
        arch<<fechaPedidos[i]<<endl;
        for(int k=0;DatosCodPed[k];k++){
            DCP = DatosDCP[k];
            arch<<right<<setw(15)<<DatosCodPed[k]<<setw(15)<<DCP[0]<<setw(5)<<DCP[1]<<endl;
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ReporteDeEnviosDePedidos(const char *namefile,char***producto,int*&stock,double *precios,
                                                 int *fechaPedidos,char ***codigoPedidos, int ***dniCantPedidos){
    ofstream arch (namefile,ios::out);
    arch<<right<<setw(70)<<"REPORTE DE ENTRADA DE PEDIDOS"<<endl;
    for(int i=0; fechaPedidos[i];i++){
        ImprimirLinea(arch,150,'=');
        arch<<left<<setw(8)<<"FECHA:"<<fechaPedidos[i]<<endl;
        ImprimirLinea(arch,150,'=');
        arch<<setw(25)<<"No.   DNI"<<setw(60)<<"Producto"<<setw(15)<<"Cantidad"<<setw(10)<<"Precio"<<
                "Total de ingreso"<<endl;
         ImprimirLinea(arch,150,'-');
        ImprimirPedidos(arch,dniCantPedidos[i],codigoPedidos[i],producto,stock,precios);
    }
}
void ImprimirLinea(ofstream &arch,int cant ,char letra){
    for(int i=0;i<cant;i++) arch<<letra;
    arch<<endl;
}
void ImprimirPedidos(ofstream &arch,int **dniCantPedidos,char **codigoPedidos,char ***producto,int *&stock, double *precio){
    int *DatosDCP,posProd;
    double montoIngresado=0,montoPerdido=0;
    char **DatosProducto;
    for(int i=0; codigoPedidos[i];i++){
        posProd = BuscarProducto(producto,codigoPedidos[i]);
        DatosProducto = producto[posProd];
        DatosDCP = dniCantPedidos[i];
        arch<<right<<setw(2)<<i+1<<")"<<setw(10)<<DatosDCP[0]<<setw(15)<<codigoPedidos[i]<<left<<"  "
                <<setw(55)<<DatosProducto[1]<<right <<setw(5)<<DatosDCP[1]<<setw(16)<<precio[posProd];
        VerificacionStockyCalculoIngreso(arch,precio[posProd],DatosDCP[1],stock[posProd],montoIngresado,montoPerdido);
    }
     ImprimirLinea(arch,150,'-');
     arch<<left<<setw(50)<<"Total Ingresado:"<<montoIngresado<<endl;
     arch<<left<<setw(50)<<"Total perdido por falta de stock:"<<montoPerdido<<endl;
}
int BuscarProducto(char ***producto,char *codigoPedidos){
    for(int i=0;producto[i];i++){
        char **Datos = producto[i];
        if(strcmp(Datos[0],codigoPedidos)==0) return i;
    }
    return -1;
}
void VerificacionStockyCalculoIngreso(ofstream &arch,double precio, int cantidad,int &stock,
        double &montoIngresado,double &montoPerdido){
    if(stock>0){
        stock -= cantidad;
        montoIngresado += precio *cantidad;
        arch<<setw(15)<<precio *cantidad<<endl;
    } else{
        stock =0;
        montoPerdido += precio*cantidad;
        arch<<setw(15)<<"SIN STOCK"<<endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* LeerCadena(ifstream & arch){
    char cadena[60], *ptrCad;
    arch.getline(cadena,60,',');
    ptrCad = new char [strlen(cadena)+1];
    strcpy(ptrCad,cadena);
    return ptrCad;
}
char** LeerDatosProducto(char *codigo,ifstream &arch){
    char **DatosPr = new char *[2];
    DatosPr[0] = codigo;
    DatosPr[1] = LeerCadena(arch);
    return DatosPr;
}
void incrementarCapacidadProducto(int &cap,int &nDatos,char***&producto,int*&stock,double *&precios){
    //Crear auxiliares de nuestros datos
    char *** AuxProd;
    int * AuxStock;
    double *AuxPrecios;
    cap += INCREMENTO;
    if(producto == nullptr){//Si es el primer elemento
        producto = new char **[cap]{};
        stock = new int [cap]{};
        precios = new double [cap]{};
        nDatos =1;
    }
    else{
        AuxProd = new char **[cap]{};
        AuxStock = new int [cap]{};
        AuxPrecios = new double [cap]{};
        for(int i=0;i<nDatos;i++){
            AuxProd[i] = producto[i];
            AuxStock[i] = stock[i];
            AuxPrecios[i] = precios[i];
        }
        delete producto;
        delete stock;
        delete precios;
        producto  = AuxProd;
        stock = AuxStock;
        precios = AuxPrecios;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BuscarFecha(int *&fechaPedidos,int fecha){
    if(fechaPedidos == nullptr) return -1;
    for(int i=0; fechaPedidos[i];i++){
        if( fechaPedidos[i] == fecha) return i;
    }
    return -1;
}
void IncrementarCapacidadPedidos(int &nDatos,int &cap,int *&fechaPedidos,char ***&codigoPedidos,
                                        int ***&dniCantPedidos,int *&N_CodPed,int *&N_DCP,int *&Cap_CodPed,int *&Cap_DCP){
    int *AuxFecha, ***AuxDCP,*Aux_NCodPed,*Aux_NDCP,*AuxCapCodPed,*AuxCapDCP;
    char ***AuxCod;
    cap += INCREMENTO;
    if(fechaPedidos == nullptr){
        fechaPedidos =  new int [cap]{};
        codigoPedidos = new char **[cap]{};
        dniCantPedidos =  new int **[cap]{};
        N_CodPed = new int [cap]{}; N_DCP = new int [cap]{};
        Cap_CodPed = new int [cap]{}; Cap_DCP = new int [cap]{};
        nDatos =1;
    }
    else{
        AuxFecha =  new int [cap]{};
        AuxCod = new char **[cap]{};
        AuxDCP =  new int **[cap]{};
        Aux_NCodPed = new int [cap]{}; Aux_NDCP = new int [cap]{};
        AuxCapCodPed = new int [cap]{}; AuxCapDCP = new int [cap]{};
        for(int i=0;i< nDatos;i++){
            AuxFecha[i] =  fechaPedidos [i];
            AuxCod[i] = codigoPedidos[i];
            AuxDCP[i] =  dniCantPedidos[i];
            Aux_NCodPed[i] = N_CodPed[i]; Aux_NDCP[i] = N_DCP[i];
            AuxCapCodPed[i] = Cap_CodPed[i]; AuxCapDCP[i] = Cap_DCP[i];
        }
        delete fechaPedidos;
        delete codigoPedidos;
        delete dniCantPedidos;
        delete N_CodPed; delete N_DCP;
        delete Cap_CodPed; delete Cap_DCP;
        fechaPedidos =AuxFecha;
        codigoPedidos = AuxCod;
        dniCantPedidos=AuxDCP;
        N_CodPed = Aux_NCodPed ; N_DCP = Aux_NDCP ;
        Cap_CodPed = AuxCapCodPed ;  Cap_DCP = AuxCapDCP ;
    }
}
void ColocarCodPed(char *Codigo,int &N_CodPed,int &Cap_CodPed,char**&codigoPedidos){
    if(N_CodPed == Cap_CodPed) IncrementarEspacios(codigoPedidos,N_CodPed,Cap_CodPed);
    codigoPedidos[N_CodPed-1] = Codigo;
    N_CodPed++;
}
void ColocarDCP(int dni,int cant,int &N_DCP,int &Cap_DCP,int **&dniCantPedidos){
    if(N_DCP == Cap_DCP) IncrementarEspacios(dniCantPedidos,N_DCP,Cap_DCP);
    int *Datos = new int [2];
    Datos[0] = dni;
    Datos[1] = cant;
    dniCantPedidos[N_DCP-1] = Datos;
    N_DCP++;
}
void  IncrementarEspacios(char **&codigoPedidos,int &nDatos,int &Cap){
    Cap += INCREMENTO;
    if(codigoPedidos == nullptr){
        codigoPedidos = new char*[Cap]{};
        nDatos =1;
    } else{
        char ** AuxCodPed = new char*[Cap]{};
        for(int i=0; i<nDatos ;i++){
            AuxCodPed[i] = codigoPedidos[i];
        }
        delete codigoPedidos;
        codigoPedidos = AuxCodPed;
    }
}
void  IncrementarEspacios(int  **&dniCantPedidos,int &nDatos,int &Cap){
    Cap += INCREMENTO;
    if(dniCantPedidos == nullptr){
        dniCantPedidos = new int*[Cap]{};
        nDatos =1;
    } else{
        int ** AuxDCP = new int*[Cap]{};
        for(int i=0; i<nDatos ;i++){
            AuxDCP[i] = dniCantPedidos[i];
        }
        delete dniCantPedidos;
        dniCantPedidos = AuxDCP;
    }
}
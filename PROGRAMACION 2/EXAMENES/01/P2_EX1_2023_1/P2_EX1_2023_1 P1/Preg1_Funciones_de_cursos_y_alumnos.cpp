/* 
 * File:   Preg1_Funciones_de_cursos_y_alumnos.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 13 de mayo de 2024, 17:40
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Preg1_Funciones_de_cursos_y_alumnos.h"
#define INCREMENTAR 5

void cargasCursosYEscalas (char***&Cursos,double *&Cursos_cred,double *escalas,const char* namefile,
        const char* namefile2){
    ifstream archCurso (namefile);
    ifstream archEscalas (namefile2);
    Cursos = nullptr;
    Cursos_cred = nullptr;
    int ndatos=0,cap=0;
    char *codigo,*nomCurso,*nomProfe,extra;
    double creditos,escala;
    int codProfe,posicion;
    while(true){
        codigo = LeerCadena(archCurso,',');
        if(archCurso.eof()) break;
         nomCurso = LeerCadena(archCurso,',');
         archCurso>>creditos>>extra>>codProfe>>extra;
         nomProfe = LeerCadena(archCurso,'\n');
         if(ndatos == cap) IncrementarEspacios(Cursos,Cursos_cred,ndatos,cap);
         Cursos[ndatos-1] = ColocarDatosCurso(codigo,nomCurso,nomProfe);
         Cursos_cred[ndatos-1] = creditos;
         ndatos++; 
    }
    while(true){
        archEscalas>>extra;
        if(archEscalas.eof())break;
        archEscalas>>posicion>>extra>>escala;
        archEscalas.get();
        escalas[posicion-1] = escala;
    }
}
char *LeerCadena(ifstream &arch,char c){
    char cadena[110],*PtrCadena;
    arch.getline(cadena,110,c);
    PtrCadena = new char[strlen(cadena)+1];
    strcpy(PtrCadena,cadena);
    return PtrCadena;
}
void IncrementarEspacios(char***&Cursos,double *&Cursos_cred,int &ndatos,int& cap){
    cap += INCREMENTAR;
    if(Cursos ==nullptr){
        Cursos_cred = new double [cap]{};
        Cursos = new char**[cap]{};
        ndatos=1;
    }else{
        char***AuxCurso = new char**[cap]{};
        double*AuxCreditos = new double [cap]{};
        for(int i=0;i<ndatos;i++){
            AuxCreditos[i] = Cursos_cred[i];
            AuxCurso[i] = Cursos[i];
        }
        delete Cursos;
        delete Cursos_cred;
        Cursos = AuxCurso;
        Cursos_cred = AuxCreditos;
    }
}
char ** ColocarDatosCurso(char *codigo,char *nomCurso,char* nomProfe){
    char **Datos = new char*[3]{};
    Datos[0] = codigo;
    Datos[1] = nomCurso;
    Datos[2] = nomProfe;
    return Datos;
}
void pruebaDeCargaDeCursos(char ***Cursos,double *Cursos_cred,const char* namefile){
    ofstream arch (namefile);
    arch.precision(2);
    arch<<fixed;
    for(int i=0;Cursos[i];i++){
        char**DatoCurso = Cursos[i];
        arch<<left<<setw(12)<<DatoCurso[0]<<setw(60)<<DatoCurso[1]<<setw(60)<<DatoCurso[2]<<Cursos_cred[i]<<endl;
    }
}

void CargaAlumnos(int *&alumnos_cod,int **&Alumnos,char***&Alumnos_nom_mod,const char* namefile){
     ifstream arch(namefile);
    alumnos_cod = nullptr;
    Alumnos = nullptr;
    Alumnos_nom_mod = nullptr;
    int ndatos=0,cap=0;
    char *nombAlumno,modalidad,extra;
    int codAlumno,porcentaje=0,escala;
    while(true){
        arch>>codAlumno;
        if(arch.eof()) break;
        arch.get();
         nombAlumno = LeerCadena(arch,',');
         arch>>modalidad;
         if(modalidad == 'S'){
             arch>>extra>>porcentaje>>extra>>extra>>escala;
         } else if(modalidad == 'V'){
              arch>>extra>>extra>>escala;
         } else {
             arch>>escala;
         }
         arch.get();
         if(ndatos == cap) IncrementarEspaciosAlumnos(alumnos_cod,Alumnos,Alumnos_nom_mod,ndatos,cap);
         alumnos_cod[ndatos-1] = codAlumno;
         Alumnos[ndatos-1] = ColocarDatosAlumno(codAlumno,escala,porcentaje);
         Alumnos_nom_mod[ndatos-1] = ColocarNombYModAlumno(nombAlumno,modalidad);
         ndatos++; 
    }
}
void IncrementarEspaciosAlumnos(int *&alumnos_cod,int **&Alumnos,char***&Alumnos_nom_mod,int &ndatos,int &cap){
    cap += INCREMENTAR;
    if(alumnos_cod ==nullptr){
        alumnos_cod = new int [cap]{};
        Alumnos = new int*[cap]{};
        Alumnos_nom_mod = new char**[cap]{};
        ndatos=1;
    }else{
        int*AuxCod = new int [cap]{};
        int**AuxAlumnos = new int*[cap]{};
        char***AuxNomMod = new char**[cap]{};
        for(int i=0;i<ndatos;i++){
            AuxCod[i] = alumnos_cod[i];
            AuxAlumnos[i] = Alumnos[i];
            AuxNomMod[i] = Alumnos_nom_mod[i];
        }
        delete alumnos_cod;
        delete Alumnos;
        delete Alumnos_nom_mod;
        alumnos_cod = AuxCod;
        Alumnos = AuxAlumnos;
        Alumnos_nom_mod = AuxNomMod;
    }
}
int *ColocarDatosAlumno(int codAlumno,int escala,int porcentaje){
    if(porcentaje == 0){
        int *datos = new int[2]{};
        datos[0] = codAlumno;
        datos[1] = escala;
        return datos;
    } else {
        int *datos = new int[3]{};
        datos[0] = codAlumno;
        datos[1] = escala;
        datos[2] = porcentaje;
        return datos;
    }
}
char ** ColocarNombYModAlumno(char *nombAlumno,const char modalidad){
    char ** datos = new char*[2]{};
    char mod_str[2];
    mod_str[0] = modalidad;
    mod_str[1] = '\0';
    char *mod = mod_str;
    datos[0] = nombAlumno;
    datos[1] = mod;
    return datos;
}
void pruebaDeCargaAlumnos(int *alumnos_cod,int **Alumnos,char***Alumnos_nom_mod,const char *namefile){
    ofstream arch (namefile);
    for(int i=0;alumnos_cod[i];i++){
        int* datoAlumno = Alumnos[i];
        char **DatostxtAlumno = Alumnos_nom_mod[i];
 
        arch<<left<<setw(15)<<datoAlumno[0]<<setw(50)<<DatostxtAlumno[0]<<setw(10)<<datoAlumno[1]<<
                setw(5)<<DatostxtAlumno[1];
        if(strcmp(DatostxtAlumno[1],"S")==0) arch<<datoAlumno[2]<<endl;
        else arch<<endl;
    }
}
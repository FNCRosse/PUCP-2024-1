/* 
 * File:   SobreCarga.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 2 de abril de 2024, 11:29
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Estructuras.h"
using namespace std;

bool operator >> (ifstream &arch, struct StCurso &curso){
    char codCurso[7],nomCurso[60],nomProfesor[60];
    double creditos;
    int codProf;
    arch>>codCurso;
    if(arch.eof()) return false;
    arch>>nomCurso>>creditos>>codProf>>nomProfesor;
    
    strcpy(curso.codigoDelCurso,codCurso);
    strcpy(curso.nombreDelCurso, nomCurso);
    strcpy(curso.nombreDelProfesor,nomProfesor);
    curso.creditos = creditos;
    curso.codigoDelProfesor = codProf;
    curso.numeroDeAlumnos=0;
    curso.ingresos=0;
    return true;
}
bool operator >> (ifstream &arch, struct StAlumno &alumno){
    int semestre, cod,porcentaje,escala;
    char nomb[60],mod,c;
    
    arch>>semestre;
    if(arch.eof()) return false;
    arch>>c>>cod>>nomb>>mod;
    if(mod =='G'){ // Es presencial
        strcpy(alumno.modalidad,"PRESENCIAL");
        arch>>escala;
    }
    else if(mod == 'V'){
        strcpy(alumno.modalidad,"VIRTUAL");
        arch>>c>>escala;
    }
    else if(mod == 'S'){
        strcpy(alumno.modalidad,"SEMI PRESENCIAL");
        arch>>porcentaje>>c>>escala;
        alumno.porcentaje =porcentaje;
    }
    alumno.semestre=semestre;
    alumno.codigo =cod;
    strcpy(alumno.nombre,nomb);
    alumno.escala = escala;
    alumno.numeroDeCursos=0;
    alumno.costoTotal=0;
    return true;
}
bool operator >> (ifstream &arch, struct StRegistroDeMatricula &reg){
    char cod[7],c;
    int semestre,codAlumno;
    arch>>cod;
    if(arch.eof()) return false;
    arch>>semestre>>c>>codAlumno;
    
    strcpy(reg.codigoDelCurso,cod);
    reg.codigodelAlumno = codAlumno;
    reg.semestreDelAlumno=semestre;
    return true;
}

void operator += (struct StCurso *ArrCurso, const StCurso &curso){
    int i=0;
    while(true){
        if(strcmp(ArrCurso[i].codigoDelCurso,"XXXXXX") == 0) break;
        i++;
    }
    strcpy(ArrCurso[i].codigoDelCurso,curso.codigoDelCurso);
    strcpy(ArrCurso[i].nombreDelCurso,curso.nombreDelCurso);
    ArrCurso[i].creditos = curso.creditos;
    ArrCurso[i].codigoDelProfesor = curso.codigoDelProfesor;
    strcpy(ArrCurso[i].nombreDelProfesor,curso.nombreDelProfesor);
    for(int j=0;j<curso.numeroDeAlumnos;j++){
        ArrCurso[i].alumnos[j] = curso.alumnos[j];
    }
    ArrCurso[i].numeroDeAlumnos = curso.numeroDeAlumnos;
    ArrCurso[i].ingresos = curso.ingresos;
    strcpy(ArrCurso[++i].codigoDelCurso,"XXXXXX");
}
void operator += (struct StAlumno *ArrAlumno, const StAlumno &alumno){
    int i=0;
    for(i=0;ArrAlumno[i].semestre != 0; i++);
     ArrAlumno[i].semestre = alumno.semestre;
     ArrAlumno[i].codigo = alumno.codigo;
     strcpy(ArrAlumno[i].nombre,alumno.nombre);
     strcpy(ArrAlumno[i].modalidad,alumno.modalidad);
     ArrAlumno[i].porcentaje = alumno.porcentaje;
     ArrAlumno[i].escala = alumno.escala;
     for(int j=0; j<alumno.numeroDeCursos;j++){
         ArrAlumno[i].cursos[j] = new char [strlen(alumno.cursos[j])+1];
         strcpy(ArrAlumno[i].cursos[j],alumno.cursos[j]);
     }
     ArrAlumno[i].numeroDeCursos = alumno.numeroDeCursos;
     ArrAlumno[i].costoTotal = alumno.costoTotal;
     ArrAlumno[++i].semestre = 0;
}

void operator *=(struct StCurso * ArrCurso, const StRegistroDeMatricula &RegMat){
    int i=0;
    while(true){
         if(strcmp(ArrCurso[i].codigoDelCurso,"XXXXXX") == 0) break;
         if(strcmp(ArrCurso[i].codigoDelCurso,RegMat.codigoDelCurso) == 0){
             int alumno = RegMat.semestreDelAlumno*10000 + RegMat.codigodelAlumno;
             ArrCurso[i].alumnos[ArrCurso[i].numeroDeAlumnos] = alumno;
             ArrCurso[i].numeroDeAlumnos++;
             break;
         }
        i++;
    }
}
void operator *=(struct StAlumno *ArrAlumno, const StRegistroDeMatricula &RegMat){
    int i=0;
    while(true){
        StAlumno a = ArrAlumno[i];
        if(ArrAlumno[i].semestre == 0) break; 
        if(ArrAlumno[i].codigo == RegMat.codigodelAlumno && ArrAlumno[i].semestre == RegMat.semestreDelAlumno){
             ArrAlumno[i].cursos[ArrAlumno[i].numeroDeCursos] = new char [strlen(RegMat.codigoDelCurso)+1];
             strcpy(ArrAlumno[i].cursos[ArrAlumno[i].numeroDeCursos],RegMat.codigoDelCurso);
             ArrAlumno[i].numeroDeCursos++;
             StAlumno b = ArrAlumno[i];
             break;
         }
        i++;
    }
}

void operator << (ofstream &arch, const struct StCurso &curso){
    arch<<left<<setw(17)<<"  CODIGO"<<setw(48)<<"NOMBRE"<<"CREDITOS"<<endl;
    arch<<"  "<<left<<setw(15)<<curso.codigoDelCurso<<setw(50)<<curso.nombreDelCurso<<curso.creditos<<endl;
    arch<<"  Profesor:  "<<setw(40)<<curso.nombreDelProfesor<<"["<<curso.codigoDelProfesor<<"]"<<endl;
    arch<<"  Alumnos matriculados: "<<endl;
    arch<<setw(15)<<"  Semetre"<<"Codigo"<<endl;
    for(int i=0;i< curso.numeroDeAlumnos; i++){
        arch<<right<<setw(9)<<curso.alumnos[i]/1000<<setw(10)<<curso.alumnos[i]%10000<<endl;
    }
    arch<<"  Numero de alumnos: "<<curso.numeroDeAlumnos<<endl;
    arch<<"  Total ingresados: "<<endl;
}
void operator << (ofstream &arch, const struct StAlumno &alumno){
    arch<<left<<setw(13)<<"  SEMESTRE"<<setw(10)<<"CODIGO"<<setw(30)<<"NOMBRE"<<setw(25)
            <<"MODALIDAD"<<"ESCALA"<<endl;
    arch<<"  "<<setw(12)<<alumno.semestre<<setw(9)<<alumno.codigo<<setw(30)<<alumno.nombre<<setw(18)
            <<alumno.modalidad;
    if(strcmp(alumno.modalidad,"SEMI PRESENCIAL") ==0){
        arch<<"CON "<<alumno.porcentaje<<setw(10)<<"%"<<alumno.escala<<endl;
    }
    else{
        arch<<right<<setw(11)<<alumno.escala<<endl;
    }
    arch<<"  Codigos de cursos matriculados:"<<endl;
    for(int i=0;i<alumno.numeroDeCursos;i++) arch<<right<<setw(15)<<alumno.cursos[i]<<endl;
    arch<<"  Numero de Cursos: "<<alumno.numeroDeCursos<<endl;
    arch<<"  Costo Total: "<<endl;
}
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Facultad.h
 * Author: Rosse
 *
 * Created on 8 de julio de 2024, 17:17
 */

#ifndef FACULTAD_H
#define FACULTAD_H
#include "Util.h"
#include "ListaDoble.h"

class Facultad{
private:
    class ListaDoble alumnosxNotas;
public:
    void LeerAlumnosNotas(const char* namefile1,const char* namefile2);
    void ImprimeAlumnosNotas(const char* namefile);
};
#endif /* FACULTAD_H */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   medico.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 16:09
 */

#ifndef MEDICO_H
#define MEDICO_H

class medico{
private:
    int codigo;
    char* nombre;
    char * especialidad;
public:
    medico();
    void SetEspecialidad(const char* especialidad);
    void GetEspecialidad(char *cad) const;
    void SetNombre(const char* nombre);
    void GetNombre(char *cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void LeerDatos(ifstream &arch);
    void Imprimir(ofstream &arch);
};
#endif /* MEDICO_H */

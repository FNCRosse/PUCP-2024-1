/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   NEstante.h
 * Author: Rosse
 *
 * Created on 9 de julio de 2024, 05:49
 */

#ifndef NESTANTE_H
#define NESTANTE_H
#include "Util.h"
#include "NLibro.h"
#include "Arbol.h"
class NEstante{
private:
    int id;
    double capacidad;
    double disponible;
    vector<class NLibro> vlibros;
    class NEstante *izq;
    class NEstante *der;
public:
    NEstante();
    void SetDer(NEstante* der);
    NEstante* GetDer() const;
    void SetIzq(NEstante* izq);
    NEstante* GetIzq() const;
    void SetVlibros(vector<NLibro> vlibros);
    vector<NLibro> GetVlibros() const;
    void SetDisponible(double disponible);
    double GetDisponible() const;
    void SetCapacidad(double capacidad);
    double GetCapacidad() const;
    void SetId(int id);
    int GetId() const;
    
    bool LeerDatos(ifstream &arch);
    void LeerLibros(ifstream &arch);
    void imprimeDatos(ofstream &arch);
    friend class Arbol;
};
#endif /* NESTANTE_H */

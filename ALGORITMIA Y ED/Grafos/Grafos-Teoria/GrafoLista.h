/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   GrafoLista.h
 * Author: Rosse
 *
 * Created on 28 de junio de 2024, 11:11
 */

#ifndef GRAFOLISTA_H
#define GRAFOLISTA_H

class GrafoLista{
private:
    vector<vector<int>> lista;
public:
    GrafoLista(int ver);
    void AgregarArista(int u, int v);
    void imprimirGrafo();
};
#endif /* GRAFOLISTA_H */

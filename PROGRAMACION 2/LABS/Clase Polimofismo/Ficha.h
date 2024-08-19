/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file_header.h to edit this template
 */

/* 
 * File:   Ficha.h
 * Author: Rosse
 *
 * Created on 12 de junio de 2024, 08:49
 */

#ifndef FICHA_H
#define FICHA_H
class Ficha{
private:
    char *ID;
    int fila;
    int col;
public:
    Ficha();
    virtual ~Ficha();
    void SetCol(int col);
    int GetCol() const;
    void SetFila(int fila);
    int GetFila() const;
    void SetID(const char* ID);
    void  GetID(char *) const;
    //////////////////////////////////////////
    void Asignar(char *, int , int);
    virtual void imprime(ofstream &)=0;
    virtual void mover(char, int)=0;
};
#endif /* FICHA_H */

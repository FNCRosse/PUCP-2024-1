/* 
 * File:   Espacio.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 10:03
 */

#ifndef ESPACIO_H
#define ESPACIO_H

class Espacio{
private:
    char contenido;
    int PosX;
    int PosY;
public:
    Espacio();
    void SetPosY(int PosY);
    int GetPosY() const;
    void SetPosX(int PosX);
    int GetPosX() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    void Imprimir (ofstream &arch);
};
void operator << (ofstream &arch,Espacio Es);

#endif /* ESPACIO_H */


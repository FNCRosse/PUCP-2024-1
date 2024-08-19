/* 
 * File:   Libro.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 30 de mayo de 2024, 09:24
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro{
private:
    char *Codigo;
    char *Nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* Nombre);
    void GetNombre(char *cad) const;
    void SetCodigo(const char* Codigo);
    void GetCodigo(char *cad) const;
    
    void LeerDatos(ifstream &);
    void Imprimir (ofstream &);
    
};
void operator >> (ifstream &,Libro &L);
void operator << (ofstream &,Libro L);
#endif /* LIBRO_H */


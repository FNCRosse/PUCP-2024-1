/* 
 * File:   Libro.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 15:13
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro{
    private: 
        char *Codigo;
        char *Titulo;
        char* Autor;
        int stock;
        double Precio;
public:
    Libro();
    void Leer(ifstream &);
    void SetPrecio(double Precio);
    double GetPrecio() const;
    void SetStock(int stock);
    int GetStock() const;
    void SetAutor(const char* Autor);
    void  GetAutor(char*) const;
    void SetTitulo(const char* Titulo);
    void GetTitulo(char*) const;
    void SetCodigo(const char* Codigo);
    char* GetCodigo() const;

};

void operator >>(ifstream &arch,Libro &L);
void operator <<(ofstream &arch,Libro L);
#endif /* LIBRO_H */


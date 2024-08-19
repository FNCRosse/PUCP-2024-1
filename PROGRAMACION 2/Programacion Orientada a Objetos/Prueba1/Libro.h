/* 
 * File:   Libro.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 23 de mayo de 2024, 19:52
 */

#ifndef LIBRO_H
#define LIBRO_H

class Libro{
private:
    char *Codigo;
    char* Titulo;
    char* Autor;
    int Stock;
    double Precio;
public:
    Libro();
    void SetPrecio(double Precio);
    double GetPrecio() const;
    void SetStock(int Stock);
    int GetStock() const;
    void SetAutor(const char* Autor);
    char* GetAutor() const;
    void SetTitulo(const char* Titulo);
    char* GetTitulo() const;
    void SetCodigo(const char* Codigo);
    char* GetCodigo() const;
    
    void Leer(ifstream &);
};

void operator >>(ifstream &arch, Libro &L);
void operator <<(ofstream &arch, Libro L);

#endif /* LIBRO_H */


/* 
 * File:   Alumno.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:48
 */

#ifndef ALUMNO_H
#define ALUMNO_H

class Alumno {
private:
    int codigo;
    char *Nombre;
    int escala;
    double total;
public:
    Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* Nombre);
    void GetNombre(char *&cad) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    void LeerDatos(ifstream &arch);
    void Imprime(ofstream &arch);
};

#endif /* ALUMNO_H */


/* 
 * File:   SemiPresencial.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:58
 */

#ifndef SEMIPRESENCIAL_H
#define SEMIPRESENCIAL_H
#include "Alumno.h"
class SemiPresencial : public Alumno{
    private:
        double descuento;
        double total;
    public:
        SemiPresencial();
        void SetTotal(double total);
        double GetTotal() const;
        void SetDescuento(double descuento);
        double GetDescuento() const;
        
        void LeerDatos(ifstream &arch);
        void Actualiza(double monto);
        void Imprimir(ofstream &arch);
};

#endif /* SEMIPRESENCIAL_H */


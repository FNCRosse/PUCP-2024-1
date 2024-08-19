/* 
 * File:   Presencial.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 19:55
 */

#ifndef PRESENCIAL_H
#define PRESENCIAL_H
#include "Alumno.h"
class Presencial : public Alumno{
    private:
        double recargo;
        double total;
    public:
        Presencial();
        void SetTotal(double total);
        double GetTotal() const;
        void SetRecargo(double recargo);
        double GetRecargo() const;
        
        void LeerDatos(ifstream &arch);
        void Actualiza(double monto);
        void Imprimir(ofstream &arch);
};
#endif /* PRESENCIAL_H */


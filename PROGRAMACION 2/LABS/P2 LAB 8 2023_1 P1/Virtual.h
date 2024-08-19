/* 
 * File:   Virtual.h
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 29 de mayo de 2024, 20:01
 */

#ifndef VIRTUAL_H
#define VIRTUAL_H
#include "Alumno.h"

class Virtual: public Alumno{
    private:
        char *Licencia;
        double total;
    public:
        Virtual();
        void SetTotal(double total);
        double GetTotal() const;
        void SetLicencia(const char* Licencia);
        void GetLicencia(char *&cad) const;
        
        void LeerDatos(ifstream &arch);
        void Actualiza(double monto);
        void Imprimir(ofstream &arch);
};


#endif /* VIRTUAL_H */


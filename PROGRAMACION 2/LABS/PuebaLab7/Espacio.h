
/* 
 * File:   Espacio.h
 * Author: Rosse
 *
 * Created on 30 de mayo de 2024, 20:50
 */

#ifndef ESPACIO_H
#define ESPACIO_H

class Espacio{
private:
    char contenido;
    int posx;
    int posy;
public:
    Espacio();
    void SetPosy(int posy);
    int GetPosy() const;
    void SetPosx(int posx);
    int GetPosx() const;
    void SetContenido(char contenido);
    char GetContenido() const;
    
    void Imprimir(ofstream &arch);
};
#endif /* ESPACIO_H */

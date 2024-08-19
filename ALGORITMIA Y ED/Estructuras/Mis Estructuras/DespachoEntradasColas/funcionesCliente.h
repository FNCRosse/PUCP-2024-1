/* 
 * File:   funcionesCliente.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 11:39 PM
 */

#ifndef FUNCIONESCLIENTE_H
#define FUNCIONESCLIENTE_H

int getHoraLlegada(const struct Cliente & cliente);
int getHoraSalida(const struct Cliente & cliente);
int totalTiempo(const struct Cliente & cliente);
void setHoraSalida(struct Cliente & cliente, int salida);

#endif /* FUNCIONESCLIENTE_H */

